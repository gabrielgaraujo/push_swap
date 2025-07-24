#include "push_swap.h"

/* Split stack A into two halves - smaller values to B, larger to A */
void	split_stack_optimally(t_stack *stack_a, t_stack *stack_b)
{
    int	median;
    int	pushed_count;
    int	target_size;
    int	rotations;
    
    median = find_median(stack_a);
    target_size = stack_a->size / 2;
    pushed_count = 0;
    rotations = 0;
    
    while (pushed_count < target_size && rotations < stack_a->size * 2)
    {
        if (stack_a->data[0] <= median)
        {
            pb(stack_a, stack_b);
            pushed_count++;
            rotations = 0;  // Reset rotation counter
        }
        else
        {
            ra(stack_a);
            rotations++;
        }
    }
}