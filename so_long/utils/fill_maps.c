/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:33:08 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/02 20:14:35 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_the_map_fortop(t_data	data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	mlx_clear_window(data.mlx, data.mlx_win);
	char	*redx = "./xpmfile/top_pack.xpm";
	data.imgs.playerback = mlx_xpm_file_to_image(data.mlx, redx,
			&data.imgs.width, &data.imgs.height);
	while (*y < data.height)
	{
		while(*x < data.width)
		{
			if (data.map[*y][*x] == data.content.wall)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall,
					*x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.space)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor,
					*x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.player)
				mlx_put_image_to_window(data.mlx, data.mlx_win,
					data.imgs.playerback, *x * data.imgs.width,
					*y * data.imgs.height);
			if (data.map[*y][*x] == data.content.collect)
				mlx_put_image_to_window(data.mlx,
					data.mlx_win, data.imgs.collect,
					*x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.exit)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit,
					*x * data.imgs.width, *y * data.imgs.height);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	ft_show_moves(&data);
}
void	fill_the_map_forright(t_data	data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	mlx_clear_window(data.mlx, data.mlx_win);
	char	*redx = "./xpmfile/right_pack.xpm";
	data.imgs.player_right = mlx_xpm_file_to_image(data.mlx, redx, &data.imgs.width, &data.imgs.height);
	while (*y < data.height)
	{
		while(*x < data.width)
		{
			if (data.map[*y][*x] == data.content.wall)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.space)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.player)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.player_right, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.collect)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.exit)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit, *x * data.imgs.width, *y * data.imgs.height);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	ft_show_moves(&data);
}
void	fill_the_map_forsmallright(t_data	data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	mlx_clear_window(data.mlx, data.mlx_win);
    char	*exit = "./xpmfile/doropen_pack.xpm";
	data.imgs.exit = mlx_xpm_file_to_image(data.mlx, exit, &data.imgs.width, &data.imgs.height);
	char	*redx = "./xpmfile/right_pack.xpm";
	data.imgs.player_right = mlx_xpm_file_to_image(data.mlx, redx, &data.imgs.width, &data.imgs.height);
	while (*y < data.height)
	{
		while(*x < data.width)
		{
			if (data.map[*y][*x] == data.content.wall)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.space)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.player)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.player_right, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.collect)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.exit)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit, *x * data.imgs.width, *y * data.imgs.height);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	ft_show_moves(&data);
}
void	fill_the_map_forsmallleft(t_data	data, int *x, int *y)
{
	*x = 0;
	*y = 0;
    char	*exit = "./xpmfile/doropen_pack.xpm";
	data.imgs.exit = mlx_xpm_file_to_image(data.mlx, exit, &data.imgs.width, &data.imgs.height);
	char	*redx = "./xpmfile/left_pack.xpm";
	data.imgs.player_right = mlx_xpm_file_to_image(data.mlx, redx, &data.imgs.width, &data.imgs.height);
	while (*y < data.height)
	{
		while(*x < data.width)
		{
			if (data.map[*y][*x] == data.content.wall)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.space)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.player)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.player_right, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.collect)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.exit)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit, *x * data.imgs.width, *y * data.imgs.height);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	ft_show_moves(&data);
}
void	fill_the_map_forleft(t_data	data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	mlx_clear_window(data.mlx, data.mlx_win);
	char	*redx = "./xpmfile/left_pack.xpm";
	data.imgs.player_left = mlx_xpm_file_to_image(data.mlx, redx, &data.imgs.width, &data.imgs.height);
	while (*y < data.height)
	{
		while(*x < data.width)
		{
			if (data.map[*y][*x] == data.content.wall)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.space)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.player)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.player_left, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.collect)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.exit)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit, *x * data.imgs.width, *y * data.imgs.height);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	};
	ft_show_moves(&data);
}
void	fill_the_map_forsmall(t_data	data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	mlx_clear_window(data.mlx, data.mlx_win);
	char	*exit = "./xpmfile/doropen_pack.xpm";
	data.imgs.exit = mlx_xpm_file_to_image(data.mlx, exit, &data.imgs.width, &data.imgs.height);
	while (*y < data.height)
	{
		while(*x < data.width)
		{
			if (data.map[*y][*x] == data.content.wall)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.space)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.player)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.player, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.collect)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.exit)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit, *x * data.imgs.width, *y * data.imgs.height);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	ft_show_moves(&data);
}
void	fill_the_map_forsmalltop(t_data	data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	mlx_clear_window(data.mlx, data.mlx_win);
    char	*exit = "./xpmfile/doropen_pack.xpm";
	data.imgs.exit = mlx_xpm_file_to_image(data.mlx, exit, &data.imgs.width, &data.imgs.height);
	char	*redx = "./xpmfile/top_pack.xpm";
	data.imgs.playerback = mlx_xpm_file_to_image(data.mlx, redx, &data.imgs.width, &data.imgs.height);
	while (*y < data.height)
	{
		while(*x < data.width)
		{
			if (data.map[*y][*x] == data.content.wall)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.space)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.player)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.playerback, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.collect)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.exit)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit, *x * data.imgs.width, *y * data.imgs.height);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	ft_show_moves(&data);
}
void	fill_the_map_fordown(t_data	data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	mlx_clear_window(data.mlx, data.mlx_win);
	char	*redx = "./xpmfile/down_pack.xpm";
	data.imgs.player_down = mlx_xpm_file_to_image(data.mlx, redx,
			&data.imgs.width, &data.imgs.height);
	while (*y < data.height)
	{
		while(*x < data.width)
		{
			if (data.map[*y][*x] == data.content.wall)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall,
					*x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.space)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor,
					*x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.player)
				mlx_put_image_to_window(data.mlx, data.mlx_win,
					data.imgs.player_down, *x * data.imgs.width,
					*y * data.imgs.height);
			if (data.map[*y][*x] == data.content.collect)
				mlx_put_image_to_window(data.mlx,
					data.mlx_win, data.imgs.collect,
					*x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.exit)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit,
					*x * data.imgs.width, *y * data.imgs.height);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	ft_show_moves(&data);
}

void	fill_the_map_forsmalldown(t_data	data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	mlx_clear_window(data.mlx, data.mlx_win);
    char	*exit = "./xpmfile/doropen_pack.xpm";
	data.imgs.exit = mlx_xpm_file_to_image(data.mlx, exit, &data.imgs.width, &data.imgs.height);
	char	*redx = "./xpmfile/down_pack.xpm";
	data.imgs.player_down = mlx_xpm_file_to_image(data.mlx, redx, &data.imgs.width, &data.imgs.height);
	while (*y < data.height)
	{
		while(*x < data.width)
		{
			if (data.map[*y][*x] == data.content.wall)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.space)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.player)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.player_down, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.collect)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.exit)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit, *x * data.imgs.width, *y * data.imgs.height);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	ft_show_moves(&data);
}

void	direction(t_data *data)
{
	char	*redx;
	if (data->keysend == KEY_A)
	{
		redx = "./xpmfile/left_pack.xpm";
		data->imgs.player = mlx_xpm_file_to_image(data->mlx, redx, &data->imgs.width, &data->imgs.height);
	}
	else if (data->keysend == KEY_D)
	{
		redx = "./xpmfile/right_pack.xpm";
		data->imgs.player = mlx_xpm_file_to_image(data->mlx, redx, &data->imgs.width, &data->imgs.height);
	}
	else if (data->keysend == KEY_S)
	{
		redx = "./xpmfile/down_pack.xpm";
		data->imgs.player = mlx_xpm_file_to_image(data->mlx, redx, &data->imgs.width, &data->imgs.height);
	}
	else if (data->keysend == KEY_W)
	{
		redx = "./xpmfile/top_pack.xpm";
		data->imgs.player = mlx_xpm_file_to_image(data->mlx, redx, &data->imgs.width, &data->imgs.height);
	}
}

void	fill_the_map(t_data	data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	mlx_clear_window(data.mlx, data.mlx_win);
	direction(&data);
	while (*y < data.height)
	{
		while(*x < data.width)
		{
			if (data.map[*y][*x] == data.content.wall)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.space)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.player)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.player, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.collect)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect, *x * data.imgs.width, *y * data.imgs.height);
			if (data.map[*y][*x] == data.content.exit)
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit, *x * data.imgs.width, *y * data.imgs.height);
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
	ft_show_moves(&data);
}