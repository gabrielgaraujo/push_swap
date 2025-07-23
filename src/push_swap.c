#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}

	stack_a = init_stack(argc - 1);
	stack_b = init_stack(argc - 1);

	if (!stack_a || !stack_b)
	{
		write(2, "Error\n", 6);
		// Clean up and exit
		if (stack_a)
			free_stack(stack_a);
		if (stack_b)
			free_stack(stack_b);
		return (1);
	}

	populate_stack_a(argc, argv, stack_a);

	// Reset operation counter
	reset_operation_count();
	
	// Set global debug stacks for operations debug printing
	g_debug_stack_a = stack_a;
	g_debug_stack_b = stack_b;
	
	// Check if already sorted first
	if (!is_sorted(stack_a))
	{
		// Apply appropriate sorting algorithm based on size
		if (stack_a->size == 2)
			sort_two(stack_a);
		else if (stack_a->size == 3)
			sort_three(stack_a);
		else if (stack_a->size == 4)
			sort_four(stack_a, stack_b);
		else
			sort_large(stack_a, stack_b);
	}

	// Clean up
	free_stack(stack_a);
	free_stack(stack_b);
	
	return (0);
}

