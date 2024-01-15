/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:19:00 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/13 20:09:37 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_err(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	for_arg_handler(char ***str, int *found, int *spy, int *i, int *j, int *midd)
{
	if ((*str)[*j][*i] < '0' || (*str)[*j][*i] > '9')
	{
		*found = 1;
		if ((*str)[*j][*i] == ' ')
			*found = 0;
		if ((*str)[*j][*i] == '-' || (*str)[*j][*i] == '+')
		{
			if (!ft_isdigit((*str)[*j][*i + 1]))
				(*midd)++;
			if (((*str)[*j][(*i) - 1] == ' ') || *i == 0)
				(*spy)++;
			else
				(*midd)++;
			*found = 0;
		}
	}
	(*i)++;
}
int arg_handlers(int total, char **str)
{
	int j = 1;
	int found = 0;
	int	spy = 0;
	int	midd = 0;
	int	is_digit = 0;
	int	i = 0;

	if (total == 1)
		ft_print_err();
	while (str[j]) 
	{
		i = 0;
		spy = 0;
		is_digit = 0;
		while (str[j][i] && str[j][i] != '\0')
		{
			if (ft_isdigit(str[j][i]))
				is_digit = 1;
			for_arg_handler(&str, &found, &spy, &i, &j, &midd);
		}
		if (!is_digit)
			ft_print_err();
		if (midd != 0)
			ft_print_err();
		j++;
	}
	if (found)
		return 1;
	else
		return 0;
}
