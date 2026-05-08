# push_swap

A highly optimized sorting algorithm implementation for the 42 Cursus push_swap project. This program sorts a stack of integers using a limited set of operations, minimizing the total number of instructions required.

## Overview

The push_swap project implements a dual-stack sorting system using linked lists and two primary algorithms: an optimized easy sort for small datasets (≤5 elements) and a binary radix sort for larger datasets. The program validates input, assigns indices to enable efficient sorting, and outputs the sequence of operations required to sort the stack in ascending order. 

## Build Instructions

### Prerequisites
- GCC compiler
- Make utility

### Compilation
```bash
# Build the project
make

# Clean object files
make clean

# Remove all generated files
make fclean

# Rebuild from scratch
make re
```

The build system uses a hierarchical Makefile structure that first compiles the custom libft library, then builds the main push_swap binary with strict compiler flags (-Wall -Wextra -Werror). 

## Usage

### Input Formats
The program accepts integers in two formats:

```bash
# Multiple arguments
./push_swap 2 1 3 6 5 8

# Single quoted string
./push_swap "2 1 3 6 5 8"
```

### Output
The program outputs a sequence of operations, each on a new line:
- `sa`, `sb`, `ss`: Swap operations
- `pa`, `pb`: Push operations  
- `ra`, `rb`, `rr`: Rotate operations
- `rra`, `rrb`, `rrr`: Reverse rotate operations 

## Data Structures

### Stack Node (t_l)
The fundamental data structure is a linked list node with three components: 

```c
typedef struct s_l
{
    int         value;  // The actual integer value
    int         index;  // Rank after pre-sorting (0 to N-1)
    struct s_l  *next;  // Pointer to next node
} t_l;
```

### Stack Representation
- Stack A: Primary stack containing initial unsorted data
- Stack B: Auxiliary stack used during sorting operations

## Algorithms

### Easy Sort (≤5 elements)
Optimized hard-coded logic for small datasets:
- `sort_3`: Handles 3-element stacks with minimal operations
- `sort_4`/`sort_5`: Recursively pushes minimum values to Stack B, sorts remaining, then restores 

### Radix Sort (>5 elements)
Binary radix sort that operates on indices rather than values:
1. Assigns indices (0 to N-1) to all elements based on sorted order
2. Processes bits from least significant to most significant
3. Uses bit manipulation to distribute elements between stacks 

## Input Validation

The program performs comprehensive validation before sorting:

- Checks for non-numeric input
- Detects duplicate integers
- Validates 32-bit signed integer range (-2147483648 to 2147483647)
- Handles both quoted string and multiple argument formats

Invalid input results in `Error\n` output to stderr. 

## Performance Targets

The algorithm aims to minimize operations based on stack size:
- 3 elements: ≤3 operations
- 5 elements: ≤12 operations  
- 100 elements: 700-1500 operations (5 points for ≤700)
- 500 elements: 5500-11500 operations (5 points for ≤5500)

## Project Structure

```
push_swap/
├── headers/
│   ├── push_swap.h      # Main project headers
│   └── libft.h          # Custom library headers
├── src/
│   ├── push_swap.c      # Main program entry
│   ├── push_validation.c # Input validation
│   ├── push_easy.c      # Small stack sorting
│   ├── push_radix.c     # Large stack sorting
│   ├── push_movements.c # Stack operations
│   └── push_*.c         # Utility functions
├── libft/
│   ├── src/             # Custom library source
│   └── Makefile         # Library build system
└── Makefile             # Main project build system
```

## Dependencies

- Custom libft library providing standard C function implementations
- Standard C libraries: stdio.h, unistd.h, stdlib.h, fcntl.h 

## Notes

The current README.md contains only external reference links and lacks project documentation. This implementation follows 42 Cursus norms with strict error handling, memory management, and coding standards. The radix sort implementation uses binary operations on indices for optimal performance regardless of actual integer values or ranges.
