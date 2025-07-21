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
