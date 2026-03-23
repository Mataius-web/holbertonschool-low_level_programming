# Valgrind Analysis - Memory Behavior to Diagnostic Mapping

## Scope and Method

Programs analyzed:
- `stack_example`
- `heap_example`
- `aliasing_example`
- `crash_example`

Compilation used:

```bash
gcc -g -O0 -Wall -Wextra -pedantic -std=c99 -o stack_example stack_example.c
gcc -g -O0 -Wall -Wextra -pedantic -std=c99 -o heap_example heap_example.c
gcc -g -O0 -Wall -Wextra -pedantic -std=c99 -o aliasing_example aliasing_example.c
gcc -g -O0 -Wall -Wextra -pedantic -std=c99 -o crash_example crash_example.c
```

Intended Valgrind command (strict settings):

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all ./PROGRAM
```

Environment note:
- `valgrind` is not installed in this execution environment (`command not found`).
- Therefore, this document maps each issue from concrete code behavior and verified runtime behavior, and lists the expected Valgrind classifications that follow from that behavior.

## Program-by-Program Analysis

### 1) stack_example.c

Observed behavior:
- Recursive calls create multiple stack frames.
- Frame-local objects (`local_int`, `local_buf`, `marker`) have automatic storage duration and die at function return.

Memory objects involved:
- Stack object `local_int` in `dump_frame`.
- Stack object `local_buf[16]` in `dump_frame`.
- Stack object `marker` in `walk_stack`.

Lifetime reasoning:
- No pointer escapes to dead stack storage.
- No dereference after frame teardown.
- No heap allocations.

Expected Valgrind result:
- No leaks.
- No invalid read/write.
- No use of uninitialized memory.

Conclusion:
- This program is a control case for valid stack lifetime usage.

---

### 2) heap_example.c

Relevant source behavior:
- `person_new` allocates two heap objects per `Person`:
	- outer object: `Person *p = malloc(sizeof(Person));`
	- owned inner object: `p->name = malloc(len + 1);`
- In `main`, both `alice` and `bob` are created.
- `bob` is fully released: `free(bob->name); free(bob);`
- `alice` is partially released via `person_free_partial(alice);`.
- `person_free_partial` frees only the outer struct (`free(p);`) and never frees `p->name`.

Memory object involved in the warning:
- The heap block backing `alice->name` (the copied string "Alice").

Type of error:
- Memory leak.

Precise misuse:
- Leak due to lost ownership of nested allocation.
- Ownership chain is `alice (stack) -> alice struct (heap) -> alice->name (heap)`.
- After freeing only `alice struct`, the only pointer to `alice->name` is destroyed.
- This is not just "missing free" in abstraction; it is a concrete owner-graph break.

Expected Valgrind classification:
- Leak report for the `alice->name` block.
- Depending on allocator bookkeeping and reachability at exit, this will appear as a leak kind such as "definitely lost" for the string block once no live root points to it.

Why this follows from memory rules:
- Heap object lifetime ends only with `free`.
- Freeing parent container does not recursively free owned pointers in C.

---

### 3) aliasing_example.c

Relevant source behavior:
- `a = make_numbers(n);` allocates one heap array.
- `b = a;` creates an alias (same address, two pointer variables).
- `free(a);` ends lifetime of that heap block.
- Program then reads and writes through `b`:
	- read: `b[2]`
	- write: `b[3] = 1234`

Memory object involved in the warnings:
- The heap array allocated in `make_numbers`.

Type of errors:
- Invalid read (use-after-free).
- Invalid write (use-after-free).

Precise misuse:
- After `free(a)`, both `a` and `b` still contain the old numeric address, but that address no longer names a live object.
- The violation is lifetime-based: dereference of a pointer to deallocated storage.

Expected Valgrind classifications:
- "Invalid read of size 4" at the `printf(... b[2])` access.
- "Invalid write of size 4" at `b[3] = 1234`.

Why this follows from memory rules:
- `free` invalidates the allocation, not just one variable.
- Aliases do not create independent ownership or lifetime.

---

### 4) crash_example.c

Relevant source behavior:
- `n = 0`.
- `allocate_numbers(0)` returns `NULL` by guard (`if (n <= 0) return NULL;`).
- `nums[0] = 42;` dereferences `NULL`.

Memory object involved:
- No heap object exists here (allocation was skipped).
- Access targets address `0x0` (`NULL`), which is invalid user-space memory.

Type of error:
- Invalid write via NULL pointer dereference.

Expected Valgrind classification:
- Invalid write at address `0x0` followed by process termination (SIGSEGV).

Why this follows from memory rules:
- `NULL` has no referent object and no valid lifetime.
- Dereference is immediate UB and typically traps due to page-zero protection.

## Uninitialized Memory Check

No explicit uninitialized-read pattern appears in these sources:
- Stack locals are assigned before use.
- Heap arrays are filled before read.

Expected Valgrind status:
- No "Conditional jump or move depends on uninitialised value(s)" in these four programs under current code.

## Cross-Check Against Task 1 Memory Maps

This analysis matches `memory_maps.md`:
- `heap_example`: nested ownership and leaked inner allocation (`alice->name`).
- `aliasing_example`: alias survives but object lifetime ended after `free(a)`.
- `crash_example`: no allocation created; NULL dereference is deterministic.
- `stack_example`: frame-local data stays within frame lifetime.

## AI Explanation Audit (Required)

### Case where AI explanation was incorrect

Incorrect AI claim:
- "In `heap_example`, there is no leak because `person_free_partial(alice)` frees `alice`."

Why it is incorrect:
- `alice` is a two-layer object graph.
- `person_free_partial` frees only the outer `Person` object.
- The `alice->name` heap block is still allocated and becomes unreachable once the struct is freed.

Correct reasoning:
- This is a leak due to lost ownership of an inner heap allocation, not a fully deallocated object.

## Final Classification Table

| Program | Expected Valgrind Warning Type | Memory Object | Root Cause |
|---|---|---|---|
| `stack_example` | none | stack locals | no lifetime violation |
| `heap_example` | leak (lost block) | `alice->name` string block | outer struct freed without freeing owned inner allocation |
| `aliasing_example` | invalid read + invalid write | freed int array from `make_numbers` | use-after-free via alias `b` |
| `crash_example` | invalid write at `0x0` | no object (NULL access) | dereference of NULL returned for `n <= 0` |

## Pending Execution Step

To convert this expected classification into captured Valgrind evidence, run:

```bash
cd programs
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all ./stack_example
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all ./heap_example
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all ./aliasing_example
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all ./crash_example
```

Then replace "expected" wording above with exact observed report snippets (including access sizes and allocation/free backtraces).
