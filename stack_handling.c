/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:51:14 by lucho             #+#    #+#             */
/*   Updated: 2025/10/18 16:23:34 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_node *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	ft_fill_stack(t_node **stack, int value)
{
	t_node	*new;
	t_node	*current;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		write (2, "malloc failed\n", 14);
		return (0);
	}
	new->value = value;
	new->index = -1;
	new->next = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return (1);
	}
	else
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (1);
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
