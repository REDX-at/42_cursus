/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_third.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:26:33 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/04 17:51:00 by aitaouss         ###   ########.fr       */
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

void	check_newline(char	**str)
{
	int		fd2;
	char	*line;
	char	*temp;

	fd2 = 0;
	fd2 = open(str[1], O_RDONLY);
	if (fd2 == -1)
		print_string("Error\nFailed to open file\n");
	line = get_next_line(fd2);
	while (line)
	{
		temp = line;
		if (*line == '\n')
			print_string("Error\nFailed to open file\n");
		line = get_next_line(fd2);
		free(temp);
	}
	close(fd2);
}

void	check_keysend(t_data *data, char *redx)
{
	if (data->keysend == KEY_A || data->keysend == KEY_LEFT)
	{
		redx = "./texture/left_pack.xpm";
		data->imgs.player = mlx_xpm_file_to_image(data->mlx, redx,
				&data->imgs.width, &data->imgs.height);
	}
	else if (data->keysend == KEY_D || data->keysend == KEY_RIGHT)
	{
		redx = "./texture/right_pack.xpm";
		data->imgs.player = mlx_xpm_file_to_image(data->mlx, redx,
				&data->imgs.width, &data->imgs.height);
	}
	else if (data->keysend == KEY_S || data->keysend == KEY_BOTTOM)
	{
		redx = "./texture/down_pack.xpm";
		data->imgs.player = mlx_xpm_file_to_image(data->mlx, redx,
				&data->imgs.width, &data->imgs.height);
	}
	else if (data->keysend == KEY_W || data->keysend == KEY_TOP)
	{
		redx = "./texture/top_pack.xpm";
		data->imgs.player = mlx_xpm_file_to_image(data->mlx, redx,
				&data->imgs.width, &data->imgs.height);
	}
}
