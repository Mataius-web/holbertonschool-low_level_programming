# C - Function Pointers

> Using function pointers to write flexible, callback-driven C programs.

## Description

This project is part of the **Holberton School** curriculum. It covers function pointers in C — variables that store the address of a function and allow functions to be passed as arguments, enabling patterns like callbacks, dispatch tables, and generic algorithms.

## Learning Objectives

- Understand what a function pointer is and how to declare one
- Use function pointers as parameters to other functions
- Build a dispatch table (array of function pointers) for a simple calculator
- Understand where function pointers are stored in memory

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
| `0-print_name.c` | Print a name using a function pointer |
| `1-array_iterator.c` | Execute a function on each element of an array |
| `2-int_index.c` | Return the index of the first element for which a function returns non-zero |
| `3-calc.h` | Header for the calculator: defines `op_t` struct and prototypes |
| `3-get_op_func.c` | Return the right arithmetic function for a given operator |
| `3-op_functions.c` | Arithmetic functions: add, sub, mul, div, mod |
| `3-main.c` | Entry point for the calculator program |
| `function_pointers.h` | Header file with prototypes |

## Usage

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-main.c 3-get_op_func.c 3-op_functions.c -o calc
./calc 10 + 5
```

## Author

**Mataius-web** — [GitHub](https://github.com/Mataius-web)

---
*Project completed as part of the Holberton School curriculum.*