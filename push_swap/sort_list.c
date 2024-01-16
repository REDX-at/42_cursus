/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:25:43 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/16 22:35:07 by aitaouss         ###   ########.fr       */
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
		exit(0);
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
	int	d = 1;
	while (temp_b)
	{
		if (temp_b->above_median)
		{
			temp_b->cheapest_move = temp_b->index;
			// ft_printf("cheap : %d %d\n", temp_b->cheapest_move, d);
		}
		else
		{
			temp_b->cheapest_move = ft_lstsizet(*stack_b) - temp_b->index;
			// ft_printf("cheap : %d %d\n", temp_b->cheapest_move, d);
		}
		temp_b = temp_b->next;
	}
	d = 2;
	t_swap	*temp_a = *stack_a;
	index_target(&temp_a);
	while (temp_a)
	{
		if (temp_a->above_median)
			temp_a->cheapest_move = temp_a->index;
		else
			temp_a->cheapest_move = ft_lstsizet(*stack_a) - temp_a->index;
		temp_a = temp_a->next;
	}
}

void	find_target(t_swap **stack_a, t_swap **stack_b)
{
	t_swap	*temp_b;
	t_swap	*temp_a;
	int		target = 0;
	int		flag = 0;
	
	temp_b = *stack_b;
	temp_a = *stack_a;
	while (temp_b)
	{	
		t_swap	*min = find_minswap(stack_a);
		temp_a = *stack_a;
		flag = 0;
		while (temp_a)
		{
			if (temp_a->content > temp_b->content)
			{
				if (!flag)
				{
					temp_b->target_node = temp_a;
					target = temp_a->content;
				}
				else
				{
					if (temp_a->content < target)
					{
						temp_b->target_node = temp_a;
						target = temp_a->content;
					}
				}
				flag = 1;
			}
			else
				temp_b->target_node = min;
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
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
	if (size == 3)
		sort_three(stack_a);
	fin_cheap(stack_a, stack_b);
	find_target(stack_a, stack_b);
}
