# push_swap

A highly optimized sorting algorithm implementation for the 42 Cursus push_swap project. This program sorts a stack of integers using a limited set of operations, minimizing the total number of instructions required.

## Overview

The push_swap project implements a dual-stack sorting system using linked lists and two primary algorithms: an optimized easy sort for small datasets (≤5 elements) and a binary radix sort for larger datasets. The program validates input, assigns indices to enable efficient sorting, and outputs the sequence of operations required to sort the stack in ascending order. [1](#0-0) 

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

The build system uses a hierarchical Makefile structure that first compiles the custom libft library, then builds the main push_swap binary with strict compiler flags (-Wall -Wextra -Werror). [2](#0-1) 

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
- `rra`, `rrb`, `rrr`: Reverse rotate operations [3](#0-2) 

## Data Structures

### Stack Node (t_l)
The fundamental data structure is a linked list node with three components: [4](#0-3) 

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
- `sort_4`/`sort_5`: Recursively pushes minimum values to Stack B, sorts remaining, then restores [5](#0-4) 

### Radix Sort (>5 elements)
Binary radix sort that operates on indices rather than values:
1. Assigns indices (0 to N-1) to all elements based on sorted order
2. Processes bits from least significant to most significant
3. Uses bit manipulation to distribute elements between stacks [6](#0-5) 

## Input Validation

The program performs comprehensive validation before sorting: [7](#0-6) 

- Checks for non-numeric input
- Detects duplicate integers
- Validates 32-bit signed integer range (-2147483648 to 2147483647)
- Handles both quoted string and multiple argument formats

Invalid input results in `Error\n` output to stderr. [8](#0-7) 

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
- Standard C libraries: stdio.h, unistd.h, stdlib.h, fcntl.h [9](#0-8) 

## Notes

The current README.md contains only external reference links and lacks project documentation. This implementation follows 42 Cursus norms with strict error handling, memory management, and coding standards. The radix sort implementation uses binary operations on indices for optimal performance regardless of actual integer values or ranges.

Wiki pages you might want to explore:
- [Getting Started: Build and Usage (stick0789/pushSwap)](/wiki/stick0789/pushSwap#1.1)
- [Glossary (stick0789/pushSwap)](/wiki/stick0789/pushSwap#6)

### Citations

**File:** src/push_swap.c (L14-20)
```c
static void	sort(t_l **stack_a, t_l **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		easy_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
```

**File:** src/push_swap.c (L46-48)
```c
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
```

**File:** Makefile (L32-41)
```text
all	:	makelib $(OBJ_PATH) $(NAME)

makelib	:	
		$(MAKE) --silent -C libft --no-print-directory

$(OBJ_PATH):
		mkdir -p $(OBJ_PATH)

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
```

**File:** headers/push_swap.h (L15-19)
```text
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
```

**File:** headers/push_swap.h (L21-26)
```text
typedef struct s_l
{
	int			value;
	int			index;
	struct s_l	*next;
}	t_l;
```

**File:** headers/push_swap.h (L47-61)
```text
int		swap(t_l **stack);
int		push(t_l **stack_to, t_l **stack_from);
int		rotate(t_l **stack);
int		reverse_rotate(t_l **stack);
int		sa(t_l **stack_a);
int		sb(t_l **stack_b);
int		ss(t_l **stack_a, t_l **stack_b);
int		pa(t_l **stack_a, t_l **stack_b);
int		pb(t_l **stack_a, t_l **stack_b);
int		ra(t_l **stack_a);
int		rb(t_l **stack_b);
int		rr(t_l **stack_a, t_l **stack_b);
int		rra(t_l **stack_a);
int		rrb(t_l **stack_b);
int		rrr(t_l **stack_a, t_l **stack_b);
```

**File:** src/push_easy.c (L42-91)
```c
static void	sort_4(t_l **stack_a, t_l **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min_val(stack_a, -1));
	if (is_sorted(stack_a))
		return ;
	if (distance == 1)
		ra(stack_a);
	if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_5(t_l **stack_a, t_l **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min_val(stack_a, -1));
	if (is_sorted(stack_a))
		return ;
	if (distance == 1)
		ra(stack_a);
	if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
```

**File:** src/push_radix.c (L34-61)
```c
void	radix_sort(t_l **stack_a, t_l **stack_b)
{
	t_l	*head_a;
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
```

**File:** src/push_validation.c (L79-96)
```c
int	input_validation(int argc, char *argv[])
{
	char	**args;
	int		i;
	int		result;

	if (*(argv[1]) == '\0')
		return (0);
	args = initialize_args(argc, argv, &i);
	if (args[0] == NULL)
		return (0);
	if (!args)
		return (0);
	result = validate_args(args, i);
	if (argc == 2)
		free_split(args);
	return (result);
}
```
