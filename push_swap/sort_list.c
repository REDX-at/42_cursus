/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:25:43 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/23 18:27:25 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsizet(t_swap *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	check_if_sorted(t_swap **stack)
{
	int		flag;
	t_swap	*head;

	head = *stack;
	flag = 0;
	if (!stack || !*stack)
	{
		ft_putstr_fd("Error\n", 2);
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

void	sort_three(t_swap **a)
{
	t_swap	*ls;
	int		size;

	size = ft_lstsizet(*a);
	ls = ft_lstlastt(*a);
	if (!a || !*a)
		exit(0);
	if (!check_if_sorted(a) && size == 3)
	{
		if ((*a)->content < (*a)->next->content
			&& (*a)->content < ls->content)
			case_one(a);
		else if ((*a)->content > (*a)->next->content
			&& (*a)->content < ls->content)
			case_two(a);
		else if ((*a)->content < (*a)->next->content
			&& (*a)->content > ls->content)
			case_three(a);
		else if ((*a)->content > (*a)->next->content
			&& (*a)->content > ls->content && (*a)->next->content < ls->content)
			case_four(a);
		else if ((*a)->content > (*a)->next->content
			&& (*a)->content > ls->content && (*a)->next->content > ls->content)
			case_five(a);
	}
}

void	move_to_top(t_swap **a, t_swap **b, t_swap	*t_p)
{
	while ((*a) && (*b) && ((t_p) != (*b)) && ((t_p)->target_node != (*a))
		&& ((t_p)->above_median) && ((t_p)->target_node->above_median))
		rotate_a_b(a, b);
	while ((*a) && (*b) && ((t_p) != (*b)) && ((t_p)->target_node != (*a))
		&& !((t_p)->above_median) && !((t_p)->target_node->above_median))
		reverse_rotate_a_b(a, b);
	while ((*b) && (t_p) != (*b))
	{
		if ((t_p)->above_median)
			rotate_b((b), 1);
		else
			reverse_rotate_b((b), 1);
	}
	while ((*a) && (t_p)->target_node != (*a))
	{
		if ((t_p)->target_node->above_median)
			rotate_a((a), 1);
		else
			reverse_rotate_a((a), 1);
	}
	push_a(a, b);
}

void	sort_turk(t_swap **stack_a, t_swap **stack_b)
{
	int	size_list;
	int	med;
	int	size;
	int	min;

	size = 0;
	min = find_min(stack_a);
	med = get_med(stack_a);
	size_list = ft_lstsizet(*stack_a);
	if (check_if_sorted(stack_a))
		exit(0);
	size = size_list;
	first_step(stack_a, stack_b, &size, &med);
	push_back(stack_a, stack_b);
}
