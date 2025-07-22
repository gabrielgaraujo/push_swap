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

	i = 0;
	while (numbers[i])
	{
		num = ft_atoi(numbers[i]);
		stack_a->data[i] = num;
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
