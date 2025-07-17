#include "../includes/push_swap.h"

/* sa - swap the first 2 elements at the top of stack a */
void	sa(t_stack *stack_a)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->data[stack_a->size - 1];
	stack_a->data[stack_a->size - 1] = stack_a->data[stack_a->size - 2];
	stack_a->data[stack_a->size - 2] = temp;
	ft_printf("sa\n");
}

/* sb - swap the first 2 elements at the top of stack b */
void	sb(t_stack *stack_b)
{
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->data[stack_b->size - 1];
	stack_b->data[stack_b->size - 1] = stack_b->data[stack_b->size - 2];
	stack_b->data[stack_b->size - 2] = temp;
	ft_printf("sb\n");
}

/* ss - sa and sb at the same time */
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_a->size >= 2)
	{
		temp = stack_a->data[stack_a->size - 1];
		stack_a->data[stack_a->size - 1] = stack_a->data[stack_a->size - 2];
		stack_a->data[stack_a->size - 2] = temp;
	}
	if (stack_b->size >= 2)
	{
		temp = stack_b->data[stack_b->size - 1];
		stack_b->data[stack_b->size - 1] = stack_b->data[stack_b->size - 2];
		stack_b->data[stack_b->size - 2] = temp;
	}
	ft_printf("ss\n");
}

/* pa - take the first element at the top of b and put it at the top of a */
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size == 0)
		return ;
	stack_a->data[stack_a->size] = stack_b->data[stack_b->size - 1];
	stack_a->size++;
	stack_b->size--;
	ft_printf("pa\n");
}

/* pb - take the first element at the top of a and put it at the top of b */
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 0)
		return ;
	stack_b->data[stack_b->size] = stack_a->data[stack_a->size - 1];
	stack_b->size++;
	stack_a->size--;
	ft_printf("pb\n");
}

/* ra - shift up all elements of stack a by 1 (first element becomes last) */
void	ra(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->data[stack_a->size - 1];
	i = stack_a->size - 1;
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	stack_a->data[0] = temp;
	ft_printf("ra\n");
}

/* rb - shift up all elements of stack b by 1 (first element becomes last) */
void	rb(t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->data[stack_b->size - 1];
	i = stack_b->size - 1;
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i--;
	}
	stack_b->data[0] = temp;
	ft_printf("rb\n");
}

/* rr - ra and rb at the same time */
void	rr(t_stack *stack_a, t_stack *stack_b)
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
	ft_printf("rr\n");
}

/* rra - shift down all elements of stack a by 1 (last element becomes first) */
void	rra(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->data[0];
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	stack_a->data[stack_a->size - 1] = temp;
	ft_printf("rra\n");
}

/* rrb - shift down all elements of stack b by 1 (last element becomes first) */
void	rrb(t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->data[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
	stack_b->data[stack_b->size - 1] = temp;
	ft_printf("rrb\n");
}

/* rrr - rra and rrb at the same time */
void	rrr(t_stack *stack_a, t_stack *stack_b)
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
	ft_printf("rrr\n");
}
