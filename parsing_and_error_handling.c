/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_error_handling.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:37:53 by lucho             #+#    #+#             */
/*   Updated: 2025/10/18 16:24:51 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// (INCLUIR MI LIBFT PARA EL ISDIGIT!!!)

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	convert_and_check_range(const char *str, int *out_value)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		i = 1;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result > (long)INT_MAX + 1))
			return (0);
		i++;
	}
	*out_value = (int)(sign * result);
	return (1);
}

int	validate_arg_str(const char *str, int *value, t_node *stack)
{
	if (!str || !value)
	{
		write(2, "🚫 Invalid input pointer!\n", 26);
		return (0);
	}
	if (!is_valid_number(str))
	{
		write(2, "❌ Not a valid number format!\n", 31);
		return (0);
	}
	if (!convert_and_check_range(str, value))
	{
		write(2, "📉 Number out of range!\n", 27);
		return (0);
	}
	while (stack)
	{
		if (stack->value == *value)
		{
			write(2, "♻️  Duplicate value detected!\n", 34);
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}
