/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:36:42 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/16 22:25:10 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(t_swap **stack_a)
{
	if (!stack_a || !*stack_a)
		return (0);

	int min = (*stack_a)->content;
	t_swap *current = *stack_a;

	while (current->next)
	{
		if (current->next->content < min)
			min = current->next->content;
		current = current->next;
	}

	return (min);
}
t_swap *find_minswap(t_swap **stack_a)
{
	if (!stack_a || !*stack_a)
		return (NULL);
	t_swap	*min_node = (*stack_a);
	int min = (*stack_a)->content;
	t_swap *current = *stack_a;

	while (current)
	{
		if (current->next)
		{
			if (current->content < min)
			{
				min = current->content;
				min_node = current;
				ft_printf("min : %d\n", min);
			}
		}
		current = current->next;
	}
	// ft_printf("min : %d\n", min_node->content);
	return (min_node);
}

int find_max(t_swap **stack_a)
{
	if (!stack_a || !*stack_a)
		return (0);

	int max = (*stack_a)->content;
	t_swap *current = *stack_a;

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

