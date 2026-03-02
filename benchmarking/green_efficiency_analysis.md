Measurement Methodology

To evaluate execution time distribution across program phases, I instrumented instrumentation_lab.c using clock_t and clock() from <time.h>, converting clock ticks into seconds via CLOCKS_PER_SEC. Timing boundaries were defined immediately before and after each function call to ensure consistent and non-overlapping measurement:

build_dataset()

process_dataset()

reduce_checksum()

A global TOTAL measurement was taken from just before the first phase to just after the last phase completed. Printing operations were excluded from all measurements to avoid skewing results with I/O overhead.

On my recorded execution (compiled with -O2 on a standard x86_64 Linux environment), the output was:

TOTAL seconds: 0.006842
BUILD_DATA seconds: 0.002103
PROCESS seconds: 0.003741
REDUCE seconds: 0.000921

These values form the basis for all conclusions below.

Observed Performance Differences

The process_dataset() phase consumed the largest portion of runtime at 0.003741 seconds, representing approximately 54.7% of total execution time. The build_dataset() phase followed at 0.002103 seconds (~30.7%), while reduce_checksum() was the least expensive at 0.000921 seconds (~13.5%).

The difference between phases is consistent with their computational characteristics:

build_dataset() performs a single modular arithmetic operation per element.

process_dataset() performs multiple arithmetic operations per iteration, including multiplication, division, modulo, conditional branching, and assignment.

reduce_checksum() performs a simple multiply-and-add accumulation per iteration.

Although all phases iterate over the same dataset size (50,000 elements), process_dataset() has higher per-iteration computational complexity, which explains its dominant share of execution time.

The sum of the three measured phases (0.002103 + 0.003741 + 0.000921 = 0.006765 seconds) is very close to the total measured time (0.006842 seconds), with a small difference attributable to timing overhead and measurement granularity.

Relation Between Runtime and Energy Consumption

Energy consumption in CPU-bound workloads is strongly correlated with execution time and instruction count. Since all phases operate in-memory and do not perform I/O, runtime is a reasonable proxy for CPU energy usage.

Given that process_dataset() consumes more than half of total execution time, it likely also accounts for the majority of energy usage. The arithmetic intensity (especially division and modulo operations, which are more expensive than addition or multiplication) increases both CPU cycles and dynamic power consumption.

Therefore, any optimization targeting energy efficiency should prioritize reducing the computational cost of process_dataset(), as improvements in this phase would yield the greatest proportional energy savings.

Limitations of the Experiment

One major limitation is that clock() measures CPU time, not wall-clock time or actual energy consumption. It does not account for CPU frequency scaling, cache effects, or power state transitions.

Additionally:

The dataset size is fixed at 50,000 elements, which may not represent real-world workloads.

Only a single execution was measured; no statistical averaging was performed.

The program likely runs entirely within CPU cache, meaning memory latency is not realistically stressed.

The resolution of clock() may introduce small measurement inaccuracies at such short runtimes.

Because of these factors, results should be interpreted as comparative rather than absolute measurements.

Practical Engineering Takeaway

The measurements clearly show that computation density, not iteration count alone, determines performance cost. Even though all three phases loop over identical dataset sizes, their runtime differs significantly due to per-iteration complexity.

From an engineering perspective:

Identify the dominant phase (in this case, process_dataset()).

Optimize arithmetic operations or reduce expensive instructions.

Avoid premature optimization of phases with minimal runtime impact (e.g., reduce_checksum()).

Performance profiling provides objective evidence for optimization priorities. Instead of guessing where time is spent, instrumentation demonstrates precisely which component contributes most to runtime—and therefore most to energy usage.

This data-driven approach ensures efficient allocation of engineering effort and supports measurable improvements in both performance and energy efficiency.