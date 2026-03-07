# C - argc, argv

> Understanding how to use command-line arguments in C programs.

## Description

This project is part of the **Holberton School** curriculum. It covers how to use `argc` and `argv` to pass arguments to a C program from the command line, and how to process those arguments (counting, printing, converting, and validating them).

## Learning Objectives

- Understand how to use arguments passed to a program
- Know the prototypes of `main` with `argc` and `argv`
- Use `argc` and `argv` to count and iterate over command-line arguments
- Convert string arguments to integers using `atoi`

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
| `0-whatsmyname.c` | Print the name of the program |
| `1-args.c` | Print the number of arguments passed to the program |
| `2-args.c` | Print all arguments received by the program |
| `3-mul.c` | Multiply two numbers passed as command-line arguments |
| `4-add.c` | Add positive numbers passed as command-line arguments |

## Usage

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 file.c -o output
./output [arguments]
```

## Author

**Mataius-web** — [GitHub](https://github.com/Mataius-web)

---
*Project completed as part of the Holberton School curriculum.*