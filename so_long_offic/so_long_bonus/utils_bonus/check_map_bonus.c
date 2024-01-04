/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:30:25 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/04 12:39:57 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_check_col(char *map_line, char wall, t_data *data)
{
	int		i;

	i = 0;
	while (map_line[i])
		i++;
	if (map_line[0] != wall || map_line[i - 1] != wall)
	{
		print_string("Error\nMap column not close\n");
		return (0);
	}
	data->width = i;
	return (1);
}

int	ft_check_line(char *map_line, char wall)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (map_line[j])
		j++;
	while (map_line[i] && i < j)
	{
		if (map_line[i] != wall)
		{
			print_string("Error\nMap line not close\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_other(char *map_line, t_cnt *content)
{
	int		i;

	i = 0;
	while (map_line[i])
	{
		if (content->count_e > 1 || content->count_p > 1
			|| content->count_n == 0)
		{
			print_string("Error\nWrong number of player"
				"| exit | enemie Not found\n");
			return (0);
		}
		if (map_line[i] != content->wall && map_line[i] != content->player
			&& map_line[i] != content->exit && map_line[i] != content->collect
			&& map_line[i] != content->space && map_line[i] != content->enemie)
		{
			print_string("Error\nSymbole Not found in Data\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_check_content(t_data *data)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (data->map[i])
	{
		while (data->map[i][y])
		{
			if (data->map[i][y] == data->content.collect)
				data->content.count_c += 1;
			if (data->map[i][y] == data->content.player)
				data->content.count_p += 1;
			if (data->map[i][y] == data->content.exit)
				data->content.count_e += 1;
			if (data->map[i][y] == data->content.enemie)
				data->content.count_n += 1;
			y++;
		}
		y = 0;
		i++;
	}
}

int	ft_check_format(char **map)
{
	int		y;
	int		x;
	int		count_x;

	x = 0;
	y = 0;
	count_x = 0;
	while (map[0][count_x])
		count_x++;
	while (map[y] != NULL)
	{
		while (map[y][x])
			x++;
		if (x != count_x)
		{
			print_string("Error\nFormat of Map invalid\n");
			return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}
