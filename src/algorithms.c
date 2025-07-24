#include "../includes/push_swap.h"

/* Check if stack is sorted in ascending order (top to bottom) */
int	is_sorted(t_stack *stack_a)
{
	int	i;

	if (stack_a->size <= 1)
		return (1);
	
	// Check from top to bottom (data[0] to data[size-1])
	i = 0;
	while (i < stack_a->size - 1)
	{
		if (stack_a->data[i] > stack_a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/* Sort 2 elements: if top > bottom, swap them */
void	sort_two(t_stack *stack_a)
{
	if (stack_a->size != 2)
		return;
	
	// We know it's not sorted (checked in main), so just swap
	sa(stack_a);
}

/* Sort 3 elements using optimal operations */
void	sort_three(t_stack *stack_a)
{
	int	top;
	int	mid;
	int	bot;

	if (stack_a->size != 3)
		return;
	
	// Get the three elements: data[0] is top, data[2] is bottom
	top = stack_a->data[0];  // Top of stack (data[0])
	mid = stack_a->data[1];  // Middle of stack (data[1])
	bot = stack_a->data[2];  // Bottom of stack (data[2])
	
	// Case analysis for 3 elements (we know it's not sorted)
	if (top < mid && mid > bot && top < bot)
	{
		// Pattern: top < bot < mid (e.g., 1 3 2)
		sa(stack_a);
		ra(stack_a);
	}
	else if (top > mid && mid < bot && top < bot)
	{
		// Pattern: mid < top < bot (e.g., 2 1 3)
		sa(stack_a);
	}
	else if (top < mid && mid > bot && top > bot)
	{
		// Pattern: bot < top < mid (e.g., 2 3 1)
		rra(stack_a);
	}
	else if (top > mid && mid < bot && top > bot)
	{
		// Pattern: mid < bot < top (e.g., 3 1 2)
		ra(stack_a);
	}
	else if (top > mid && mid > bot)
	{
		// Pattern: bot < mid < top (e.g., 3 2 1) - reverse sorted
		sa(stack_a);
		rra(stack_a);
	}
}

/* Sort 4 elements using optimal strategy */
void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;
	int max_pos;

	if (stack_a->size != 4) return;
	
	min_pos = get_min_position(stack_a);
	max_pos = get_max_position(stack_a);
	
	// Handle special cases
	if (min_pos == 1 && max_pos == 3 && stack_a->data[0] < stack_a->data[2])
	{
		// Pattern [b, a, c, d]
		sa(stack_a);
	} else if (min_pos == 3 && max_pos == 2 && stack_a->data[0] < stack_a->data[1])
	{
		// Pattern [b, c, d, a]
		rra(stack_a);
	} else if (min_pos == 1 && max_pos == 0 && stack_a->data[2] < stack_a->data[3]) 
	{
		// Pattern [d, a, b, c]
		ra(stack_a);
	} else if (min_pos == 2 && max_pos == 1 && stack_a->data[3] < stack_a->data[0])
	{
		// Pattern [c, d, a, b]
		ra(stack_a);
		ra(stack_a);
	} else {
		// General case:
		move_index_to_top(stack_a, min_pos, 'a');
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}

/* General sorting algorithm for 5+ elements */
void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 4)
        return;
    
    // Phase 1: Split into two roughly equal halves
    split_stack_optimally(stack_a, stack_b);
    
    // Phase 2: Sort both stacks simultaneously using dual operations
    dual_bubble_sort(stack_a, stack_b);
    
    // Phase 3: Merge sorted stacks back together
    merge_sorted_stacks(stack_a, stack_b);
}

/* Split stack A into two halves - smaller values to B, larger to A */
void	split_stack_optimally(t_stack *stack_a, t_stack *stack_b)
{
    int	median;
    int	pushed_count;
    int	target_size;
    int	rotations;
    
    median = find_median(stack_a);
    target_size = stack_a->size / 2;
    pushed_count = 0;
    rotations = 0;
    
    while (pushed_count < target_size && rotations < stack_a->size * 2)
    {
        if (stack_a->data[0] <= median)
        {
            pb(stack_a, stack_b);
            pushed_count++;
            rotations = 0;  // Reset rotation counter
        }
        else
        {
            ra(stack_a);
            rotations++;
        }
    }
}
