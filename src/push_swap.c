#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char	**numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		num_count;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	
	numbers = ft_split(argv[1], ' ');
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
	
	// Print initial state of stacks
	ft_printf("Initial state:\n");
	print_stacks(stack_a, stack_b);
	
	// TODO: Implement push_swap algorithm here
	// For now, stack_a contains all numbers, stack_b is empty
	
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

