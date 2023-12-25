/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:30:25 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/25 20:29:33 by aitaouss         ###   ########.fr       */
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

int ft_check_p(char **map, char p, int *row, int *col) {
    *row = 0;
    while (map[*row] != NULL) {
        *col = 0;
        while (map[*row][*col] != '\0') {
            if (map[*row][*col] == p) {
				printf("there is p : \n");
                return 1;
            }
            (*col)++;
        }
        (*row)++;
    }
    return 0;
}

int check_if_is_playable(char **map) {
    t_data data;
    int row, col;
    
    if (ft_check_p(map, 'P', &row, &col)) {
        if (row > 0 && row < data.width - 1 && col > 0 && col < data.width - 1) {
            if (map[row + 1][col] == '1' && map[row - 1][col] == '1' &&
                map[row][col + 1] == '1' && map[row][col - 1] == '1') {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 1;
}

int main(){
    char *map[] = {
        "111111",
        "10C1C1",
        "1C1P11",
        "1C11C1",
        "11E1C1",
        "111111",
        NULL
    };
	
	t_data	data;
	data.width = 6;
	int d = check_if_is_playable(map);
	printf("%d", d);
    return 0;
}
