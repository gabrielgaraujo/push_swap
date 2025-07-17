#include "../includes/push_swap.h"

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
	
	(void)stack_a;      // Suppress unused parameter warning
	(void)stack_b;      // Suppress unused parameter warning
	
	ft_printf("Interactive mode not yet implemented.\n");
	ft_printf("Available operations: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr\n");
}

/*
** TODO: Helper functions to implement later:
**
** static int	execute_operation(char *operation, t_stack *stack_a, t_stack *stack_b);
** - Parse and execute a single operation
** - Return 1 if successful, 0 if invalid
**
** static int	validate_input(char *input);
** - Validate user input
** - Handle trimming and format checking
**
** static void	display_help(void);
** - Show available operations and usage
** - Display examples and special commands
*/
