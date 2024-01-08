/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:54:00 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/08 01:19:56 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_number(int *arr)
{
	int r = 0;
	int j = 0;
	int x = 0;
	int tmp = 0;
	while (r < j - 1)
	{
		x = 0;
		while (x < j - 1 - r)
		{
			if (arr[x] > arr[x + 1])
			{
				tmp = arr[x];
				arr[x] = arr[x + 1];
				arr[x + 1] = tmp;
			}
			x++;
		}
		r++;
	}
	j = 0;
	while (j < r)
	{
		ft_printf("%d\n", arr[j]);
		j++;
	}
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

t_swap *create_list(char **str)
{
	t_swap *head = NULL;
	t_swap *current = NULL;
 	t_swap *new_node = NULL;
	int i = 1;
	while (str[i])
	{
		int content = atoi(str[i]);
		new_node = new_list(content);
		if (!new_node)
			return NULL;
		if (!head)
		{
			head = new_node;
			current = head;
		}
		else
		{
			current->next = new_node;
			new_node->prev = current;
			current = new_node;
		}
		i++;
	}
	return head;
}

t_swap *create_empty_stack() {
    t_swap *new_stack = (t_swap *)malloc(sizeof(t_swap));
    if (new_stack == NULL) {
        return NULL;
    }
    new_stack->content = 0;
    new_stack->next = NULL;
    return new_stack;
}

int check_duplicate(const t_swap *list)
{
	const t_swap *current = list;

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

	return 0;
}

int main(int argc, char **argv)
{
	t_swap	*stack_a = NULL;
	t_swap	*stack_b = NULL;
	int d = arg_handlers(argc, argv);
	if (d == 1)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	stack_a = create_list(argv);
	stack_b = create_empty_stack();
	check_duplicate(stack_a);
	//swap_a(stack_a);
	//swap_b(stack_b);
	//swap_a_b(stack_a, stack_b);
	//push_b(stack_a, stack_b);
	//rotate_a(stack_a);
	while (stack_b)
	{
		ft_printf("b : %d\n", stack_b->content);
		stack_b = stack_b->next;
	}
	ft_printf("-------------------\n");
	while (stack_a)
	{
		ft_printf("a : %d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("-\na\n");
	return 0;
}
