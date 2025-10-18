/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_back_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 01:28:48 by lucho             #+#    #+#             */
/*   Updated: 2025/10/18 16:23:09 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_node *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

void	push_back_to_a(t_node **stack_a, t_node **stack_b)
{
	int	max;

	while (*stack_b)
	{
		max = find_max_index(*stack_b);
		bring_to_top(stack_b, max, 'b');
		pa(stack_a, stack_b);
	}
	return ;
}
