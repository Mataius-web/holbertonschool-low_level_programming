# C - More Malloc & Free

> Advanced dynamic memory allocation in C: safe allocation, `calloc`, and array ranges.

## Description

This project is part of the **Holberton School** curriculum. It builds on the foundations of `malloc` and `free`, introducing checked allocation that exits on failure, string concatenation with a size limit, `calloc` for zero-initialized memory, and creating arrays of consecutive integers.

## Learning Objectives

- Use `malloc` with proper error handling (`exit` on failure)
- Implement `_calloc` from scratch using `malloc`
- Concatenate strings with a maximum size using dynamic allocation
- Build a range array of consecutive integers
- Understand `EXIT_FAILURE` and `stdlib.h` utilities

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
| `0-malloc_checked.c` | Allocate memory using `malloc`; exit with `98` if it fails |
| `1-string_nconcat.c` | Concatenate two strings, using at most `n` bytes from the second |
| `2-calloc.c` | Allocate memory for an array, initialized to zero (`_calloc`) |
| `3-array_range.c` | Create an array of integers from `min` to `max` |
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