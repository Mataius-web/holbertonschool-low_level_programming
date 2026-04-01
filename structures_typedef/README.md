# C - Structures & Typedef

> Grouping related data with structs and creating type aliases with typedef in C.

## Description

This project is part of the **Holberton School** curriculum. It covers `struct` and `typedef` in C — how to define custom data types that bundle multiple fields together, and how to alias them for cleaner code. The exercises use a `dog` structure with `name`, `age`, and `owner` fields.

## Learning Objectives

- Understand what a structure is and how to define one
- Use `typedef` to create type aliases for structs
- Initialize, print, create, and free struct instances
- Understand the difference between stack-allocated and heap-allocated structs

## Requirements

- Ubuntu 20.04 LTS
- gcc (GNU Compiler Collection)
- All files compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the **Betty** style guide
- No global variables
- No more than 5 functions per file

## Data Structure

```c
typedef struct dog
{
    char *name;
    float age;
    char *owner;
} dog_t;
```

## Files

| File | Description |
|------|-------------|
| `1-init_dog.c` | Initialize a variable of type `struct dog` |
| `2-print_dog.c` | Print a `struct dog` |
| `4-new_dog.c` | Create a new `dog_t` on the heap with duplicated strings |
| `5-free_dog.c` | Free all memory allocated by `new_dog` |
| `dog.h` | Header file with struct definition and prototypes |

## Usage

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 file.c -o output
./output
```

## Author

**Mataius-web** — [GitHub](https://github.com/Mataius-web)

---
*Project completed as part of the Holberton School curriculum.*