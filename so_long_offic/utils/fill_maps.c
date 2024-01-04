/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:33:08 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/04 17:50:55 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	direction(t_data *data)
{
	char	*redx;
	char	*exit;

	redx = NULL;
	if (check_collect(data, data->map) == 0)
	{
		exit = "./texture/doropen_pack.xpm";
		data->imgs.exit = mlx_xpm_file_to_image(data->mlx, exit,
				&data->imgs.width, &data->imgs.height);
	}
	check_keysend(data, redx);
}

void	for_fill_small(t_data data, int *x, int *y)
{
	if (data.map[*y][*x] == data.content.wall)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall,
			*x * data.imgs.width, *y * data.imgs.height);
	if (data.map[*y][*x] == data.content.space)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor,
			*x * data.imgs.width, *y * data.imgs.height);
	if (data.map[*y][*x] == data.content.player)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.player,
			*x * data.imgs.width, *y * data.imgs.height);
	if (data.map[*y][*x] == data.content.collect)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect,
			*x * data.imgs.width, *y * data.imgs.height);
	if (data.map[*y][*x] == data.content.exit)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit,
			*x * data.imgs.width, *y * data.imgs.height);
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
			for_fill_small(data, x, y);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
}

void	for_fill(t_data data, int *x, int *y)
{
	if (data.map[*y][*x] == data.content.wall)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall,
			*x * data.imgs.width, *y * data.imgs.height);
	if (data.map[*y][*x] == data.content.space)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor,
			*x * data.imgs.width, *y * data.imgs.height);
	if (data.map[*y][*x] == data.content.player)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.player,
			*x * data.imgs.width, *y * data.imgs.height);
	if (data.map[*y][*x] == data.content.collect)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect,
			*x * data.imgs.width, *y * data.imgs.height);
	if (data.map[*y][*x] == data.content.exit)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit,
			*x * data.imgs.width, *y * data.imgs.height);
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
			for_fill(data, x, y);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
}
