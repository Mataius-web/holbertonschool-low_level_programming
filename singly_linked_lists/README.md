# C - Singly Linked Lists

> Building and manipulating singly linked lists in C.

## Description

This project is part of the **Holberton School** curriculum. It introduces singly linked lists — dynamic data structures where each node stores a value and a pointer to the next node. The exercises cover printing, counting, adding nodes, and freeing the list.

## Learning Objectives

- Understand when to use a linked list versus an array
- Build a singly linked list from scratch
- Add nodes at the beginning and at the end of a list
- Traverse and print the elements of a list
- Free all memory used by a linked list

## Requirements

- Ubuntu 20.04 LTS
- gcc (GNU Compiler Collection)
- All files compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the **Betty** style guide
- No global variables
- No more than 5 functions per file

## Data Structure

```c
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

## Files

| File | Description |
|------|-------------|
| `0-print_list.c` | Print all elements of a singly linked list |
| `1-list_len.c` | Return the number of elements in a singly linked list |
| `2-add_node.c` | Add a new node at the beginning of a singly linked list |
| `3-add_node_end.c` | Add a new node at the end of a singly linked list |
| `4-free_list.c` | Free a singly linked list |
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