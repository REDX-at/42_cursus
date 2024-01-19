/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:36:42 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/19 18:59:41 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_swap **stack_a)
{
	int		min;
	t_swap	*current;

	if (!stack_a || !*stack_a)
		return (0);
	min = (*stack_a)->content;
	current = *stack_a;
	while (current->next)
	{
		if (current->next->content < min)
			min = current->next->content;
		current = current->next;
	}
	return (min);
}

t_swap	*find_minswap(t_swap **stack_a)
{
	t_swap	*min_node;
	t_swap	*current;

	if (!stack_a || !*stack_a)
		return (NULL);
	min_node = *stack_a;
	current = (*stack_a)->next;
	while (current)
	{
		if (current->content < min_node->content)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

int	find_max(t_swap **stack_a)
{
	t_swap	*current;
	int		max;

	max = (*stack_a)->content;
	current = *stack_a;
	if (!stack_a || !*stack_a)
		return (0);
	while (current->next)
	{
		if (current->next->content > max)
			max = current->next->content;
		current = current->next;
	}
	return (max);
}

int	get_med(t_swap **stack_a)
{
	int	med;
	int	min;
	int	max;

	min = find_min(stack_a);
	max = find_max(stack_a);
	med = (max + min) / 2;
	return (med);
}
