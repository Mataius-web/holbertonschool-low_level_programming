# Memory Maps - C Programs Analysis

## Program 1: stack_example.c

**What happens:** Recursive calls create stack frames that grow downward.

**Key observation:** Each frame takes exactly 0x30 (48 bytes) of stack:
```
Depth 0 marker: 0x7fffc0a5e754
Depth 1 marker: 0x7fffc0a5e724  (-0x30)
Depth 2 marker: 0x7fffc0a5e6f4  (-0x30)
Depth 3 marker: 0x7fffc0a5e6c4  (-0x30)
```

**Variable lifetimes:** Each frame's variables destroyed when function returns. Stack space is immediately reused.

---

## Program 2: heap_example.c

**What happens:** Two Person objects allocated on heap. Each Person "owns" a string pointer.

**Memory layout:**
```
alice (stack) → alice_struct (heap, 24 bytes) → alice->name (heap, 7 bytes, "Alice\0")
bob (stack)   → bob_struct (heap, 24 bytes)   → bob->name (heap, 5 bytes, "Bob\0")
```

**The leak:** `person_free_partial()` only frees the struct, NOT the string:
```c
free(bob->name);      // Correct: frees both layers
free(bob);
person_free_partial(alice);  // WRONG: only frees struct, leaks 7-byte string
```

**Result:** Alice's string (0x7ffff37ed4d0) is lost forever when main() exits.

---

## Program 3: aliasing_example.c

**What happens:** Two pointers point to same heap memory. Then one is freed, but both still hold the address.

**Aliasing:**
```c
int *a = make_numbers(5);   // a = 0x7fffbe1ec4b0
int *b = a;                  // b = 0x7fffbe1ec4b0 (SAME address)
```

**After `free(a)`:**
- `a` still = 0x7fffbe1ec4b0 (pointer value unchanged!)
- `b` still = 0x7fffbe1ec4b0 (pointer value unchanged!)
- Memory now freed, but program reads/writes through `b` anyway (undefined behavior)

**Why no immediate crash:** OS doesn't protect freed heap (only allocator does). Compare to NULL (page 0 protected by OS).

---

## Program 4: crash_example.c

**What happens:** `allocate_numbers(0)` returns NULL. Main doesn't check. Crash guaranteed.

```c
int n = 0;
int *nums = allocate_numbers(0);  // returns NULL (0x0)
nums[0] = 42;                      // Write to address 0x0 → Page fault → SIGSEGV
```

**Why 100% deterministic:**
- Page 0 protected by OS always
- CPU raises exception, kernel sends SIGSEGV
- Exit code 139 = 128 + 11 (SIGSEGV signal number)

---

## AI Explanation Corrections

### Issue 1: free() Behavior (aliasing_example.c)

**What AI said:** "free() makes pointer b a dangling pointer"

**What was missing:**
- AI didn't explain that **free() doesn't change pointer values**
- After `free(a)`, both a and b still hold `0x7fffbe1ec4b0`
- There's NO OS protection on freed heap (unlike NULL → page 0)
- Only the allocator tracks ownership; no hardware protection

**Fix:** Clarified that freed heap memory can still be read/written (undefined behavior), unlike NULL which is protected by OS. Normal runs don't crash because memory isn't immediately reused.

### Issue 2: Frame Size (stack_example.c)

**What AI said:** "Every recursion adds exactly 0x30 bytes to stack"

**What was missing:**
- This 0x30 is empirical from THIS system with THIS compiler
- Frame size depends on compiler flags, CPU architecture, ABI alignment
- Not universal; different systems could have different frame sizes

**Fix:** Made clear this is observed pattern on x86-64 Linux, not a law. Key insight: recursion creates *consistent* frame size (whatever it is for your system).

### Issue 3: Leak Timeline (heap_example.c)

**What AI said:** "person_free_partial frees nothing, memory leak at T4"

**What was missing:**
- Leak condition exists when person_free_partial returns without freeing string
- But leak becomes *irrecoverable* when main() returns (alice variable destroyed)
- At T4: leaking but potentially recoverable; at T5: definitely lost

**Fix:** Separated two stages: "leaking from here" vs "definitely lost from here".

---

## Summary

**Stack:** Frames reused after return; pointers must stay within frame lifetime.

**Heap:** Objects needing nested freeing; free only outer layer = leak.

**Aliasing:** Multiple pointers to same memory; free() changes allocator state, not pointer values.

**NULL:** Address 0x0 protected by OS always; crash 100% guaranteed.
