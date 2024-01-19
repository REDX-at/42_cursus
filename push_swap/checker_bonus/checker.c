/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:31:54 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/19 22:55:35 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_stacks(t_swap	**stack_a, t_swap **stack_b, char *buffer)
{
	ft_free_stack_a(stack_a);
	ft_free_stack_b(stack_b);
	free(buffer);
	exit(0);
}

int	check_if_sorted(t_swap **stack)
{
	int		flag;
	t_swap	*head;

	head = *stack;
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

int	join(char	*line, char	**buffer)
{
	if (!ft_strncmp("sa\n", line, 3))
		*buffer = ft_strjoin(*buffer, "sa\n");
	else if (!ft_strncmp("sb\n", line, 3))
		*buffer = ft_strjoin(*buffer, "sb\n");
	else if (!ft_strncmp("ss\n", line, 3))
		*buffer = ft_strjoin(*buffer, "ss\n");
	else if (!ft_strncmp("pa\n", line, 3))
		*buffer = ft_strjoin(*buffer, "pa\n");
	else if (!ft_strncmp("pb\n", line, 3))
		*buffer = ft_strjoin(*buffer, "pb\n");
	else if (!ft_strncmp("ra\n", line, 3))
		*buffer = ft_strjoin(*buffer, "ra\n");
	else if (!ft_strncmp("rb\n", line, 3))
		*buffer = ft_strjoin(*buffer, "rb\n");
	else if (!ft_strncmp("rra\n", line, 4))
		*buffer = ft_strjoin(*buffer, "rra\n");
	else if (!ft_strncmp("rrb\n", line, 4))
		*buffer = ft_strjoin(*buffer, "rrb\n");
	else if (!ft_strncmp("rr\n", line, 3))
		*buffer = ft_strjoin(*buffer, "rr\n");
	else if (!ft_strncmp("rrr\n", line, 4))
		*buffer = ft_strjoin(*buffer, "rrr\n");
	else
		return (1);
	return (0);
}

void	make_it(char *handler, t_swap **stack_a, t_swap **stack_b)
{
	if (!ft_strncmp("sa", handler, 2))
		checker_swap_a(*stack_a);
	else if (!ft_strncmp("sb", handler, 2))
		checker_swap_b(*stack_b);
	else if (!ft_strncmp("ss", handler, 2))
		checker_swap_a_b(*stack_a, *stack_a);
	else if (!ft_strncmp("pa", handler, 2))
		checker_push_a(stack_a, stack_b);
	else if (!ft_strncmp("pb", handler, 2))
		checker_push_b(stack_a, stack_b);
	else if (!ft_strncmp("ra", handler, 2))
		checker_rotate_a(stack_a);
	else if (!ft_strncmp("rb", handler, 2))
		checker_rotate_b(stack_b);
	else if (!ft_strncmp("rra", handler, 3))
		checker_reverse_rotate_a(stack_a);
	else if (!ft_strncmp("rrb", handler, 3))
		checker_reverse_rotate_b(stack_b);
	else if (!ft_strncmp("rr", handler, 2))
		checker_rotate_a_b(stack_a, stack_b);
	else if (!ft_strncmp("rrr", handler, 3))
		checker_reverse_rotate_a_b(stack_a, stack_b);
}

void	f(void)
{
	system("leaks push_swap_bonus");
}
int	main(int argc, char **argv)
{
	int		arg_valid;
	char	*line;
	char	*buffer;
	char	**handler;
	t_swap	*stack_a;
	t_swap	*stack_b = NULL;

	atexit(f);
	buffer = ft_strdup("");
	arg_valid = arg_handlers_bonus(argc, argv);
	if (arg_valid)
		ft_print_err();
	stack_a = create_list(argv, 1, 0);
	check_duplicate(stack_a);
	if (check_if_sorted(&stack_a))
	{
		ft_printf("sorted\n");
		free_stacks(&stack_a, &stack_a, buffer);
	}
	line = get_next_line(0);
	while (line)
	{
		if(join(line, &buffer))
			free_stacks(&stack_a, &stack_a, buffer);
		free(line);
		line = get_next_line(0);
	}
	handler = ft_split(buffer, '\n');
	if (!handler)
		free_stacks(&stack_a, &stack_a, buffer);
	int i = 0;
	while (handler[i])
	{
		make_it(handler[i], &stack_a, &stack_b);
		free(handler[i]);
		i++;
	}
	if (check_if_sorted(&stack_a) && !stack_b)
	{
		ft_printf("OK\n");
		free_stacks(&stack_a, &stack_a, buffer);
	}
	ft_printf("KO\n");
	free_stacks(&stack_a, &stack_a, buffer);
}
