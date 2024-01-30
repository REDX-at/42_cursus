/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:31:21 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/20 21:23:11 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_ok_ko(int flag)
{
	if (flag == 1)
	{
		ft_printf("OK\n");
		exit(0);
	}
	ft_printf("KO\n");
	exit(0);
}

int	check_if_sorted(t_swap **stack)
{
	int		flag;
	t_swap	*head;

	head = *stack;
	flag = 0;
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

void	ft_free_stack_a(t_swap **stack_a)
{
	t_swap	*tmp;

	while (*stack_a)
	{
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
	}
}

void	ft_free_stack_b(t_swap **stack_b)
{
	t_swap	*tmp;

	while (*stack_b)
	{
		tmp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = tmp;
	}
}

void	check_arg(char **str)
{
	int	d;
	int	i;

	d = 1;
	i = 0;
	while (str[d] != NULL)
	{
		i = 0;
		while (str[d][i] != '\0')
		{
			if (!ft_isdigit(str[d][i]) && str[d][i] != ' ' && str[d][i] != '\t'
				&& str[d][i] != '-' && str[d][i] != '+')
				ft_print_err();
			i++;
		}
		d++;
	}
}
