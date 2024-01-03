/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:33:08 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/03 12:10:26 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	direction(t_data *data)
{
	char	*redx;
	char	*exit;

	if (check_collect(data, data->map) == 0)
	{
		exit = "./xpmfile/doropen_pack.xpm";
		data->imgs.exit = mlx_xpm_file_to_image(data->mlx, exit,
				&data->imgs.width, &data->imgs.height);
	}
	if (data->keysend == KEY_A || data->keysend == KEY_LEFT)
	{
		redx = "./xpmfile/left_pack.xpm";
		data->imgs.player = mlx_xpm_file_to_image(data->mlx, redx,
				&data->imgs.width, &data->imgs.height);
	}
	else if (data->keysend == KEY_D || data->keysend == KEY_RIGHT)
	{
		redx = "./xpmfile/right_pack.xpm";
		data->imgs.player = mlx_xpm_file_to_image(data->mlx, redx,
				&data->imgs.width, &data->imgs.height);
	}
	else if (data->keysend == KEY_S || data->keysend == KEY_BOTTOM)
	{
		redx = "./xpmfile/down_pack.xpm";
		data->imgs.player = mlx_xpm_file_to_image(data->mlx, redx,
				&data->imgs.width, &data->imgs.height);
	}
	else if (data->keysend == KEY_W || data->keysend == KEY_TOP)
	{
		redx = "./xpmfile/top_pack.xpm";
		data->imgs.player = mlx_xpm_file_to_image(data->mlx, redx,
				&data->imgs.width, &data->imgs.height);
	}
}

void	fill_the_map_forsmall(t_data	data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	mlx_clear_window(data.mlx, data.mlx_win);
	direction(&data);
	while (*y < data.height)
	{
		while (*x < data.width)
		{
			if (data.map[*y][*x] == data.content.wall)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall,
					*x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.space)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor,
					*x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.player)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.player, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.collect)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.exit)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit,
					*x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.enemie)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.enemie, *x * data.imgs.width, *y * data.imgs.height);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	ft_show_moves(&data);
}

void	fill_the_map(t_data	data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	mlx_clear_window(data.mlx, data.mlx_win);
	direction(&data);
	while (*y < data.height)
	{
		while (*x < data.width)
		{
			if (data.map[*y][*x] == data.content.wall)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall,
					*x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.space)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor,
					*x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.player)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.player, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.collect)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.exit)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit,
					*x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.enemie)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.enemie, *x * data.imgs.width, *y * data.imgs.height);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	ft_show_moves(&data);
}
