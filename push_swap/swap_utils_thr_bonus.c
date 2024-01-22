/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_thr_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:52:29 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/19 22:45:11 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	checker_rotate_a(t_swap **stack_a)
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
}

void	checker_rotate_b(t_swap **stack_b)
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
}

void	checker_rotate_a_b(t_swap **stack_a, t_swap **stack_b)
{
	checker_rotate_a(stack_a);
	checker_rotate_b(stack_b);
}
