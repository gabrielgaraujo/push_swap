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
	
	// Check if top element is greater than bottom element
	// Remember: stack_a->data[stack_a->size - 1] is the top (last pushed)
	if (stack_a->data[1] > stack_a->data[0])
		sa(stack_a);
}
