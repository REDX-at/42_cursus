/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:30:25 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/27 16:01:46 by aitaouss         ###   ########.fr       */
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
			{
                return 1;
            }
        }
		else
		{
            return 1;
        }
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


// int check_if_is_playable(char **map)
// {
//     t_data data;
//     int row, col;
    
// 	data.width = 6;
//     if (ft_check_p(map, 'P', &row, &col)) {
//         if (row > 0 && row < data.width - 1 && col > 0 && col < data.width - 1)
// 		{
//             if (map[row + 1][col] == '1' && map[row - 1][col] == '1' &&
//                 map[row][col + 1] == '1' && map[row][col - 1] == '1')
// 			{
// 				printf("Error\nThe map is not Playabale\n");
//                 return 0;
//             }
// 			else
// 			{
//                 return 1;
//             }
//         }
// 		else
// 		{
//             return 1;
//         }
//     }
//     return 0;
// }
// int main() {
//     // Example map
//     char *map[] = {
//         "111111",
//         "100011",
//         "11P111",
//         "101011",
//         "100011",
//         "111111",
//         NULL
//     };

//     // Check if the map is surrounded by walls
//     if (check_if_is_playable(map)) {
//         printf("The map is playable!\n");
//     }

//     return 0;
// }
