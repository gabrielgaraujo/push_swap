#include "../includes/push_swap.h"

/* Global operation counter */
int	g_operation_count = 0;

int	count_numbers(char **numbers)
{
	int	count;

	count = 0;
	while (numbers[count])
		count++;
	return (count);
}

t_stack	*init_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = malloc(sizeof(int) * capacity);
	if (!stack->data)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->data)
			free(stack->data);
		free(stack);
	}
}

int	populate_stack_a(t_stack *stack_a, char **numbers)
{
	int	i;
	int	num;

	// Populate in regular order
	i = 0;
	while (numbers[i])
	{
		num = ft_atoi(numbers[i]);
		stack_a->data[i] = num;  // Store in regular order
		stack_a->size++;
		i++;
	}
	return (1);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max_size;

	max_size = stack_a->size;
	if (stack_b->size > max_size)
		max_size = stack_b->size;
	
	ft_printf("Stack A\t\tStack B\n");
	ft_printf("-------\t\t-------\n");
	
	i = max_size - 1;
	while (i >= 0)
	{
		if (i < stack_a->size)
			ft_printf("%d\t\t", stack_a->data[i]);
		else
			ft_printf(" \t\t");
		
		if (i < stack_b->size)
			ft_printf("%d\n", stack_b->data[i]);
		else
			ft_printf(" \n");
		
		i--;
	}
	ft_printf("-------\t\t-------\n");
	ft_printf("   a\t\t   b\n\n");
}

/* Operation counter functions */
void	reset_operation_count(void)
{
	g_operation_count = 0;
}

void	increment_operation_count(void)
{
	g_operation_count++;
}

int	get_operation_count(void)
{
	return (g_operation_count);
}

void	print_operation_count(void)
{
	ft_printf("Total operations performed: %d\n", g_operation_count);
}

/* Get the position of the smallest value in the stack */
int	get_min_position(t_stack *stack)
{
	int	min_value;
	int	min_position;
	int	i;

	if (stack->size == 0)
		return (-1);
	
	min_value = stack->data[0];
	min_position = 0;
	
	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i] < min_value)
		{
			min_value = stack->data[i];
			min_position = i;
		}
		i++;
	}
	
	return (min_position);
}

/* Move element at given index to top using least operations */
void	move_index_to_top(t_stack *stack, int index, char stack_name)
{
	int	moves_up;
	int	moves_down;

	if (index < 0 || index >= stack->size)
		return;
	
	// Calculate moves needed in each direction
	moves_up = (stack->size - 1) - index;  // rotations needed (ra/rb) to reach top
	moves_down = index + 1;                 // reverse rotations needed (rra/rrb)
	
	// Choose the most efficient direction
	if (moves_up <= moves_down)
	{
		// Use rotate up (ra/rb)
		while (moves_up > 0)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
			moves_up--;
		}
	}
	else
	{
		// Use rotate down (rra/rrb)
		while (moves_down > 0)
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
			moves_down--;
		}
	}
}

/* Reconstruct command line arguments into a single string */
char	*reconstruct_args(int argc, char **argv)
{
	char	*result;
	char	*temp;
	int		i;

	if (argc < 2)
		return (NULL);
	
	// Start with the first argument
	result = ft_strdup(argv[1]);
	if (!result)
		return (NULL);
	
	// Join remaining arguments with spaces
	i = 2;
	while (i < argc)
	{
		temp = ft_strjoin(result, " ");
		free(result);
		if (!temp)
			return (NULL);
		result = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!result)
			return (NULL);
		i++;
	}
	
	return (result);
}
	}
	
	return (result);
}


