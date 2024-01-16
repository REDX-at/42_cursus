/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:17:45 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/16 22:41:03 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_swap *stack)
{
	int tmp;
	t_swap *head = NULL;
	int i = 0;

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
	if (stack)
	{
		tmp = (stack)->content;
		(stack)->content = (stack)->next->content;
		stack = (stack)->next;
		(stack)->content = tmp;
	}
	else
		return ;
}

void	check(t_swap *stack)
{
	int i = 0;
	t_swap	*head = NULL;
	
	head = stack;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	if (i <= 1)
		exit(0);
	stack = head;
}

void	swap_b(t_swap *list)
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

void	swap_a_b(t_swap *stack_a, t_swap *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void push_b(t_swap **stack_a, t_swap **stack_b)
{
    if (*stack_a && stack_b)
    {
        t_swap *new_node = (t_swap *)malloc(sizeof(t_swap));

        if (!new_node)
            return;
        new_node->content = (*stack_a)->content;
        new_node->next = *stack_b;
        new_node->prev = NULL;

        if (*stack_b)
            (*stack_b)->prev = new_node;
        *stack_b = new_node;
        t_swap *temp = *stack_a;
        *stack_a = (*stack_a)->next;
        if (*stack_a)
            (*stack_a)->prev = NULL;
        free(temp);
    }
}

void	push_a(t_swap **stack_a, t_swap **stack_b)
{
    if (*stack_b && stack_a)
    {
        t_swap *new_node = (t_swap *)malloc(sizeof(t_swap));

        if (!new_node)
            return;

        new_node->content = (*stack_b)->content;
        new_node->next = *stack_a;
        *stack_a = new_node;

        t_swap *temp = *stack_b;
        *stack_b = (*stack_b)->next;
        free(temp);
	}
}

t_swap	*ft_lstlastt(t_swap *lst)
{
	if (!lst)
		return (lst);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	rotate_a(t_swap **stack_a)
{
	check(*stack_a);
	t_swap *last = ft_lstlastt(*stack_a);
	t_swap *temp = NULL;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	last->next = temp;
}

void	rotate_b(t_swap **stack_b)
{
	check(*stack_b);
	t_swap *last = ft_lstlastt(*stack_b);
	t_swap *temp = NULL;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	last->next = temp;
}

void	rotate_a_b(t_swap *stack_a, t_swap *stack_b)
{
	rotate_a(&stack_a);
	rotate_b(&stack_b);
}

void	reverse_rotate_a(t_swap **stack_a)
{
	check(*stack_a);
	t_swap	*last = ft_lstlastt(*stack_a);
	t_swap *temp = *stack_a;
	last->prev->next = NULL;
	*stack_a = last;
	(*stack_a)->next = temp;
}

void	reverse_rotate_b(t_swap **stack_b)
{
	check(*stack_b);
	t_swap *last = ft_lstlastt(*stack_b);
	t_swap *temp = *stack_b;
	if (last->prev->next)
		last->prev->next = NULL;
	*stack_b = last;
	(*stack_b)->next = temp;
}

void	reverse_rotate_a_b(t_swap **stack_a, t_swap **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
