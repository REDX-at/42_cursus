/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:10:12 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/27 12:02:46 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_background(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i] != '\0')
		{
			if (data->map[y][i] == data->content.wall)
				print_img(data, data->imgs.img_wall, i, y);
			if (data->map[y][i] == data->content.space)
				print_img(data, data->imgs.img_floor, i, y);
			i++;
		}
		i = 0;
		y++;
	}
}

void	render_mapi(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i])
		{
			while (data->map[y][i])
			{
				if (data->map[y][i] == data->content.collect)
					print_img(data, data->imgs.img_collect, i, y);
				if (data->map[y][i] == data->content.player)
				{
					data->pos.x = i * data->imgs.width;
					data->pos.y = y * data->imgs.height;
					print_img(data, data->imgs.img_player, i, y);
				}
				if (data->map[y][i] == data->content.exit)
					print_img(data, data->imgs.img_exit, i, y);
				i++;
			}
			i = 0;
			y++;
		}
	}
}

// int	input_key(int keycode, t_data *data)
// {
// 	if (keycode == KEY_ESC)
// 	{
// 		ft_printf("The Game is ended.\n");
// 		mlx_destroy_window(data->mlx, data->mlx_win);
// 	}
// 	if (keycode == KEY_A)
// 		move_right(data);
// 	if (keycode == KEY_W)
// 		ft_printf("W");
// 	if (keycode == KEY_S)
// 		ft_printf("S");
// 	if (keycode == KEY_D)
// 		ft_printf("D");
// 	return (0);
// }

int	render(t_data *data)
{
	render_background(data);
	render_mapi(data);
	return (0);
}
void	render_offic(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->width * (data->imgs.width), (data->height * data->imgs.height), "So_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx);
		return ;
	}
	mlx_loop_hook(data->mlx, &render, data);
	mlx_hook(data->mlx_win, 2, 0, &input_key, &data);
	mlx_hook(data->mlx_win, 17, 0, &end, data);
	mlx_loop(data->mlx);
	end(data);
}
void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img,
		data->width * x, data->height * y);
}