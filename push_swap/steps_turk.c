/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_turk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:33:41 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/23 21:26:00 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_step(t_swap **stack_a, t_swap **stack_b, int *size, int *med)
{
	while (*size > 3 && *stack_a)
	{
		if ((*stack_a)->content > *med)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b, 1);
		}
		else
			push_b(stack_a, stack_b);
		(*size)--;
	}
	if (*size == 3)
		sort_three(stack_a);
}

void	push_back(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*to_push;

	while (*stack_b)
	{
		index_target(stack_b);
		index_target(stack_a);
		fin_cheap(stack_a, stack_b);
		find_target(stack_a, stack_b);
		get_cheapest_cost(stack_b);
		to_push = find_cheap_cost(stack_b);
		move_to_top(stack_a, stack_b, to_push);
	}
	finish_stack(stack_a);
}

void	finish_stack(t_swap **stack_a)
{
	t_swap	*min;

	min = find_minswap(stack_a);
	index_target(stack_a);
	while (*stack_a && min != (*stack_a))
	{
		if (min->above_median)
			rotate_a(stack_a, 1);
		else
			reverse_rotate_a(stack_a, 1);
	}
}
