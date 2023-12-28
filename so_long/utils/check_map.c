/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:30:25 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/28 20:12:53 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != wall)
		{
			print_string("Error\nMap line not close\n");
			return 0;
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
		if (content->count_e > 1 || content->count_p > 1)
		{
			print_string("Error\nWrong number of player or exit\n");
			return (0);
		}
		if (map_line[i] != content->wall && map_line[i] != content->player
			&& map_line[i] != content->exit && map_line[i] != content->collect
			&& map_line[i] != content->space)
		{
			print_string("Error\nUnknown symbol(s) in map\n");
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
			print_string("Error\nMap must be a rectangle or a square\n");
			return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}
char	**get_clone(t_data *data)
{
	int y = 0;
	data->map_tmp = (char **)malloc(sizeof(char *) * (data->height + 1)); 
	while (data->map[y])
	{
		data->map_tmp[y] = ft_strdup(data->map[y]);
		y++;
	}
	// int i = 0;
	// while (data->map[i])
	// {
	// 	free(data->map[i]);
	// 	i++;
	// }
	// free(data->map);
	//data->map[y] = NULL;
	return data->map_tmp;
}
int check_if_is_playable(char **map)
{
    t_data data;
    int row, col;
    
	// data.width = 6;
    if (ft_check_p(map, 'P', &row, &col))
	{
        if (row > 0 && row < data.width - 1 && col > 0 && col < data.width - 1)
		{
            if (map[row + 1][col] == '1' && map[row - 1][col] == '1' &&
                map[row][col + 1] == '1' && map[row][col - 1] == '1')
			{
				print_string("Error\nThe map is not Playabale\n");
                return 0;
            }
			else
                return 1;
        }
		else
            return 1;
    }
    return 0;
}
int ft_check_p(char **map, char p, int *row, int *col) 
{
    *row = 0;
    while (map[*row] != NULL)
	{
        *col = 0;
        while (map[*row][*col] != '\0')
		{
            if (map[*row][*col] == p)
                return 1;
            (*col)++;
        }
        (*row)++;
    }
    return 0;
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
	if (str[y + 1][x] == data->content.exit || str[y - 1][x] == data->content.exit || str[y][x + 1] == data->content.exit || str[y][x - 1] == data->content.exit)
		data->new_e = 1;
	if (str[y][x + 1] == data->content.collect || str[y][x + 1] == data->content.space)
	{
		str[y][x + 1] = data->content.player;
		check_direction(y, x + 1, data, str);
	}
	if (str[y][x - 1] == data->content.collect || str[y][x - 1] == data->content.space)
	{
		str[y][x - 1] = data->content.player;
		check_direction(y, x - 1, data, str);
	}
	if (str[y + 1][x] == data->content.collect || str[y + 1][x] == data->content.space)
	{
		str[y + 1][x] = data->content.player;
		check_direction(y + 1, x, data, str);
	}
	if (str[y - 1][x] == data->content.collect || str[y - 1][x] == data->content.space)
	{
		str[y - 1][x] = data->content.player;
		check_direction(y - 1, x, data, str);
	}
	return str;
}

int	check_if_can_play(char **str, t_data *data)
{
	int x;
	int y;
	int d = 0;
	
	d = ft_check_whereis_p(str, 'P', &y, &x);
	if (d != 0)
	{
		str = check_direction(y, x, data, data->map_tmp);
		y = -1;
		while (str[++y])
		{
			data->check_exit = ft_strtrim(str[y], "PE10");
			if (data->check_exit[0] != '\0' || data->new_e == 0)
			{
				print_string("The Map Cant Be Playable 🤬.\n");
				return (0);
			}
		}
	}
	return 0;
}
