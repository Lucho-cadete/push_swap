/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_chunks_to_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:40:25 by lucho             #+#    #+#             */
/*   Updated: 2025/10/18 16:25:23 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cheapest_index(t_node *stack, int min, int max)
{
	while (stack)
	{
		if (stack->index >= min && stack->index < max)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}

int	count_elements_in_chunk(t_node *stack, int min, int max)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index < max)
			count++;
		stack = stack->next;
	}
	return (count);
}

int	get_optimal_chunk_size(t_node *stack)
{
	int	total_size;

	total_size = ft_stack_size (stack);
	if (total_size <= 10)
		return (2);
	else if (total_size <= 50)
		return (5);
	else if (total_size <= 100)
		return (16);
	else if (total_size <= 200)
		return (20);
	else if (total_size <= 300)
		return (30);
	else if (total_size <= 400)
		return (35);
	else if (total_size <= 500)
		return (41);
	else
		return (60);
}

void	process_chunk(t_node **stack_a, t_node **stack_b, int min, int max)
{
	int	count;
	int	next;

	count = count_elements_in_chunk(*stack_a, min, max);
	while (count)
	{
		next = get_cheapest_index(*stack_a, min, max);
		if (next == -1)
			return ;
		bring_to_top(stack_a, next, 'a');
		pb(stack_a, stack_b);
		count--;
	}
}

void	push_chunks_to_b(t_node **stack_a, t_node **stack_b)
{
	int	total_size;
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	next;

	total_size = ft_stack_size(*stack_a);
	chunk_size = get_optimal_chunk_size(*stack_a);
	chunk_min = 0;
	chunk_max = chunk_size;
	while (chunk_min < total_size)
	{
		process_chunk(stack_a, stack_b, chunk_min, chunk_max);
		chunk_min += chunk_size;
		chunk_max += chunk_size;
	}
	while (ft_stack_size(*stack_a) > 0)
	{
		next = get_cheapest_index(*stack_a, INT_MIN, INT_MAX);
		bring_to_top(stack_a, next, 'a');
		pb(stack_a, stack_b);
	}
}
