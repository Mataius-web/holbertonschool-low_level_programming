# C - Secure Data Handling

> Implementing safe session management and in-memory data storage in C.

## Description

This project focuses on secure data handling in C — implementing a session management system backed by an in-memory store. It covers safe memory operations, proper use of dynamic allocation, and clean resource management to avoid leaks and vulnerabilities.

## Learning Objectives

- Implement a session abstraction with create, update, and destroy operations
- Build a linked-list-backed in-memory store with add, get, delete, and destroy operations
- Handle dynamic memory safely to prevent leaks and use-after-free errors
- Organize a C project with separate headers, source files, and a Makefile

## Requirements

- Ubuntu 20.04 LTS
- gcc (GNU Compiler Collection)
- Compiled via the provided `Makefile`
- Code follows the **Betty** style guide

## Data Structures

```c
/* session.h */
typedef struct session_s {
    char *id;
    unsigned int uid;
    unsigned char *data;
    size_t data_len;
} session_t;

/* store.h */
typedef struct node_s {
    session_t *sess;
    struct node_s *next;
} node_t;

typedef struct store_s {
    node_t *head;
} store_t;
```

## Files

| File | Description |
|------|-------------|
| `session.c` | Create, update, and destroy session objects |
| `session.h` | Session structure definition and prototypes |
| `store.c` | In-memory store: init, add, get, delete, and destroy |
| `store.h` | Store structure definition and prototypes |
| `main.c` | Entry point demonstrating session and store usage |
| `Makefile` | Build rules for the project |

## Usage

```bash
make
./secure_data
```

## Author

**Mataius-web** — [GitHub](https://github.com/Mataius-web)

---
*Project completed as part of the Holberton School curriculum.*