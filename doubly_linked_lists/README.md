# C - Doubly Linked Lists

> Implementing and manipulating doubly linked lists in C.

## Description

This project is part of the **Holberton School** curriculum. It covers doubly linked lists — data structures where each node holds a pointer to both the next and the previous node — enabling efficient traversal in both directions.

## Learning Objectives

- Understand what a doubly linked list is and when to use one
- Build and traverse a doubly linked list
- Insert and delete nodes at any position
- Compute the sum of all node values
- Free allocated memory properly

## Requirements

- Ubuntu 20.04 LTS
- gcc (GNU Compiler Collection)
- All files compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the **Betty** style guide
- No global variables
- No more than 5 functions per file

## Data Structure

```c
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
```

## Files

| File | Description |
|------|-------------|
| `0-print_dlistint.c` | Print all elements of a doubly linked list |
| `1-dlistint_len.c` | Return the number of elements in a doubly linked list |
| `2-add_dnodeint.c` | Add a new node at the beginning of a doubly linked list |
| `3-add_dnodeint_end.c` | Add a new node at the end of a doubly linked list |
| `4-free_dlistint.c` | Free a doubly linked list |
| `5-get_dnodeint.c` | Return the nth node of a doubly linked list |
| `6-sum_dlistint.c` | Return the sum of all data in a doubly linked list |
| `7-insert_dnodeint.c` | Insert a new node at a given position |
| `8-delete_dnodeint.c` | Delete a node at a given index |
| `lists.h` | Header file with structure definition and prototypes |

## Usage

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 file.c -o output
./output
```

## Author

**Mataius-web** — [GitHub](https://github.com/Mataius-web)

---
*Project completed as part of the Holberton School curriculum.*