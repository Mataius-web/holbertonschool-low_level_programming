# C - More Functions, More Nested Loops

> Expanding the C toolbox with more custom functions, character checks, and visual pattern generation.

## Description

This project is part of the **Holberton School** curriculum. It builds on the foundations of functions and nested loops, introducing more complex logic such as character classification, arithmetic operations, FizzBuzz, and printing visual patterns using nested loops.

## Learning Objectives

- Write and use custom functions that mimic standard library behavior
- Use nested loops to generate structured visual output
- Understand how to check character types without using standard library functions
- Apply the Betty coding style consistently
- Organize prototypes cleanly in a header file

## Requirements

- Ubuntu 20.04 LTS
- gcc (GNU Compiler Collection)
- All files compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the **Betty** style guide
- No global variables
- No more than 5 functions per file
- Only `_putchar` allowed (no `printf`, `puts`)

## Files

| File | Description |
|------|-------------|
| `0-isupper.c` | Check for uppercase character |
| `1-isdigit.c` | Check for a digit (`0` through `9`) |
| `2-mul.c` | Multiply two integers |
| `3-print_numbers.c` | Print the numbers `0` to `9` |
| `4-print_most_numbers.c` | Print numbers `0` to `9` except `2` and `4` |
| `5-more_numbers.c` | Print numbers `0` to `14`, ten times |
| `6-print_line.c` | Draw a straight line using `_putchar` |
| `7-print_diagonal.c` | Draw a diagonal line using `_putchar` |
| `8-print_square.c` | Print a square using `#` |
| `9-fizz_buzz.c` | Print numbers 1 to 100 with FizzBuzz rules |
| `10-print_triangle.c` | Print a triangle using `#` |
| `main.h` | Header file with all function prototypes |

## Usage

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 file.c _putchar.c -o output
./output
```

## Example — print_square(4)

```
####
####
####
####
```

## Example — FizzBuzz (1 to 15)

```
1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz
```

## Author

**Mataius-web** — [GitHub](https://github.com/Mataius-web)

---
*Project completed as part of the Holberton School curriculum.*
