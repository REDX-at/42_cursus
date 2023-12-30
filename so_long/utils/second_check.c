/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:54:06 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/30 10:58:27 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_if_is_playable(char **map)
{
	t_data	data;
	int		row;
	int		col;

	if (ft_check_p(map, 'P', &row, &col))
	{
		if (row > 0 && row < data.width - 1 && col > 0 && col < data.width - 1)
		{
			if (map[row + 1][col] == '1' && map[row - 1][col] == '1' &&
				map[row][col + 1] == '1' && map[row][col - 1] == '1')
			{
				print_string("Error\nThe map is not Playabale\n");
				return (0);
			}
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

int	ft_check_p(char **map, char p, int *row, int *col)
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

int	check_collect(t_data *data, char **map)
{
	int		i;
	int		y;
	int		count;

	data->map = map;
	i = 0;
	y = 0;
	count = 0;
	while (data->map[y])
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.collect)
				count++;
			i++;
		}
		i = 0;
		y++;
	}
	return (count);
}

char	**check_direction(int y, int x, t_data *data, char **str)
{
	if (str[y + 1][x] == data->content.exit
		|| str[y - 1][x] == data->content.exit
			|| str[y][x + 1] == data->content.exit
			|| str[y][x - 1] == data->content.exit)
		data->new_e = 1;
	if (str[y][x + 1] == data->content.collect
		|| str[y][x + 1] == data->content.space)
	{
		str[y][x + 1] = data->content.player;
		check_direction(y, x + 1, data, str);
	}
	if (str[y][x - 1] == data->content.collect
		|| str[y][x - 1] == data->content.space)
	{
		str[y][x - 1] = data->content.player;
		check_direction(y, x - 1, data, str);
	}
	if (str[y + 1][x] == data->content.collect
		|| str[y + 1][x] == data->content.space)
	{
		str[y + 1][x] = data->content.player;
		check_direction(y + 1, x, data, str);
	}
	if (str[y - 1][x] == data->content.collect
		|| str[y - 1][x] == data->content.space)
	{
		str[y - 1][x] = data->content.player;
		check_direction(y - 1, x, data, str);
	}
	return (str);
}

int	check_if_can_play(char **str, t_data *data)
{
	int	x;
	int	y;
	int	d;

	d = 0;
	d = ft_check_whereis_p(str, 'P', &y, &x);
	if (d != 0)
	{
		str = check_direction(y, x, data, data->map_tmp);
		y = -1;
		while (str[++y])
		{
			ft_printf("y : %d\n", y);
			ft_printf("he : %s\n", str[y]);
			data->check_exit = ft_strtrim(str[y], "PE10");
			ft_printf("the char : %c\n", data->check_exit[0]);
			if (data->check_exit[0] != '\0' || data->new_e == 0)
			{
				print_string("The Map Cant Be Playable 🤬.\n");
				return (0);
			}
			free(data->check_exit);
			free(str[y]);
		}
	}
	return (0);
}