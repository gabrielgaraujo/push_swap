#include "../includes/push_swap.h"

/* Check if stack is sorted in ascending order (top to bottom) */
int	is_sorted(t_stack *stack_a)
{
	int	i;

	if (stack_a->size <= 1)
		return (1);
	i = stack_a->size - 1;
	while (i > 0)
	{
		if (stack_a->data[i] > stack_a->data[i - 1])
			return (0);
		i--;
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
	
	// Get the three elements: top, middle, bottom
	top = stack_a->data[2];  // stack_a->data[stack_a->size - 1]
	mid = stack_a->data[1];  // stack_a->data[stack_a->size - 2]
	bot = stack_a->data[0];  // stack_a->data[stack_a->size - 3]
	
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
