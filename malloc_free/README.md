# C - Malloc & Free

> Dynamic memory allocation in C using `malloc` and `free`.

## Description

This project is part of the **Holberton School** curriculum. It introduces dynamic memory allocation with `malloc` and `free` — allocating memory at runtime on the heap, working with dynamically sized arrays and strings, and preventing memory leaks by freeing all allocated memory.

## Learning Objectives

- Understand the difference between automatic and dynamic memory allocation
- Use `malloc` and `free` correctly
- Know when to use `malloc` vs stack allocation
- Avoid memory leaks and double frees
- Use `valgrind` to check for memory errors

## Requirements

- Ubuntu 20.04 LTS
- gcc (GNU Compiler Collection)
- All files compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the **Betty** style guide
- No global variables
- No more than 5 functions per file

## Files

| File | Description |
|------|-------------|
| `0-create_array.c` | Create an array of chars and initialize it with a specific char |
| `1-strdup.c` | Return a pointer to a new string which is a duplicate of a given string |
| `2-str_concat.c` | Concatenate two strings into a newly allocated string |
| `3-alloc_grid.c` | Return a pointer to a 2D array of integers |
| `4-free_grid.c` | Free a 2D grid previously created by `alloc_grid` |
| `main.h` | Header file with function prototypes |

## Usage

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 file.c -o output
./output
```

## Author

**Mataius-web** — [GitHub](https://github.com/Mataius-web)

---
*Project completed as part of the Holberton School curriculum.*