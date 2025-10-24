/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:44:49 by lucho             #+#    #+#             */
/*   Updated: 2025/10/24 14:26:21 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

// ───────────────────────────────
// Commands
// ───────────────────────────────

void	ft_push(t_node **dest, t_node **src);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ft_reverse_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	ft_rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	ft_swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

// ───────────────────────────────
// Utils
// ───────────────────────────────

int		find_min_value(t_node *stack);
void	sort_dispatcher(t_node **stack_a, t_node **stack_b);
void	ft_free(t_node **stack);
int		ft_isdigit(int c);

// ───────────────────────────────
// Index
// ───────────────────────────────

int		get_position_of_index(t_node *stack, int index);
int		*stack_to_temp_array(t_node *stack, int size);
void	internal_sorting(int *array, int size);
void	assign_index(t_node *stack);

// ───────────────────────────────
// Sorting algorithm
// ───────────────────────────────

int		already_sorted(t_node *stack);
void	sort_two(t_node **stack_a);
void	sort_three_actions(t_node **stack_a, int first, int second, int third);
void	sort_three(t_node **stack_a);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_five(t_node **a, t_node **b);
void	push_chunks_to_b(t_node **stack_a, t_node **stack_b);
void	push_back_to_a(t_node **stack_a, t_node **stack_b);

// ───────────────────────────────
// Parsing and stack handling
// ───────────────────────────────

int		is_valid_number(const char *str);
int		convert_and_check_range(const char *str, int *out_value);
int		validate_arg_str(const char *str, int *value, t_node *stack);
int		ft_stack_size(t_node *stack);
int		ft_fill_stack(t_node **stack, int value);
void	rotate_to_top(t_node **stack, int index, char stack_name);
void	bring_to_top(t_node **stack, int index, char stack_name);
void	bring_min_to_top(t_node **stack, int min_index);
int		get_cheapest_index(t_node *stack, int min, int max);
int		find_max_index(t_node *stack);

#endif
