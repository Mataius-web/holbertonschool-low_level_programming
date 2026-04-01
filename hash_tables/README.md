# C - Hash Tables

> Implementing hash tables in C for fast key-value storage and retrieval.

## Description

This project is part of the **Holberton School** curriculum. It covers hash tables — data structures that map keys to values using a hash function. The implementation includes creating tables, handling collisions with chaining, and performing get, set, print, and delete operations.

## Learning Objectives

- Understand what a hash function is and what makes a good one
- Know how to handle collisions using chaining (linked lists)
- Implement `hash_table_create`, `hash_table_set`, `hash_table_get`, `hash_table_print`, and `hash_table_delete`
- Understand the advantages and limitations of hash tables

## Requirements

- Ubuntu 20.04 LTS
- gcc (GNU Compiler Collection)
- All files compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the **Betty** style guide
- No global variables
- No more than 5 functions per file

## Data Structure

```c
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
```

## Files

| File | Description |
|------|-------------|
| `0-hash_table_create.c` | Create a hash table |
| `1-djb2.c` | Implement the djb2 hash function |
| `2-key_index.c` | Return the index for a given key |
| `3-hash_table_set.c` | Add or update an element in the hash table |
| `4-hash_table_get.c` | Retrieve the value associated with a key |
| `5-hash_table_print.c` | Print the hash table |
| `6-hash_table_delete.c` | Delete the hash table |
| `hash_tables.h` | Header file with structure definitions and prototypes |

## Usage

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 file.c -o output
./output
```

## Author

**Mataius-web** — [GitHub](https://github.com/Mataius-web)

---
*Project completed as part of the Holberton School curriculum.*