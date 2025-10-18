/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:37:37 by lucho             #+#    #+#             */
/*   Updated: 2025/10/18 15:35:09 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		value;
	t_node	*stack_a;
	t_node	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (!validate_arg_str(argv[i], &value, stack_a))
		{
			ft_free(&stack_a);
			return (1);
		}
		ft_fill_stack(&stack_a, value);
		i++;
	}
	sort_dispatcher(&stack_a, &stack_b);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
