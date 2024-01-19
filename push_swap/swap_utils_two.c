/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:16 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/19 19:26:33 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_swap **stack_a, int flag)
{
	t_swap	*last;
	t_swap	*second_last;

	last = *stack_a;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	while (last->next->next != NULL)
		last = last->next;
	second_last = last;
	last = last->next;
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (flag != 0)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_swap **stack_b, int flag)
{
	t_swap	*last;
	t_swap	*second_last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	while (last->next->next != NULL)
		last = last->next;
	second_last = last;
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

void	push_a(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*new_node;
	t_swap	*temp;

	if (*stack_b && stack_a)
	{
		new_node = (t_swap *)malloc(sizeof(t_swap));
		if (!new_node)
			return ;
		new_node->content = (*stack_b)->content;
		new_node->next = *stack_a;
		*stack_a = new_node;
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(temp);
		ft_printf("pa\n");
	}
}
