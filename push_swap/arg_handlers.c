/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:19:00 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/20 21:24:22 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	for_arg_handler(char ***str, int *f, t_data *data)
{
	if ((*str)[data->j][data->i] < '0' || (*str)[data->j][data->i] > '9')
	{
		*f = 1;
		if ((*str)[data->j][data->i] == ' ')
			*f = 0;
		if ((*str)[data->j][data->i] == '-' || (*str)[data->j][data->i] == '+')
		{
			if (!ft_isdigit((*str)[data->j][data->i + 1]))
				data->midd++;
			if (((*str)[data->j][(data->i) - 1] == ' ') || data->i == 0)
				data->spy++;
			else
				data->midd++;
			*f = 0;
		}
	}
	data->i++;
}

void	loop_args(char **str, int *found, int *digit)
{
	t_data	v;

	v.j = 1;
	v.midd = 0;
	v.spy = 0;
	v.i = 0;
	while (str[v.j])
	{
		v.i = 0;
		v.spy = 0;
		*digit = 0;
		while (str[v.j][v.i] && str[v.j][v.i] != '\0')
		{
			if (ft_isdigit(str[v.j][v.i]))
				*digit = 1;
			for_arg_handler(&str, found, &v);
		}
		if (!*digit || v.midd != 0)
			ft_print_err();
		v.j++;
	}
}

int	arg_handlers(int total, char **str)
{
	int	found;
	int	digit;

	digit = 0;
	found = 0;
	if (total == 1)
		exit(0);
	check_arg(str);
	loop_args(str, &found, &digit);
	if (found)
		return (1);
	return (0);
}
