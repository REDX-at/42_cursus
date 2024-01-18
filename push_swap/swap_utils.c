/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:17:45 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/18 22:55:46 by aitaouss         ###   ########.fr       */
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
	ft_printf("sa\n");
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
	if (i < 1)
	{
		return;
	}
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
	ft_printf("sb\n");
}

void	swap_a_b(t_swap *stack_a, t_swap *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_printf("ss\n");
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
		ft_printf("pb\n");
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
		ft_printf("pa\n");
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

void	rotate_a(t_swap **stack_a, int flag)
{
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	t_swap *last = ft_lstlastt(*stack_a);
	t_swap *temp = NULL;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	last->next = temp;
	if (flag != 0)
		ft_printf("ra\n");
}

void	rotate_b(t_swap **stack_b, int flag)
{
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	t_swap *last = ft_lstlastt(*stack_b);
	t_swap *temp = NULL;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	last->next = temp;
	if (flag != 0)
		ft_printf("rb\n");
}

void	rotate_a_b(t_swap **stack_a, t_swap **stack_b)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	ft_printf("rr\n");
}

void reverse_rotate_a(t_swap **stack_a, int flag)
{
    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    t_swap *last = *stack_a;
    while (last->next->next != NULL)
        last = last->next;
    t_swap *second_last = last;
    last = last->next;
    second_last->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
	if (flag != 0)
		ft_printf("rra\n");
}

void reverse_rotate_b(t_swap **stack_b, int flag)
{
    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    t_swap *last = *stack_b;
    while (last->next->next != NULL)
        last = last->next;
    t_swap *second_last = last;
    last = last->next;
    second_last->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
	if (flag != 0)
		ft_printf("rrb\n");
}

void	reverse_rotate_a_b(t_swap **stack_a, t_swap **stack_b)
{
	reverse_rotate_a(stack_a, 0);
	reverse_rotate_b(stack_b, 0);
	ft_printf("rrr\n");
}
