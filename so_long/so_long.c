/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:14:14 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/27 12:49:37 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	print_err()
{
	ft_printf("%sMap Invalide %sX\n", WHITE, RED_NEW);
}

int	end(t_data *data)
{
	int		i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		data->map[i] = NULL;
		free(data->map);
		mlx_destroy_image(data->mlx, data->imgs.img_floor);
		mlx_destroy_image(data->mlx, data->imgs.img_collect);
		mlx_destroy_image(data->mlx, data->imgs.img_wall);
		mlx_destroy_image(data->mlx, data->imgs.img_exit);
		mlx_destroy_image(data->mlx, data->imgs.img_player);
		mlx_destroy_image(data->mlx, data->mlx_win);
	}
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

void	*print_string(char *str)
{
	ft_printf("%s%s",WHITE, str);
	exit(EXIT_FAILURE);
}
void	init_variables(t_data *data)
{
	data->content.count_p = 0;
	data->content.count_e = 0;
	data->content.count_c = 0;
}

void check_height_width(char **map, int *x, int *y)
{
    *y = 0;
    *x = 0;
    while (map[*x][*y])
        (*x)++;
    ft_printf("X : %d", *x);
    *x = 0;
    while (map[*x][*y])
        (*y)++;
    ft_printf("Y : %d", *y);
}
void	fill_the_map(t_data	data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (*y < data.height)
	{
		while(*x < data.width)
		{
			if (data.map[*y][*x] == data.content.wall)
			{
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall, *x * data.imgs.width, *y * data.imgs.height);
			}
			if (data.map[*y][*x] == data.content.space)
			{
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor, *x * data.imgs.width, *y * data.imgs.height);
			}
			if (data.map[*y][*x] == data.content.player)
			{
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.player, *x * data.imgs.width, *y * data.imgs.height);
			}
			if (data.map[*y][*x] == data.content.collect)
			{
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect, *x * data.imgs.width, *y * data.imgs.height);
			}
			if (data.map[*y][*x] == data.content.exit)
			{
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit, *x * data.imgs.width, *y * data.imgs.height);
			}
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
}
int main(int argc, char **argv)
{
	t_data		data;
	
	args_handler(argc);
	int i = 0;
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
		{
			print_string("Message Empty.\n");
			return (0);
		}
		i = check_map_ber(argv[1]);
		if (i == 0)
			print_err();
		else if (i == 2)
			print_string("Right syntax <file.ber>");
		else
		{
			data.count = 0;
			init_variables(&data);
			set_content(&(data.content));
			data.map = map_core(argv, &data);
			data.mlx = mlx_init();
			if (!data.mlx)
				return 0;
			data.imgs.width = 48;
			data.imgs.height = 48;
			data.mlx_win = mlx_new_window(data.mlx, data.width * (data.imgs.width), (data.height * data.imgs.height), "So_long");
			if (data.mlx_win == NULL)
			{
				free(data.mlx);
				return 0;
			}
			// render(&data);
			int y = 0;
			int x = 0;
			// void	*img;
			// void	*floor;
			char	*wall = "wall7jar.xpm";
			char	*floorxpm = "floorw.xpm";
			char	*redx = "REDXw.xpm";
			char	*collect = "collect.xpm";
			char	*exit = "EXIT.xpm";
			data.imgs.collect = mlx_xpm_file_to_image(data.mlx, collect, &data.imgs.width, &data.imgs.height);
			data.imgs.wall = mlx_xpm_file_to_image(data.mlx, wall, &data.imgs.width, &data.imgs.height);
			data.imgs.floor = mlx_xpm_file_to_image(data.mlx, floorxpm, &data.imgs.width, &data.imgs.height);
			data.imgs.player = mlx_xpm_file_to_image(data.mlx, redx, &data.imgs.width, &data.imgs.height);
			data.imgs.exit = mlx_xpm_file_to_image(data.mlx, exit, &data.imgs.width, &data.imgs.height);
			// mlx_put_image_to_window(data.mlx, data.mlx_win, img, 0, 0);
			// while (y < data.height)
			// {
			// 	while(x < data.width)
			// 	{
			// 		if (data.map[y][x] == data.content.wall)
			// 		{
			// 			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.wall, x * data.imgs.width, y * data.imgs.height);
			// 		}
			// 		if (data.map[y][x] == data.content.space)
			// 		{
			// 			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.floor, x * data.imgs.width, y * data.imgs.height);
			// 		}
			// 		if (data.map[y][x] == data.content.player)
			// 		{
			// 			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.player, x * data.imgs.width, y * data.imgs.height);
			// 		}
			// 		if (data.map[y][x] == data.content.collect)
			// 		{
			// 			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.collect, x * data.imgs.width, y * data.imgs.height);
			// 		}
			// 		if (data.map[y][x] == data.content.exit)
			// 		{
			// 			mlx_put_image_to_window(data.mlx, data.mlx_win, data.imgs.exit, x * data.imgs.width, y * data.imgs.height);
			// 		}
			// 		x++;
			// 	}
			// 	x = 0;
			// 	y++;
			// }
			fill_the_map(data, &x, &y);
			mlx_hook(data.mlx_win, 2, 0, &input_key, &data);
			mlx_hook(data.mlx_win, 17, 0, &end, &data);
			mlx_loop(data.mlx);
			end(&data);
		}
	}
	return 0;
}
