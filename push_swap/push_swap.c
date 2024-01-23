/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:54:00 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/23 20:14:33 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		*stack_b = tmp;
	}
}

int	check_duplicate(t_swap *list)
{
	t_swap	*current;
	t_swap	*temp;

	current = list;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->content == temp->content)
				ft_print_err();
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
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
			if (!ft_isdigit(str[d][i]) && str[d][i] != ' '
				&& str[d][i] != '\t' && str[d][i] != '-' && str[d][i] != '+')
				ft_print_err();
			i++;
		}
		d++;
	}
}

int	main(int argc, char **argv)
{
	t_swap	*stack_a;
	t_swap	*stack_b;
	int		arg_valid;

	stack_a = NULL;
	stack_b = NULL;
	arg_valid = arg_handlers(argc, argv);
	if (arg_valid)
		ft_print_err();
	stack_a = create_list(argv, 1, 0);
	check_duplicate(stack_a);
	sort_turk(&stack_a, &stack_b);
	ft_free_stack_a(&stack_a);
	ft_free_stack_b(&stack_b);
	return (0);
}
