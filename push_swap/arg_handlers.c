/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:19:00 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/07 22:52:41 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int arg_handlers(int total, char **str)
{
	int j = 1;
	int found = 0;
	int	spy = 0;
	if (total == 1)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	while (str[j]) 
	{
		int i = 0;
		spy = 0;
		if (str[j][0] == '-')
			spy++;
		while (str[j][i])
		{
			if (str[j][i] < '0' || str[j][i] > '9')
			{
				found = 1;
				if (str[j][i] == '-' || str[j][i] == '+')
					found = 0;
				if ((str[j][i] == '-' || str[j][i] == '+')&& i != 0)
				{
					found = 0;
					spy++;
				}
			}
			i++;
		}
		if (spy > 1)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		j++;
	}
	if (found)
		return 1;
	else
		return 0;
}
