/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:17:45 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/08 01:21:20 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_swap *list)
{
	int tmp;
	t_swap *head = NULL;
	int i = 0;

	tmp = 0;
	head = list;
	while (list)
	{
		list = list->next;
		i++;
	}
	list = head;
	if (i <= 1)
		return ;
	if (list)
	{
		tmp = list->content;
		list->content = list->next->content;
		list = list->next;
		list->content = tmp;
	}
	else
		return ;
}

void	swap_b(t_swap *list)
{
	int tmp;

	tmp = 0;
	if (list)
	{
		tmp = list->content;
		list->content = list->next->content;
		list = list->next;
		list->content = tmp;
	}
	else
		return ;
}

void	swap_a_b(t_swap *stack_a, t_swap *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	push_b(t_swap *stack_a, t_swap *stack_b)
{
	if (stack_a && stack_b)
	{
		ft_printf("stack b : %d\n", stack_b->content);
		stack_b->content = stack_a->content;
	}
	return ;
}

void	rotate_a(t_swap *stack_a)
{
	t_swap	*current = stack_a;
	t_swap *last = NULL;
	t_swap *test = NULL;
	int tmp;

	last = create_empty_stack();
	while (current)
	{
		last->content = current->content;
		if (current->next == NULL)
			test = current;
		current = current->next;
	}
	tmp = stack_a->content;
	stack_a->content = last->content;
	stack_a = test;
	stack_a->content = tmp;
}

void	rotate_b(t_swap *stack_b)
{
	t_swap	*current = stack_b;
	t_swap *last = NULL;
	t_swap *test = NULL;
	int tmp;

	last = create_empty_stack();
	while (current)
	{
		last->content = current->content;
		if (current->next == NULL)
			test = current;
		current = current->next;
	}
	tmp = stack_b->content;
	stack_b->content = last->content;
	stack_b = test;
	stack_b->content = tmp;
}

void	rotate_a_b(t_swap *stack_a, t_swap *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}