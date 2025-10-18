/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fill_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:46:49 by luimarti          #+#    #+#             */
/*   Updated: 2025/10/18 17:48:21 by luimarti         ###   ########.fr       */
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
