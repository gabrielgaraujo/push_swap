#include "../includes/push_swap.h"

/* Forward declarations of static functions */
static int	execute_operation(char *operation, t_stack *stack_a, t_stack *stack_b);

/*
** Interactive mode for manually testing operations
** This function allows the user to input operations one by one
** and see the results in real-time for debugging and learning purposes
*/
void	interactive_mode(t_stack *stack_a, t_stack *stack_b)
{
	// TODO: Implement interactive mode
	// This function will:
	// 1. Display available operations
	// 2. Read user input (operations like sa, pb, ra, etc.)
	// 3. Execute the requested operation
	// 4. Show the updated stacks
	// 5. Loop until user types 'quit' or 'exit'
	
	(void)stack_a;      // Suppress unused parameter warning for now
	(void)stack_b;      // Suppress unused parameter warning for now
	
	ft_printf("Interactive mode not yet implemented.\n");
	ft_printf("Available operations: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr\n");
	ft_printf("execute_operation function ready and tested!\n");
}

/*
** Helper function to parse and execute a single operation
** Returns 1 if operation was valid and executed, 0 otherwise
*/
static int	execute_operation(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	if (!operation || ft_strlen(operation) == 0)
		return (0);
	
	// Check for exact matches with proper length validation
	if (ft_strncmp(operation, "sa", 2) == 0 && ft_strlen(operation) == 2)
	{
		sa(stack_a);
		return (1);
	}
	else if (ft_strncmp(operation, "sb", 2) == 0 && ft_strlen(operation) == 2)
	{
		sb(stack_b);
		return (1);
	}
	else if (ft_strncmp(operation, "ss", 2) == 0 && ft_strlen(operation) == 2)
	{
		ss(stack_a, stack_b);
		return (1);
	}
	else if (ft_strncmp(operation, "pa", 2) == 0 && ft_strlen(operation) == 2)
	{
		pa(stack_a, stack_b);
		return (1);
	}
	else if (ft_strncmp(operation, "pb", 2) == 0 && ft_strlen(operation) == 2)
	{
		pb(stack_a, stack_b);
		return (1);
	}
	else if (ft_strncmp(operation, "rra", 3) == 0 && ft_strlen(operation) == 3)
	{
		rra(stack_a);
		return (1);
	}
	else if (ft_strncmp(operation, "rrb", 3) == 0 && ft_strlen(operation) == 3)
	{
		rrb(stack_b);
		return (1);
	}
	else if (ft_strncmp(operation, "rrr", 3) == 0 && ft_strlen(operation) == 3)
	{
		rrr(stack_a, stack_b);
		return (1);
	}
	else if (ft_strncmp(operation, "ra", 2) == 0 && ft_strlen(operation) == 2)
	{
		ra(stack_a);
		return (1);
	}
	else if (ft_strncmp(operation, "rb", 2) == 0 && ft_strlen(operation) == 2)
	{
		rb(stack_b);
		return (1);
	}
	else if (ft_strncmp(operation, "rr", 2) == 0 && ft_strlen(operation) == 2)
	{
		rr(stack_a, stack_b);
		return (1);
	}
	
	// Operation not found
	return (0);
}

/*
** TODO: Helper functions to implement later:
**
** static int	validate_input(char *input);
** - Validate user input
** - Handle trimming and format checking
**
** static void	display_help(void);
** - Show available operations and usage
** - Display examples and special commands
*/
