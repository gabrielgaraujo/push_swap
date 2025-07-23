#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char	**numbers;
	char	*args_string;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		num_count;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	
	// Reconstruct arguments into a single string
	args_string = reconstruct_args(argc, argv);
	if (!args_string)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	
	numbers = ft_split(args_string, ' ');
	free(args_string);  // Free the reconstructed string
	if (!numbers)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	
	// Count numbers and initialize stacks
	num_count = count_numbers(numbers);
	stack_a = init_stack(num_count);
	stack_b = init_stack(num_count);
	
	if (!stack_a || !stack_b)
	{
		write(2, "Error\n", 6);
		// Clean up and exit
		if (stack_a)
			free_stack(stack_a);
		if (stack_b)
			free_stack(stack_b);
		i = 0;
		while (numbers[i])
		{
			free(numbers[i]);
			i++;
		}
		free(numbers);
		return (1);
	}
	
	// Populate stack A with the numbers
	populate_stack_a(stack_a, numbers);
	
	// Reset operation counter
	reset_operation_count();
	
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
	
	// Uncomment to enable interactive mode for testing
	// interactive_mode(stack_a, stack_b);

	// Clean up
	free_stack(stack_a);
	free_stack(stack_b);
	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
	
	return (0);
}

