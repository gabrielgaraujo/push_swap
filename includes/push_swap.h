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
int		populate_stack_a(int argc, char **argv, t_stack *stack_a);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
int		get_min_position(t_stack *stack);
int		get_max_position(t_stack *stack);
void	move_index_to_top(t_stack *stack, int index, char stack_name);

/* Input validation */
int		validate_input(int argc, char **argv);
int		find_duplicates(int argc, char **argv);
int		find_overflow(int argc, char **argv);
int		find_non_int(int argc, char **argv);
long	ft_atol(const char *str);

/* debugging functions */
extern t_stack *g_debug_stack_a;
extern t_stack *g_debug_stack_b;
void	debug_print_stacks(void);
void	debug_update_and_print(t_stack *stack_a, t_stack *stack_b);

/* Operation counter functions */
extern int	g_operation_count;
void	reset_operation_count(void);
void	increment_operation_count(void);
int		get_operation_count(void);
void	print_operation_count(void);

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

/* Algorithm functions */
int		is_sorted(t_stack *stack_a);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *stack_a, t_stack *stack_b);

/* Large stack algorithm functions */
void	split_stack_optimally(t_stack *stack_a, t_stack *stack_b);
void	dual_bubble_sort(t_stack *stack_a, t_stack *stack_b);
void	merge_sorted_stacks(t_stack *stack_a, t_stack *stack_b);
int		can_dual_rotate(t_stack *stack_a, t_stack *stack_b);
int		can_dual_swap(t_stack *stack_a, t_stack *stack_b);
int		can_dual_reverse_rotate(t_stack *stack_a, t_stack *stack_b);
int		single_stack_operations(t_stack *stack_a, t_stack *stack_b);
int		is_sorted_descending(t_stack *stack);
int		find_median(t_stack *stack);
int		find_insertion_position(t_stack *stack_a, int value);

#endif
