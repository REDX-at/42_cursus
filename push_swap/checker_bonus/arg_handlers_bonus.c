/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handlers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:19:00 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/19 20:55:19 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_print_err(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	for_arg_handler(char ***str, int *f, int *spy, int *i, int *j, int *m)
{
	if ((*str)[*j][*i] < '0' || (*str)[*j][*i] > '9')
	{
		*f = 1;
		if ((*str)[*j][*i] == ' ')
			*f = 0;
		if ((*str)[*j][*i] == '-' || (*str)[*j][*i] == '+')
		{
			if (!ft_isdigit((*str)[*j][*i + 1]))
				(*m)++;
			if (((*str)[*j][(*i) - 1] == ' ') || *i == 0)
				(*spy)++;
			else
				(*m)++;
			*f = 0;
		}
	}
	(*i)++;
}

void	loop_args(char **str, int *found, int *digit)
{
	int	j;
	int	spy;
	int	midd;
	int	i;

	j = 1;
	spy = 0;
	midd = 0;
	i = 0;
	while (str[j])
	{
		i = 0;
		spy = 0;
		*digit = 0;
		while (str[j][i] && str[j][i] != '\0')
		{
			if (ft_isdigit(str[j][i]))
				*digit = 1;
			for_arg_handler(&str, found, &spy, &i, &j, &midd);
		}
		if (!*digit || midd != 0)
			ft_print_err();
		j++;
	}
}

int	arg_handlers_bonus(int total, char **str)
{
	int	found;
	int	digit;

	digit = 0;
	found = 0;
	if (total == 1)
		exit(0);
	loop_args(str, &found, &digit);
	if (found)
		return (1);
	return (0);
}
