/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:52:29 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/19 19:08:21 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_swap **stack_a, int flag)
{
	t_swap	*temp;
	t_swap	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	last = ft_lstlastt(*stack_a);
	temp = NULL;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	last->next = temp;
	if (flag != 0)
		ft_printf("ra\n");
}

void	rotate_b(t_swap **stack_b, int flag)
{
	t_swap	*temp;
	t_swap	*last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	last = ft_lstlastt(*stack_b);
	temp = NULL;
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
