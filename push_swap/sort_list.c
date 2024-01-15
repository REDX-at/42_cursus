/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:25:43 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/16 00:23:31 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsizet(t_swap *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int check_if_sorted(t_swap **stack)
{
	int flag;
	t_swap *head = *stack;
	flag = 0;
	if (!stack || !*stack)
	{
		ft_printf("Error\n");
		exit(0);
	}
	while (*stack && (*stack)->next)
	{
		if ((*stack)->content > (*stack)->next->content)
			flag = 1;
		*stack = (*stack)->next;
	}
	*stack = head;
	if (flag)
		return (0);
	return (1);
}

void	sort_three(t_swap **stack)
{
	t_swap	*last;
	int		size;

	size = ft_lstsizet(*stack);
	last = ft_lstlastt(*stack);
	if (!stack || !*stack)
	{
		ft_printf("test 3\n");
		exit(0);
	}
	if (!check_if_sorted(stack) && size == 3)
	{
		if ((*stack)->content < (*stack)->next->content && (*stack)->content < last->content)
			case_one(stack);
		else if ((*stack)->content > (*stack)->next->content && (*stack)->content < last->content)
			case_two(stack);
		else if ((*stack)->content < (*stack)->next->content && (*stack)->content > last->content)
			case_three(stack);
		else if ((*stack)->content > (*stack)->next->content && (*stack)->content > last->content && (*stack)->next->content < last->content)
			case_four(stack);
		else if ((*stack)->content > (*stack)->next->content && (*stack)->content > last->content && (*stack)->next->content > last->content)
			case_five(stack);
		ft_printf("\n");
	}
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
		temp->index= i;
		if (i <= med)
			temp->above_median = true;
		else
			temp->above_median= false;
		temp = temp->next;
		i++;
	}
}

void	fin_cheap(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*temp_b = *stack_b;
	index_target(&temp_b);
	while (temp_b)
	{
		if (temp_b->above_median)
			temp_b->cheapest_move = temp_b->index;
		else
			temp_b->cheapest_move = ft_lstsizet(*stack_b) - temp_b->index;
		ft_printf("cheap b  : %d\n", temp_b->cheapest_move);
		temp_b = temp_b->next;
	}
	t_swap	*temp_a = *stack_a;
	index_target(&temp_a);
	while (temp_a)
	{
		if (temp_a->above_median)
			temp_a->cheapest_move = temp_a->index;
		else
			temp_a->cheapest_move = ft_lstsizet(*stack_a) - temp_a->index;
		ft_printf("cheap a  : %d\n", temp_a->cheapest_move);
		temp_a = temp_a->next;
	}
}

void	sort_turk(t_swap **stack_a, t_swap **stack_b)
{
	int	size_list;
	int	med;
	int	size = 0;

	med = get_med(stack_a);
	size_list = ft_lstsizet(*stack_a);
	if (check_if_sorted(stack_a))
	{
		ft_printf("sorted\n");
		exit(0);
	}
	size = size_list;
	while (size > 3 && *stack_a)
	{
		if ((*stack_a)->content > med)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
		else
			push_b(stack_a, stack_b);
		size--;
	}
	fin_cheap(stack_a, stack_b);
	if (size == 3)
		sort_three(stack_a);
}
