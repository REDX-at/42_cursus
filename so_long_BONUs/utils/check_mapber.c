/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:03:52 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/30 11:08:18 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	to_find_ber(char c, char b)
{
	if (c == b)
		return (1);
	return (0);
}

int	check_map_ber(char *str)
{
	int		i;
	int		find;
	int		j;
	char	*ber;

	i = 0;
	find = 0;
	j = 0;
	ber = ".ber";
	while (str[i] == ' ')
		i++;
	if (str[i] == '.')
		return (2);
	while (str[i] && ber[j])
	{
		if (str[i] == '.')
		{
			while (ber[j] != '0' && to_find_ber(str[i],
					ber[j]) == 1 && str[i] != '\0')
			{
				find += 1;
				i++;
				j++;
			}
			break ;
		}
		i++;
	}
	if (find == 4 && str[i] == '\0')
		return (1);
	return (0);
}
