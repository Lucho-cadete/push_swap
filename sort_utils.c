/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:50:19 by luimarti          #+#    #+#             */
/*   Updated: 2025/10/18 17:52:12 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dispatcher(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
	{
		assign_index(*stack_a);
		push_chunks_to_b(stack_a, stack_b);
		push_back_to_a(stack_a, stack_b);
	}
	return ;
}

int	find_min_value(t_node *stack)
{
	int	min;
	int	index;
	int	i;

	min = stack->value;
	index = 0;
	i = 0;
	if (!stack)
		return (-1);
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

void	bring_min_to_top(t_node **stack, int min_index)
{
	int	size;

	size = ft_stack_size(*stack);
	if (!stack || !*stack)
		return ;
	if (min_index < 0 || min_index >= size)
		return ;
	if (min_index <= size / 2)
	{
		while (min_index-- > 0)
			ra(stack);
	}
	else
	{
		min_index = size - min_index;
		while (min_index-- > 0)
			rra(stack);
	}
}

void	rotate_to_top(t_node **stack, int index, char stack_name)
{
	int	pos;
	int	size;

	pos = get_position_of_index(*stack, index);
	if (pos == -1)
		return ;
	size = ft_stack_size(*stack);
	while ((*stack)->index != index)
	{
		if (pos <= size / 2)
		{
			if (stack_name == 'a')
				ra(stack);
			else if (stack_name == 'b')
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else if (stack_name == 'b')
				rrb(stack);
		}
	}
}

void	bring_to_top(t_node **stack, int index, char stack_name)
{
	if (!stack || !*stack)
		return ;
	rotate_to_top(stack, index, stack_name);
}
