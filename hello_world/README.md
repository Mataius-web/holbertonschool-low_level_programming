# C - Hello, World

> First steps in C programming — compilation, the C standard library, and printing to stdout.

## Description

This project introduces the basics of C programming as part of the **Holberton School**. It covers the compilation process using `gcc`, the use of standard library functions, and writing the first C programs that interact with the user via standard output.

## Learning Objectives

- Understand why C is a powerful and widely-used language
- Know the roles of key figures like Dennis Ritchie, Brian Kernighan, and Linus Torvalds
- Understand the compilation process: preprocessing, compiling, assembling, and linking
- Use `gcc` with flags: `-Wall`, `-Werror`, `-Wextra`, `-pedantic`, `-std=gnu89`
- Write and use the `_putchar` function
- Understand the difference between `printf` and `puts`

## Requirements

- Ubuntu 20.04 LTS
- gcc (GNU Compiler Collection)
- All files compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the **Betty** style guide

## Files

| File | Description |
|------|-------------|
| `0-preprocessor` | Run a C file through the preprocessor |
| `1-compiler` | Compile a C file without linking |
| `2-assembler` | Generate assembly code from a C file |
| `3-name` | Compile a C file and create an executable named `cisfun` |
| `4-puts.c` | Print a string using `puts` |
| `5-printf.c` | Print a string using `printf` |
| `6-size.c` | Print the sizes of various data types |
| `_putchar.c` | Custom implementation of `putchar` |

## Usage

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 file.c -o output
./output
```

## Author

**Mataius-web** — [GitHub](https://github.com/Mataius-web)

---
*Project completed as part of the Holberton School.*
