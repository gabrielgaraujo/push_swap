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
    int	max_iterations;
    int	i;
    int	progress_made;
    
    // More aggressive iteration limit for thorough sorting
    max_iterations = (stack_a->size + stack_b->size) * 4;
    
    i = 0;
    while (i < max_iterations)
    {
        progress_made = 0;
        
        // Prioritize dual operations - they're more efficient
        if (can_dual_swap(stack_a, stack_b))
        {
            ss(stack_a, stack_b);
            progress_made = 1;
        }
        else if (can_dual_rotate(stack_a, stack_b))
        {
            rr(stack_a, stack_b);
            progress_made = 1;
        }
        else if (can_dual_reverse_rotate(stack_a, stack_b))
        {
            rrr(stack_a, stack_b);
            progress_made = 1;
        }
        else
        {
            // Individual operations when dual operations don't apply
            progress_made = single_stack_operations(stack_a, stack_b);
        }
        
        // Check if both stacks are optimally sorted
        if (is_sorted(stack_a) && is_sorted_descending(stack_b))
            break;
        
        // If no progress, break to avoid infinite loops
        if (!progress_made)
            break;
        
        i++;
    }
}

/* Merge two sorted stacks back together */
void	merge_sorted_stacks(t_stack *stack_a, t_stack *stack_b)
{
    // Merge elements from B back to A in optimal positions
    while (stack_b->size > 0)
    {
        // Find where B's top element belongs in A
        int target_pos = find_insertion_position(stack_a, stack_b->data[0]);
        
        // Move target position to top of A efficiently
        if (target_pos <= stack_a->size / 2)
        {
            // Rotate forward to bring target position to top
            while (target_pos > 0)
            {
                ra(stack_a);
                target_pos--;
            }
        }
        else
        {
            // Rotate backward to bring target position to top
            int rotations = stack_a->size - target_pos;
            while (rotations > 0)
            {
                rra(stack_a);
                rotations--;
            }
        }
        
        // Push from B to A
        pa(stack_a, stack_b);
    }
    
    // Final optimization: ensure minimum is at top
    int min_pos = get_min_position(stack_a);
    if (min_pos == 0)
        return; // Already optimal
        
    if (min_pos <= stack_a->size / 2)
    {
        // Rotate forward to bring minimum to top
        while (min_pos > 0)
        {
            ra(stack_a);
            min_pos--;
        }
    }
    else
    {
        // Rotate backward to bring minimum to top
        int rotations = stack_a->size - min_pos;
        while (rotations > 0)
        {
            rra(stack_a);
            rotations--;
        }
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

/* Perform single stack operations when dual operations don't help */
int	single_stack_operations(t_stack *stack_a, t_stack *stack_b)
{
    int	operations = 0;
    int	best_move_found = 0;
    
    // Try to make the most beneficial single move for stack A (ascending)
    if (!is_sorted(stack_a) && stack_a->size >= 2 && !best_move_found)
    {
        // Priority 1: Simple swap if it helps immediately
        if (stack_a->data[0] > stack_a->data[1])
        {
            // Check if swap actually improves the overall order
            int improvements = 0;
            if (stack_a->size >= 3 && stack_a->data[1] < stack_a->data[2])
                improvements++;
            if (improvements > 0 || stack_a->size == 2)
            {
                sa(stack_a);
                operations++;
                best_move_found = 1;
            }
        }
        
        // Priority 2: Reverse rotate if bottom element fits better at top
        if (!best_move_found && stack_a->size >= 3)
        {
            int bottom = stack_a->data[stack_a->size - 1];
            int top = stack_a->data[0];
            // Only reverse rotate if bottom element is significantly smaller
            if (bottom < top && (stack_a->size <= 3 || bottom < stack_a->data[1]))
            {
                rra(stack_a);
                operations++;
                best_move_found = 1;
            }
        }
        
        // Priority 3: Regular rotate (but be more selective)
        if (!best_move_found && stack_a->size >= 3)
        {
            // Only rotate if it brings a smaller element towards the front
            int second = stack_a->data[1];
            if (second < stack_a->data[0])
            {
                ra(stack_a);
                operations++;
                best_move_found = 1;
            }
        }
    }
    
    // Try to make the most beneficial single move for stack B (descending)
    if (!is_sorted_descending(stack_b) && stack_b->size >= 2 && !best_move_found)
    {
        // Priority 1: Simple swap if it helps immediately
        if (stack_b->data[0] < stack_b->data[1])
        {
            // Check if swap actually improves the overall order
            int improvements = 0;
            if (stack_b->size >= 3 && stack_b->data[1] > stack_b->data[2])
                improvements++;
            if (improvements > 0 || stack_b->size == 2)
            {
                sb(stack_b);
                operations++;
                best_move_found = 1;
            }
        }
        
        // Priority 2: Reverse rotate if bottom element fits better at top
        if (!best_move_found && stack_b->size >= 3)
        {
            int bottom = stack_b->data[stack_b->size - 1];
            int top = stack_b->data[0];
            // Only reverse rotate if bottom element is significantly larger
            if (bottom > top && (stack_b->size <= 3 || bottom > stack_b->data[1]))
            {
                rrb(stack_b);
                operations++;
                best_move_found = 1;
            }
        }
        
        // Priority 3: Regular rotate (but be more selective)
        if (!best_move_found && stack_b->size >= 3)
        {
            // Only rotate if it brings a larger element towards the front
            int second = stack_b->data[1];
            if (second > stack_b->data[0])
            {
                rb(stack_b);
                operations++;
                best_move_found = 1;
            }
        }
    }
    
    return (operations);
}

/* Helper: Check if stack is sorted in descending order */
int	is_sorted_descending(t_stack *stack)
{
    int	i;
    
    if (stack->size <= 1)
        return (1);
    
    i = 0;
    while (i < stack->size - 1)
    {
        if (stack->data[i] < stack->data[i + 1])
            return (0);
        i++;
    }
    return (1);
}

/* Helper: Find median value in stack */
int	find_median(t_stack *stack)
{
    int	*sorted_array;
    int	median;
    int	i, j, temp;
    
    sorted_array = malloc(sizeof(int) * stack->size);
    if (!sorted_array)
        return (0);
    
    // Copy values
    i = 0;
    while (i < stack->size)
    {
        sorted_array[i] = stack->data[i];
        i++;
    }
    
    // Simple bubble sort
    i = 0;
    while (i < stack->size - 1)
    {
        j = 0;
        while (j < stack->size - 1 - i)
        {
            if (sorted_array[j] > sorted_array[j + 1])
            {
                temp = sorted_array[j];
                sorted_array[j] = sorted_array[j + 1];
                sorted_array[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
    
    median = sorted_array[stack->size / 2];
    free(sorted_array);
    return (median);
}

/* Helper: Find where a value should be inserted in sorted stack A */
int	find_insertion_position(t_stack *stack_a, int value)
{
    int	i;
    
    if (stack_a->size == 0)
        return (0);
    
    // Find the position where value should be inserted to maintain order
    i = 0;
    while (i < stack_a->size)
    {
        if (stack_a->data[i] > value)
            return (i);
        i++;
    }
    
    // If value is larger than all elements, insert at end
    return (stack_a->size);
}