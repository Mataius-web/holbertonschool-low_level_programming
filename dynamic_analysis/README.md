# C - Dynamic Analysis & GDB

> Using dynamic analysis tools and GDB to inspect and debug C programs at runtime.

## Description

This project is part of the **Holberton School** curriculum. It introduces dynamic analysis techniques: using GDB (GNU Debugger) to step through programs, inspect memory and variables at runtime, set breakpoints, and understand program execution flow. It also covers using GDB with Visual Studio Code.

## Learning Objectives

- Launch and control a program with GDB
- Set and remove breakpoints
- Step through code instruction by instruction
- Inspect variable values and memory at runtime
- Use GDB within Visual Studio Code for a graphical debugging experience

## Requirements

- Ubuntu 20.04 LTS
- gcc (GNU Compiler Collection)
- GDB (GNU Debugger)

## Files

| File | Description |
|------|-------------|
| `gdb_fundamentals.txt` | Notes and exercises on GDB fundamentals (breakpoints, stepping, inspection) |
| `gdb_vsc.txt` | Notes on using GDB integrated into Visual Studio Code |

## Key GDB Commands

```
gdb ./program          - Start GDB on a compiled binary
break main             - Set a breakpoint at main
run                    - Run the program
next (n)               - Step over to the next line
step (s)               - Step into a function call
print var              - Print the value of a variable
info locals            - Show all local variables
backtrace (bt)         - Show the call stack
continue (c)           - Continue execution until next breakpoint
quit (q)               - Exit GDB
```

## Usage

```bash
gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 file.c -o output
gdb ./output
```

## Author

**Mataius-web** — [GitHub](https://github.com/Mataius-web)

---
*Project completed as part of the Holberton School curriculum.*