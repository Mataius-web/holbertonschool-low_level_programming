# C - Variadic Functions

> Writing functions that accept a variable number of arguments in C using `stdarg.h`.

## Description

This project is part of the **Holberton School** curriculum. It covers variadic functions in C — functions that accept a variable number of arguments, like `printf`. Using the macros `va_start`, `va_arg`, `va_end`, and `va_copy` from `<stdarg.h>`, these functions can process an arbitrary number of values at runtime.

## Learning Objectives

- Understand what variadic functions are and how to use them
- Use `va_start`, `va_arg`, `va_end` from `<stdarg.h>`
- Know why and how to use the `const` type qualifier
- Implement functions that sum, print numbers, print strings, and print mixed types

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
| `0-sum_them_all.c` | Return the sum of all parameters |
| `1-print_numbers.c` | Print numbers separated by a given string |
| `2-print_strings.c` | Print strings separated by a given string |
| `3-print_all.c` | Print anything based on a format string (`c`, `i`, `f`, `s`) |
| `variadic_functions.h` | Header file with function prototypes |

## Usage

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 file.c -o output
./output
```

## Author

**Mataius-web** — [GitHub](https://github.com/Mataius-web)

---
*Project completed as part of the Holberton School curriculum.*