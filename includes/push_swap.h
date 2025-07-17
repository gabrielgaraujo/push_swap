#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../lib/libft/includes/libft.h"

typedef struct s_stack
{
	int	*data;
	int	size;
	int	capacity;
}	t_stack;

/* Stack utility functions */
int		count_numbers(char **numbers);
t_stack	*init_stack(int capacity);
void	free_stack(t_stack *stack);
int		populate_stack_a(t_stack *stack_a, char **numbers);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

/* Push_swap operations */
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif
