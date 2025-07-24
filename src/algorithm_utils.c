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
    int	i;
    
    // Sort stack A (ascending) and stack B (descending) simultaneously
    i = 0;
    while (i < stack_a->size + stack_b->size)
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
        
        i++;
    }
}

/* Check if dual rotation benefits both stacks */
int	can_dual_rotate(t_stack *stack_a, t_stack *stack_b)
{
    int	a_benefit, b_benefit;
    
    if (stack_a->size < 2 || stack_b->size < 2)
        return (0);
    
    // Check if rotating A improves sorting (ascending)
    a_benefit = (stack_a->data[1] < stack_a->data[0]);
    
    // Check if rotating B improves sorting (descending)  
    b_benefit = (stack_b->data[1] > stack_b->data[0]);
    
    return (a_benefit && b_benefit);
}

/* Check if dual swap benefits both stacks */
int	can_dual_swap(t_stack *stack_a, t_stack *stack_b)
{
    int	a_benefit, b_benefit;
    
    if (stack_a->size < 2 || stack_b->size < 2)
        return (0);
    
    // Check if swapping A improves sorting (ascending)
    a_benefit = (stack_a->data[0] > stack_a->data[1]);
    
    // Check if swapping B improves sorting (descending)
    b_benefit = (stack_b->data[0] < stack_b->data[1]);
    
    return (a_benefit && b_benefit);
}

/* Check if dual reverse rotation benefits both stacks */
int	can_dual_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
    int	a_benefit, b_benefit;
    
    if (stack_a->size < 2 || stack_b->size < 2)
        return (0);
    
    // Check if reverse rotating A improves sorting (last element comes to top)
    a_benefit = (stack_a->data[stack_a->size - 1] < stack_a->data[0]);
    
    // Check if reverse rotating B improves sorting (last element comes to top)
    b_benefit = (stack_b->data[stack_b->size - 1] > stack_b->data[0]);
    
    return (a_benefit && b_benefit);
}