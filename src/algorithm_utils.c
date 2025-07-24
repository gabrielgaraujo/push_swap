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

/* Sort both stacks simultaneously using dual operations when possible */
void	dual_bubble_sort(t_stack *stack_a, t_stack *stack_b)
{
    int	swapped;
    int	pass;
    
    // Sort stack A (ascending) and stack B (descending) simultaneously
    pass = 0;
    while (pass < stack_a->size + stack_b->size)
    {
        swapped = 0;
        
        // Try dual rotation first
        if (can_dual_rotate(stack_a, stack_b))
        {
            rr(stack_a, stack_b);
            swapped = 1;
        }
        // Try dual swap
        else if (can_dual_swap(stack_a, stack_b))
        {
            ss(stack_a, stack_b);
            swapped = 1;
        }
        // Try dual reverse rotation
        else if (can_dual_reverse_rotate(stack_a, stack_b))
        {
            rrr(stack_a, stack_b);
            swapped = 1;
        }
        // Individual operations
        else
        {
            swapped += single_stack_operations(stack_a, stack_b);
        }
        
        // If both stacks are sorted, break
        if (is_sorted_ascending(stack_a) && is_sorted_descending(stack_b))
            break;
        
        if (!swapped)
            break;
        
        pass++;
    }
}