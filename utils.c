/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:34:14 by lucho             #+#    #+#             */
/*   Updated: 2025/10/18 16:23:38 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_free(t_node **stack)
{
	t_node	*current;
	t_node	*temp;

	current = *stack;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
