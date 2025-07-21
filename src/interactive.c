#include "../includes/push_swap.h"


static int	execute_operation(char *operation, t_stack *stack_a, t_stack *stack_b);
static char	*validate_input(char *input);
static int	handle_special_commands(char *input);
static void	display_error(char *invalid_input);

/*
** Interactive mode for manually testing operations
** This function allows the user to input operations one by one
** and see the results in real-time for debugging and learning purposes
*/
static char	*read_line_from_stdin(void)
{
	char	buffer[256];
	char	*line;
	int		i;
	char	c;
	int		bytes_read;

	i = 0;
	while (i < 255)
	{
		bytes_read = read(0, &c, 1);
		if (bytes_read <= 0)
			break;
		if (c == '\n')
			break;
		buffer[i] = c;
		i++;
	}
	
	if (i == 0)
		return (NULL);
	
	buffer[i] = '\0';
	line = ft_strdup(buffer);
	return (line);
}

void	interactive_mode(t_stack *stack_a, t_stack *stack_b)
{
	char	*input;
	int		should_exit;

	ft_printf("=== Interactive Mode ===\n");
	ft_printf("Type 'help' for available operations or 'exit' to quit.\n\n");
	
	// Show initial state
	print_stacks(stack_a, stack_b);
	
	should_exit = 0;
	while (!should_exit)
	{
		ft_printf("\nEnter operation: ");
		
		// Read a line of input from the user
		input = read_line_from_stdin();
		if (!input)
		{
			ft_printf("\nEnd of input detected. Exiting.\n");
			break;
		}
		
		// Execute the operation
		should_exit = execute_operation(input, stack_a, stack_b);
		
		if (!should_exit)
		{
			// Show updated stacks after operation
			ft_printf("\nUpdated stacks:\n");
			print_stacks(stack_a, stack_b);
		}
		
		free(input);
	}
	
	ft_printf("Exiting interactive mode.\n");
}

/*
** Helper function to parse and execute a single operation
** Returns 1 if operation was valid and executed, 0 otherwise
*/
static int	execute_operation(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	char	*trimmed_input;
	int		special_result;

	trimmed_input = validate_input(operation);
	if (!trimmed_input)
	{
		display_error(operation);
		return (0);
	}

	special_result = handle_special_commands(trimmed_input);
	if (special_result == 1)
	{
		free(trimmed_input);
		return (1); // Exit requested
	}
	if (special_result == 2)
	{
		free(trimmed_input);
		return (0); // Help displayed, continue
	}

	// Add safety checks before operations
	if (!stack_a || !stack_b)
	{
		ft_printf("Error: Invalid stack pointers\n");
		free(trimmed_input);
		return (0);
	}

	// Check for exact matches with proper length validation and safety checks
	if (ft_strncmp(trimmed_input, "sa", 2) == 0 && ft_strlen(trimmed_input) == 2)
	{
		if (stack_a->size >= 2)
			sa(stack_a);
		else
			ft_printf("Cannot swap: Stack A has less than 2 elements\n");
	}
	else if (ft_strncmp(trimmed_input, "sb", 2) == 0 && ft_strlen(trimmed_input) == 2)
	{
		if (stack_b->size >= 2)
			sb(stack_b);
		else
			ft_printf("Cannot swap: Stack B has less than 2 elements\n");
	}
	else if (ft_strncmp(trimmed_input, "ss", 2) == 0 && ft_strlen(trimmed_input) == 2)
	{
		if (stack_a->size >= 2 || stack_b->size >= 2)
			ss(stack_a, stack_b);
		else
			ft_printf("Cannot swap: Both stacks have less than 2 elements\n");
	}
	else if (ft_strncmp(trimmed_input, "pa", 2) == 0 && ft_strlen(trimmed_input) == 2)
	{
		if (stack_b->size > 0)
			pa(stack_a, stack_b);
		else
			ft_printf("Cannot push to A: Stack B is empty\n");
	}
	else if (ft_strncmp(trimmed_input, "pb", 2) == 0 && ft_strlen(trimmed_input) == 2)
	{
		if (stack_a->size > 0)
			pb(stack_a, stack_b);
		else
			ft_printf("Cannot push to B: Stack A is empty\n");
	}
	else if (ft_strncmp(trimmed_input, "rra", 3) == 0 && ft_strlen(trimmed_input) == 3)
	{
		if (stack_a->size > 1)
			rra(stack_a);
		else
			ft_printf("Cannot reverse rotate: Stack A has less than 2 elements\n");
	}
	else if (ft_strncmp(trimmed_input, "rrb", 3) == 0 && ft_strlen(trimmed_input) == 3)
	{
		if (stack_b->size > 1)
			rrb(stack_b);
		else
			ft_printf("Cannot reverse rotate: Stack B has less than 2 elements\n");
	}
	else if (ft_strncmp(trimmed_input, "rrr", 3) == 0 && ft_strlen(trimmed_input) == 3)
	{
		if (stack_a->size > 1 || stack_b->size > 1)
			rrr(stack_a, stack_b);
		else
			ft_printf("Cannot reverse rotate: Both stacks have less than 2 elements\n");
	}
	else if (ft_strncmp(trimmed_input, "ra", 2) == 0 && ft_strlen(trimmed_input) == 2)
	{
		if (stack_a->size > 1)
			ra(stack_a);
		else
			ft_printf("Cannot rotate: Stack A has less than 2 elements\n");
	}
	else if (ft_strncmp(trimmed_input, "rb", 2) == 0 && ft_strlen(trimmed_input) == 2)
	{
		if (stack_b->size > 1)
			rb(stack_b);
		else
			ft_printf("Cannot rotate: Stack B has less than 2 elements\n");
	}
	else if (ft_strncmp(trimmed_input, "rr", 2) == 0 && ft_strlen(trimmed_input) == 2)
	{
		if (stack_a->size > 1 || stack_b->size > 1)
			rr(stack_a, stack_b);
		else
			ft_printf("Cannot rotate: Both stacks have less than 2 elements\n");
	}
	else
	{
		display_error(trimmed_input);
		free(trimmed_input);
		return (0);
	}
	
	free(trimmed_input);
	return (0); // Continue execution
}

static char	*validate_input(char *input)
{
	char	*trimmed_input;
	int		i;

	if (!input)
		return (NULL);
	
	// Trim leading and trailing whitespace
	trimmed_input = ft_strtrim(input, " \t\n\r\v\f");
	if (!trimmed_input || ft_strlen(trimmed_input) == 0)
	{
		free(trimmed_input);
		return (NULL);
	}
	
	// Check for valid operation length
	if (ft_strlen(trimmed_input) < 2 || ft_strlen(trimmed_input) > 4)
	{
		free(trimmed_input);
		return (NULL);
	}

	// Character validation - should only contain letters
	i = 0;
	while (trimmed_input[i])
	{
		if (!ft_isalpha(trimmed_input[i]))
		{
			free(trimmed_input);
			return (NULL);
		}
		i++;
	}

	return (trimmed_input);
}

static int	handle_special_commands(char *input)
{
	if (!input)
		return (0);
	
	if (ft_strncmp(input, "exit", 4) == 0 || ft_strncmp(input, "quit", 4) == 0)
	{
		ft_printf("Exiting interactive mode.\n");
		return (1); // Signal to exit
	}
	
	if (ft_strncmp(input, "help", 4) == 0)
	{
		ft_printf("Available operations:\n");
		ft_printf("  sa  - swap a (swap first 2 elements of stack a)\n");
		ft_printf("  sb  - swap b (swap first 2 elements of stack b)\n");
		ft_printf("  ss  - swap both stacks\n");
		ft_printf("  pa  - push a (move first element from b to a)\n");
		ft_printf("  pb  - push b (move first element from a to b)\n");
		ft_printf("  ra  - rotate a (move first element to bottom)\n");
		ft_printf("  rb  - rotate b (move first element to bottom)\n");
		ft_printf("  rr  - rotate both stacks\n");
		ft_printf("  rra - reverse rotate a (move last element to top)\n");
		ft_printf("  rrb - reverse rotate b (move last element to top)\n");
		ft_printf("  rrr - reverse rotate both stacks\n");
		ft_printf("  help - show this help\n");
		ft_printf("  exit/quit - exit interactive mode\n");
		return (2); // Help displayed
	}
	
	return (0); // Continue
}

static void	display_error(char *invalid_input)
{
	ft_printf("Error: Invalid operation '%s'\n", invalid_input);
	ft_printf("Type 'help' for available operations or 'exit' to quit.\n");
}