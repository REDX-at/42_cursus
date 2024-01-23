/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:31:54 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/23 20:16:03 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	for_join(char **tmp, char **line, char **buffer, int *flag)
{
	if (!ft_strncmp("sa\n", *line, 3))
		*tmp = ft_strjoin(*buffer, "sa\n");
	else if (!ft_strncmp("sb\n", *line, 3))
		*tmp = ft_strjoin(*buffer, "sb\n");
	else if (!ft_strncmp("ss\n", *line, 3))
		*tmp = ft_strjoin(*buffer, "ss\n");
	else if (!ft_strncmp("pa\n", *line, 3))
		*tmp = ft_strjoin(*buffer, "pa\n");
	else if (!ft_strncmp("pb\n", *line, 3))
		*tmp = ft_strjoin(*buffer, "pb\n");
	else if (!ft_strncmp("ra\n", *line, 3))
		*tmp = ft_strjoin(*buffer, "ra\n");
	else if (!ft_strncmp("rb\n", *line, 3))
		*tmp = ft_strjoin(*buffer, "rb\n");
	else if (!ft_strncmp("rra\n", *line, 4))
		*tmp = ft_strjoin(*buffer, "rra\n");
	else if (!ft_strncmp("rrb\n", *line, 4))
		*tmp = ft_strjoin(*buffer, "rrb\n");
	else if (!ft_strncmp("rrr\n", *line, 4))
		*tmp = ft_strjoin(*buffer, "rrr\n");
	else if (!ft_strncmp("rr\n", *line, 3))
		*tmp = ft_strjoin(*buffer, "rr\n");
	else
		*flag = 1;
}

int	join(char *line, char **buffer)
{
	char	*tmp;
	int		flag;

	flag = 0;
	for_join(&tmp, &line, buffer, &flag);
	if (tmp == NULL || flag == 1)
		return (1);
	free(*buffer);
	*buffer = tmp;
	return (0);
}

void	make_it(char *handler, t_swap **stack_a, t_swap **stack_b)
{
	if (!ft_strncmp("sa", handler, 2))
		checker_swap_a(*stack_a);
	else if (!ft_strncmp("sb", handler, 2))
		checker_swap_b(*stack_b);
	else if (!ft_strncmp("ss", handler, 2))
	{
		checker_swap_a(*stack_a);
		checker_swap_b(*stack_b);
	}
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
	else if (!ft_strncmp("rrr", handler, 3))
		checker_reverse_rotate_a_b(stack_a, stack_b);
	else if (!ft_strncmp("rr", handler, 2))
		checker_rotate_a_b(stack_a, stack_b);
}

void	checker_steps(t_swap **stack_a, t_swap **stack_b, char **buffer)
{
	char	*line;
	char	**handler;
	int		i;

	line = get_next_line(0);
	while (line)
	{
		if (join(line, buffer))
			ft_print_err();
		free(line);
		line = get_next_line(0);
	}
	handler = ft_split(*buffer, '\n');
	if (!handler)
		exit(0);
	i = 0;
	while (handler[i])
	{
		make_it(handler[i], stack_a, stack_b);
		i++;
	}
	if (check_if_sorted(stack_a) && !*stack_b)
		print_ok_ko(1);
	ft_printf("KO\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	int		valid;
	char	*buffer;
	t_swap	*stack_a;
	t_swap	*stack_b;

	stack_b = NULL;
	buffer = ft_strdup("");
	valid = arg_handlers_bonus(argc, argv);
	if (valid)
		ft_print_err();
	stack_a = create_list(argv, 1, 0);
	check_duplicate(stack_a);
	checker_steps(&stack_a, &stack_b, &buffer);
}
