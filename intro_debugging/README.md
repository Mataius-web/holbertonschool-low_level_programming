# C - Intro to Debugging

> Learning to read, understand, and fix buggy C code — a critical skill for every developer.

## Description

This project is part of the **Holberton School** curriculum. It introduces the concept of debugging in C: reading error messages, tracing logic errors, and fixing broken programs. The exercises involve real buggy code that must be analyzed and corrected.

## Learning Objectives

- Understand what debugging is and why it matters
- Read and interpret compiler error and warning messages
- Identify and fix logic errors in existing C programs
- Understand common pitfalls: off-by-one errors, infinite loops, wrong conditions
- Develop a methodical approach to finding bugs

## Requirements

- Ubuntu 20.04 LTS
- gcc (GNU Compiler Collection)
- All files compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the **Betty** style guide

## Files

| File | Description |
|------|-------------|
| `sum_to_n.c` | Fix a function that computes the sum from 0 to `n` |
| `multiplication_table.c` | Fix a program that prints the multiplication table |
| `row_sums.c` | Fix a program that prints the sum of each row of a 2D array |
| `README.md` | Project documentation |

## Debugging Approach

```
1. Read the error message carefully — it tells you the file and line
2. Understand what the code is supposed to do
3. Trace the logic step by step
4. Identify where the actual behavior diverges from the expected
5. Fix and recompile
```

## Common Bug Types Covered

```
- Off-by-one errors     → loop goes one step too far or stops too early
- Wrong operator        → = instead of ==, || instead of &&
- Missing break         → falls through unintended cases
- Infinite loop         → condition never becomes false
- Uninitialized variable → unpredictable behavior
```

## Usage

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 file.c -o output
./output
```

## Author

**Mataius-web** — [GitHub](https://github.com/Mataius-web)

---
*Project completed as part of the Holberton School curriculum.*
