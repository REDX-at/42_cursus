/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:54:00 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/16 22:43:26 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_free_stack_a(t_swap **stack_a)
{
	t_swap *tmp;
	while (*stack_a)
	{
		// ft_printf("cheap : %d\n", (*stack_a)->cheapest_move);
		ft_printf("%d\n", (*stack_a)->content);
		tmp = (*stack_a)->next;
		// free(*stack_a);
		*stack_a = tmp;
	}
	ft_printf("-\na\n");
	ft_printf("-------------------\n");
}

void	ft_free_stack_b(t_swap **stack_b)
{
	t_swap *tmp;
	while (*stack_b)
	{
		if ((*stack_b)->target_node)
		{
			ft_printf("target : %d\n", (*stack_b)->target_node->content);
			ft_printf("cheap target : %d\n", (*stack_b)->target_node->cheapest_move);
		}
		ft_printf("cheap : %d\n", (*stack_b)->cheapest_move);
		ft_printf("%d\n", (*stack_b)->content);
		tmp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = tmp;
	}
	ft_printf("-\nb\n");
	ft_printf("-------------------\n");
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

void	setup_list(t_swap **new_node, t_swap **head, int *content, t_swap **current)
{
	*new_node = new_list(*content);
	if (!*new_node)
	{
		ft_printf("new_node\n");
		exit(0);
	}
	if (!*head)
	{
		*head = *new_node;
		*current = *head;
	}
	else
	{
		(*current)->next = *new_node;
		(*new_node)->prev = *current;
		*current = *new_node;
	}
}

t_swap *create_list(char **str)
{
	t_swap *head;
	t_swap *current;
 	t_swap *new_node;
	char	**res;
	int	content;
	int i;
	int	d;

	i = 1;
	head = NULL;
	current = NULL;
	new_node = NULL;
	content = 0;
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

int check_duplicate(const t_swap *list)
{
	const t_swap *current;

	current = list;
	while (current)
	{
		const t_swap *temp = current->next;
		while (temp)
		{
			if (current->content == temp->content)
			{
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}

void	f()
{
	system("leaks push_swap");
}

int main(int argc, char **argv)
{
	t_swap	*stack_a = NULL;
	t_swap	*stack_b = NULL;

	int arg_valid = arg_handlers(argc, argv);
	if (arg_valid)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	stack_a = create_list(argv);
	check_duplicate(stack_a);
	// push_b(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// push_b(&stack_a, &stack_b);
	// check_above_median(&stack_a, &stack_b);
	// while (stack_b)
	// {
	// 	index_target(&stack_b);
	// 	if (stack_b->above_median)
	// 		ft_printf("signe\n");
	// 	stack_b = stack_b->next;
	// }
	sort_turk(&stack_a, &stack_b);
	// t_swap	*min = find_minswap(&stack_a);
	// ft_printf("min : %d\n", min->content);
	// reverse_rotate_a(&stack_a);
	ft_free_stack_a(&stack_a);
	ft_free_stack_b(&stack_b);
	return 0;
}



