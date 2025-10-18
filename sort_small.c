/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_values_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:51:21 by lucho             #+#    #+#             */
/*   Updated: 2025/10/18 16:24:28 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	return ;
}

void	sort_three_actions(t_node **stack_a, int first, int second, int third)
{
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && first > third && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first < second && first > third && second > third)
		rra(stack_a);
	else if (first < second && first < third && second > third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first > second && first > third && second < third)
		ra(stack_a);
}

void	sort_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first < second && second < third)
		return ;
	sort_three_actions(stack_a, first, second, third);
}

void	sort_four(t_node **a, t_node **b)
{
	int	min_value;

	min_value = find_min_value(*a);
	bring_min_to_top(a, min_value);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	return ;
}

void	sort_five(t_node **a, t_node **b)
{
	int	min_value;

	min_value = find_min_value(*a);
	bring_min_to_top(a, min_value);
	pb(a, b);
	min_value = find_min_value(*a);
	bring_min_to_top(a, min_value);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
	return ;
}
