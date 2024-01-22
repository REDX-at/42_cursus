/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:17:45 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/20 18:10:02 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	checker_swap_b(t_swap *stack)
{
	int		tmp;
	t_swap	*head;
	int		i;

	if (!stack)
		return ;
	head = NULL;
	i = 0;
	tmp = 0;
	head = stack;
	while (stack)
	{
		stack = (stack)->next;
		i++;
	}
	stack = head;
	if (i <= 1)
		return ;
	tmp = (stack)->content;
	(stack)->content = (stack)->next->content;
	stack = (stack)->next;
	(stack)->content = tmp;
}

void	checker_swap_a(t_swap *stack)
{
	int		tmp;
	t_swap	*head;
	int		i;

	if (!stack)
		return ;
	head = NULL;
	i = 0;
	tmp = 0;
	head = stack;
	while (stack)
	{
		stack = (stack)->next;
		i++;
	}
	stack = head;
	if (i <= 1)
		return ;
	tmp = (stack)->content;
	(stack)->content = (stack)->next->content;
	stack = (stack)->next;
	(stack)->content = tmp;
}

void	checker_swap_a_b(t_swap *stack_a, t_swap *stack_b)
{
	checker_swap_a(stack_a);
	checker_swap_b(stack_b);
}

void	checker_push_b(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*new_node;
	t_swap	*temp;

	if (*stack_a && stack_b)
	{
		new_node = (t_swap *)malloc(sizeof(t_swap));
		if (!new_node)
			return ;
		new_node->content = (*stack_a)->content;
		new_node->next = *stack_b;
		new_node->prev = NULL;
		if (*stack_b)
			(*stack_b)->prev = new_node;
		*stack_b = new_node;
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		if (*stack_a)
			(*stack_a)->prev = NULL;
		free(temp);
	}
}
