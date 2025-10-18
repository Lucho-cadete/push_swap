/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 11:21:47 by lucho             #+#    #+#             */
/*   Updated: 2025/10/18 16:22:43 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position_of_index(t_node *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	*stack_to_temp_array(t_node *stack, int size)
{
	int	i;
	int	*array;

	i = 0;
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	while (stack && i < size)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (array);
}

void	internal_sorting(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array [j + 1];
				array [j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	assign_index(t_node *stack)
{
	int		i;
	int		size;
	int		*array;
	t_node	*to_assign_index;

	size = ft_stack_size(stack);
	array = stack_to_temp_array(stack, size);
	if (!array)
		return ;
	internal_sorting(array, size);
	to_assign_index = stack;
	while (to_assign_index)
	{
		i = 0;
		while (i < size && to_assign_index->value != array[i])
			i++;
		to_assign_index->index = i;
		to_assign_index = to_assign_index->next;
	}
	free (array);
}
