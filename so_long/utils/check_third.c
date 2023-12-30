/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_third.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:26:33 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/30 10:43:51 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_whereis_p(char **map, char p, int *row, int *col)
{
	*row = 0;
	while (map[*row] != NULL)
	{
		*col = 0;
		while (map[*row][*col] != '\0')
		{
			if (map[*row][*col] == p)
				return (1);
			(*col)++;
		}
		(*row)++;
	}
	return (0);
}

char	**get_clone(t_data *data)
{
	int	y;

	y = 0;
	data->map_tmp = (char **)malloc(sizeof(char *) * (data->height + 1));
	while (data->map[y])
	{
		data->map_tmp[y] = ft_strdup(data->map[y]);
		y++;
	}
	data->map_tmp[y] = NULL;
	return (data->map_tmp);
}
