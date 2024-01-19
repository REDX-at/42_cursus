/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:35:37 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/19 22:47:02 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	setup_list(t_swap **new, t_swap **hea, int *c, t_swap **curr)
{
	*new = new_list(*c);
	if (!*new)
		exit(0);
	if (!*hea)
	{
		*hea = *new;
		*curr = *hea;
	}
	else
	{
		(*curr)->next = *new;
		(*new)->prev = *curr;
		*curr = *new;
	}
}

void	init_stack(t_swap **h, t_swap **c, int *con, t_swap **n_d)
{
	*h = NULL;
	*c = NULL;
	*n_d = NULL;
	*con = 0;
}

t_swap	*create_list(char **str, int i, int d)
{
	t_swap	*head;
	t_swap	*current;
	t_swap	*new_node;
	char	**res;
	int		content;

	i = 1;
	init_stack(&head, &current, &content, &new_node);
	while (str[i] != NULL)
	{
		d = 0;
		res = ft_split(str[i], ' ');
		while (res[d])
		{
			content = ft_atoi(res[d]);
			setup_list(&new_node, &head, &content, &current);
			free(res[d]);
			d++;
		}
		i++;
		free(res);
	}
	return (head);
}

t_swap	*new_list(int content)
{
	t_swap	*new_node;

	new_node = (t_swap *)malloc(sizeof(t_swap));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_free_stack_a(t_swap **stack_a)
{
	t_swap	*tmp;

	while (*stack_a)
	{
		ft_printf("%d\n", (*stack_a)->content);
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
		ft_printf("%d\n", (*stack_b)->content);
		tmp = (*stack_b)->next;
		*stack_b = tmp;
	}
}