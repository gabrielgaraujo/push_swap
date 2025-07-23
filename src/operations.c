#include "../includes/push_swap.h"
t_stack *g_debug_stack_a = NULL;  // Global for debugging
t_stack *g_debug_stack_b = NULL;  // Global for debugging

void debug_print_stacks(void)
{
    int i;
    
    if (!g_debug_stack_a || !g_debug_stack_b)
        return;
        
    ft_printf("Stack A: ");
    i = 0;
    while (i < g_debug_stack_a->size)
    {
        ft_printf("%d ", g_debug_stack_a->data[i]);
        i++;
    }
    ft_printf("(size: %d)\n", g_debug_stack_a->size);
    
    ft_printf("Stack B: ");
    i = 0;
    while (i < g_debug_stack_b->size)
    {
        ft_printf("%d ", g_debug_stack_b->data[i]);
        i++;
    }
    ft_printf("(size: %d)\n", g_debug_stack_b->size);
    ft_printf("---\n");
}

// Function to update debug stacks and print current state
void debug_update_and_print(t_stack *stack_a, t_stack *stack_b)
{
    g_debug_stack_a = stack_a;
    g_debug_stack_b = stack_b;
    debug_print_stacks();
}

/* sa - swap the first 2 elements at the top of stack a */
void	sa(t_stack *stack_a)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->data[0];  // Top element
	stack_a->data[0] = stack_a->data[1];  // Second element
	stack_a->data[1] = temp;
	increment_operation_count();
	ft_printf("sa\n");
	debug_print_stacks();
}

/* sb - swap the first 2 elements at the top of stack b */
void	sb(t_stack *stack_b)
{
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->data[0];  // Top element
	stack_b->data[0] = stack_b->data[1];  // Second element
	stack_b->data[1] = temp;
	increment_operation_count();
	ft_printf("sb\n");
	debug_print_stacks();
}

/* ss - sa and sb at the same time */
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_a->size >= 2)
	{
		temp = stack_a->data[0];
		stack_a->data[0] = stack_a->data[1];
		stack_a->data[1] = temp;
	}
	if (stack_b->size >= 2)
	{
		temp = stack_b->data[0];
		stack_b->data[0] = stack_b->data[1];
		stack_b->data[1] = temp;
	}
	increment_operation_count();
	ft_printf("ss\n");
	debug_print_stacks();
}

/* pa - take the first element at the top of b and put it at the top of a */
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_b->size == 0)
		return ;
	
	// Shift all elements in A down to make room at top
	i = stack_a->size;
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	
	// Put top of B at top of A
	stack_a->data[0] = stack_b->data[0];
	stack_a->size++;
	
	// Shift all elements in B up to remove top element
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
	stack_b->size--;
	
	increment_operation_count();
	ft_printf("pa\n");
	debug_print_stacks();
}

/* pb - take the first element at the top of a and put it at the top of b */
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a->size == 0)
		return ;
	
	// Shift all elements in B down to make room at top
	i = stack_b->size;
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i--;
	}
	
	// Put top of A at top of B
	stack_b->data[0] = stack_a->data[0];
	stack_b->size++;
	
	// Shift all elements in A up to remove top element
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	stack_a->size--;
	
	increment_operation_count();
	ft_printf("pb\n");
	debug_print_stacks();
}

/* ra - shift up all elements of stack a by 1 (first element becomes last) */
void	ra(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->size < 2)
		return ;
	
	// Save top element
	temp = stack_a->data[0];
	
	// Shift all elements up
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	
	// Put old top at bottom
	stack_a->data[stack_a->size - 1] = temp;
	increment_operation_count();
	ft_printf("ra\n");
	debug_print_stacks();
}

/* rb - shift up all elements of stack b by 1 (first element becomes last) */
void	rb(t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_b->size < 2)
		return ;
	
	// Save top element
	temp = stack_b->data[0];
	
	// Shift all elements up
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
	
	// Put old top at bottom
	stack_b->data[stack_b->size - 1] = temp;
	increment_operation_count();
	ft_printf("rb\n");
	debug_print_stacks();
}

/* rr - ra and rb at the same time */
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_a->size >= 2)
	{
		temp = stack_a->data[0];
		i = 0;
		while (i < stack_a->size - 1)
		{
			stack_a->data[i] = stack_a->data[i + 1];
			i++;
		}
		stack_a->data[stack_a->size - 1] = temp;
	}
	if (stack_b->size >= 2)
	{
		temp = stack_b->data[0];
		i = 0;
		while (i < stack_b->size - 1)
		{
			stack_b->data[i] = stack_b->data[i + 1];
			i++;
		}
		stack_b->data[stack_b->size - 1] = temp;
	}
	increment_operation_count();
	ft_printf("rr\n");
	debug_print_stacks();
}

/* rra - shift down all elements of stack a by 1 (last element becomes first) */
void	rra(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->size < 2)
		return ;
	
	// Save bottom element
	temp = stack_a->data[stack_a->size - 1];
	
	// Shift all elements down
	i = stack_a->size - 1;
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	
	// Put old bottom at top
	stack_a->data[0] = temp;
	increment_operation_count();
	ft_printf("rra\n");
	debug_print_stacks();
}

/* rrb - shift down all elements of stack b by 1 (last element becomes first) */
void	rrb(t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_b->size < 2)
		return ;
	
	// Save bottom element
	temp = stack_b->data[stack_b->size - 1];
	
	// Shift all elements down
	i = stack_b->size - 1;
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i--;
	}
	
	// Put old bottom at top
	stack_b->data[0] = temp;
	increment_operation_count();
	ft_printf("rrb\n");
	debug_print_stacks();
}

/* rrr - rra and rrb at the same time */
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_a->size >= 2)
	{
		temp = stack_a->data[stack_a->size - 1];
		i = stack_a->size - 1;
		while (i > 0)
		{
			stack_a->data[i] = stack_a->data[i - 1];
			i--;
		}
		stack_a->data[0] = temp;
	}
	if (stack_b->size >= 2)
	{
		temp = stack_b->data[stack_b->size - 1];
		i = stack_b->size - 1;
		while (i > 0)
		{
			stack_b->data[i] = stack_b->data[i - 1];
			i--;
		}
		stack_b->data[0] = temp;
	}
	increment_operation_count();
	ft_printf("rrr\n");
	debug_print_stacks();
}
