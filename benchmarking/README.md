# C - Benchmarking

> Measuring and comparing the performance of C programs — understanding efficiency at the hardware level.

## Description

This project is part of the **Holberton School** curriculum. It explores benchmarking techniques in C: how to measure execution time, analyze performance metrics, compare algorithmic approaches, and reason about computational efficiency and energy consumption.

## Learning Objectives

- Understand what benchmarking is and why it matters in systems programming
- Measure execution time and CPU usage of C programs
- Compare the performance of different algorithmic approaches
- Understand the relationship between code efficiency and energy consumption
- Read and interpret performance metrics

## Requirements

- Ubuntu 20.04 LTS
- gcc (GNU Compiler Collection)
- All files compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the **Betty** style guide

## Files

| File | Description |
|------|-------------|
| `baseline_loop.c` | Baseline C program used as a reference for benchmarking |
| `baseline_loop-metrics.md` | Performance metrics collected from the baseline loop |
| `instrumentation_lab.c` | C program with instrumentation to measure execution details |
| `comparison_algorithms-metrics.md` | Metrics comparing different algorithmic approaches |
| `green_efficiency_analysis.md` | Analysis of energy efficiency and computational cost |
| `a.out` | Compiled binary output |

## Key Concepts

**Execution time measurement:**
```c
#include <time.h>

clock_t start = clock();
/* ... code to benchmark ... */
clock_t end = clock();
double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
```

**What affects performance:**
```
- Algorithm complexity  (O(n), O(n²), O(log n)...)
- Memory access patterns (cache hits vs misses)
- Compiler optimizations (-O0, -O1, -O2, -O3)
- CPU branch prediction
```

## Usage

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 baseline_loop.c -o baseline
./baseline

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 instrumentation_lab.c -o instrumentation
./instrumentation
```

## Author

**Mataius-web** — [GitHub](https://github.com/Mataius-web)

---
*Project completed as part of the Holberton School curriculum.*
