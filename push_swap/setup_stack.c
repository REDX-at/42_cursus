/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:45:07 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/19 22:04:58 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (!res)
		{
			free(res);
			exit(0);
		}
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
