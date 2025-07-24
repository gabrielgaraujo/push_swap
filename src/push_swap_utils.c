#include "../includes/push_swap.h"

/* Global operation counter */
int g_operation_count = 0;

int count_numbers(char **numbers)
{
	int count;

	count = 0;
	while (numbers[count])
		count++;
	return (count);
}

t_stack *init_stack(int capacity)
{
	t_stack *stack;

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

int populate_stack_a(int argc, char **argv, t_stack *stack_a)
{
	int i;
	int num;

	i = 1;			 // Start from 1 to skip program name
	while (i < argc) // argc includes program name
	{
		num = ft_atoi(argv[i]);
		stack_a->data[i - 1] = num; // Store in natural order
		stack_a->size++;
		i++;
	}
	return (1);
}

void free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->data)
			free(stack->data);
		free(stack);
	}
}

void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int max_size;

	max_size = stack_a->size;
	if (stack_b->size > max_size)
		max_size = stack_b->size;

	ft_printf("Stack A\t\tStack B\n");
	ft_printf("-------\t\t-------\n");

	i = 0;
	while (i < max_size)
	{
		if (i < stack_a->size)
			ft_printf("%d\t\t", stack_a->data[i]); // data[0] at top
		else
			ft_printf(" \t\t");

		if (i < stack_b->size)
			ft_printf("%d\n", stack_b->data[i]); // data[0] at top
		else
			ft_printf(" \n");

		i++;
	}
	ft_printf("-------\t\t-------\n");
	ft_printf("   a\t\t   b\n\n");
}

/* Operation counter functions */
void reset_operation_count(void)
{
	g_operation_count = 0;
}

void increment_operation_count(void)
{
	g_operation_count++;
}

int get_operation_count(void)
{
	return (g_operation_count);
}

void print_operation_count(void)
{
	ft_printf("Total operations performed: %d\n", g_operation_count);
}

/* Get the position of the smallest value in the stack */
int get_min_position(t_stack *stack)
{
	int min_value;
	int min_position;
	int i;

	if (stack->size == 0)
		return (-1);

	min_value = stack->data[0]; // Start from top of stack (data[0])
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

/* Get the position of the greatest value in the stack */
int get_max_position(t_stack *stack)
{
	int max_value;
	int max_position;
	int i;

	if (stack->size == 0)
		return (-1);

	max_value = stack->data[0]; // Start from top of stack (data[0])
	max_position = 0;

	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i] > max_value)
		{
			max_value = stack->data[i];
			max_position = i;
		}
		i++;
	}

	return (max_position);
}

/* Move element at given index to top using least operations */
void move_index_to_top(t_stack *stack, int index, char stack_name)
{
	int moves_up;
	int moves_down;

	if (index < 0 || index >= stack->size)
		return;

	// Calculate moves needed in each direction
	// moves_up: rotations needed (ra/rb) to bring element to top (data[0])
	moves_up = index; // element at data[index] needs 'index' rotations to reach data[0]
	// moves_down: reverse rotations needed (rra/rrb) to bring element to top
	moves_down = stack->size - index; // reverse rotations from bottom

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

/* Input validation */
int validate_input(int argc, char **argv)
{
	if (find_overflow(argc, argv) || find_non_int(argc, argv) || find_duplicates(argc, argv))
	{
		return (0);
	}
	return (1);
}

int find_duplicates(int argc, char **argv)
{
	int i;
	int j;
	int num_i;
	int num_j;

	i = 1;
	while (i < argc)
	{
		num_i = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			num_j = ft_atoi(argv[j]);
			if (num_i == num_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int find_non_int(int argc, char **argv)
{
    int i;
    int j;

    i = 1; // Start from first argument
    while (i < argc)
    {
        j = 0;
        
        // Check if string is empty
        if (!argv[i][j])
            return (1);
        
        // Handle optional sign at the beginning only
        if (argv[i][j] == '-' || argv[i][j] == '+')
            j++;
        
        // Must have at least one digit after optional sign
        if (!argv[i][j])
            return (1);
        
        // Rest must be digits only
        while (argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

long	ft_atol(const char *str)
{
    long	result;
    int		sign;
    int		i;

    result = 0;
    sign = 1;
    i = 0;
    
    // Skip leading whitespace
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || 
           str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
        i++;
    
    // Handle sign
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    
    // Convert digits to long
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    
    return (result * sign);
}

int find_overflow(int argc, char **argv)
{
	int i;
	long num;

	i = 1; // Start from first argument
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num < -2147483648L || num > 2147483647L)
			return (1);
		i++;
	}
	return (0);
}