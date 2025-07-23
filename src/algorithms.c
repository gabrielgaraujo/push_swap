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

	if (stack_a->size != 4)
		return;
	
	// Find position of minimum value and move it to top
	min_pos = get_min_position(stack_a);
	move_index_to_top(stack_a, min_pos, 'a');
	
	// Push minimum to stack B
	pb(stack_a, stack_b);
	
	// Sort remaining 3 elements in stack A
	if (!is_sorted(stack_a))
		sort_three(stack_a);
	
	// Push minimum back to stack A (it will be at the top, which is correct)
	pa(stack_a, stack_b);
}

/* General sorting algorithm for 5+ elements (placeholder) */
void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	// TODO: Implement sorting algorithm for large stacks
}
