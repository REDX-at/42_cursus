/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_turk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:28:22 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/20 21:55:13 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fin_cheap(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*temp_b;
	t_swap	*temp_a;

	temp_b = *stack_b;
	index_target(&temp_b);
	while (temp_b)
	{
		if (temp_b->above_median)
			temp_b->cheapest_move = temp_b->index;
		else
			temp_b->cheapest_move = ft_lstsizet(*stack_b) - temp_b->index;
		temp_b = temp_b->next;
	}
	temp_a = *stack_a;
	index_target(&temp_a);
	while (temp_a)
	{
		if (temp_a->above_median)
			temp_a->cheapest_move = temp_a->index;
		else
			temp_a->cheapest_move = ft_lstsizet(*stack_a) - temp_a->index;
		temp_a = temp_a->next;
	}
}

void	find_target(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*temp_b;
	t_swap	*temp_a;
	long	match;

	temp_b = *stack_b;
	while (temp_b)
	{
		temp_a = *stack_a;
		match = (long)INT_MAX + 1;
		while (temp_a)
		{
			if (temp_a->content > temp_b->content && temp_a->content < match)
			{
				match = temp_a->content;
				temp_b->target_node = temp_a;
			}
			if (match == (long)INT_MAX + 1)
			{
				temp_b->target_node = find_minswap(stack_a);
			}
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}

void	get_cheapest_cost(t_swap **stack_b)
{
	t_swap	*temp_b;

	temp_b = *stack_b;
	while (temp_b)
	{
		temp_b->cheapest_cost = temp_b->cheapest_move
			+ temp_b->target_node->cheapest_move;
		temp_b = temp_b->next;
	}
}

t_swap	*find_cheap_cost(t_swap **stack_b)
{
	t_swap	*cheap;
	t_swap	*temp_b;
	int		cheapest;

	temp_b = *stack_b;
	cheap = temp_b;
	cheapest = INT_MAX;
	while (temp_b)
	{
		if (temp_b)
		{
			if (temp_b->cheapest_cost < cheapest)
			{
				cheapest = temp_b->cheapest_cost;
				cheap = temp_b;
			}
		}
		temp_b = temp_b->next;
	}
	return (cheap);
}

void	index_target(t_swap **stack)
{
	t_swap	*temp;
	int		i;
	int		med;

	med = ft_lstsizet(*stack) / 2;
	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->index = i;
		if (i <= med)
			temp->above_median = true;
		else
			temp->above_median = false;
		temp = temp->next;
		i++;
	}
}
