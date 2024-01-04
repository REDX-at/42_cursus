/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_renders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:35:05 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/04 12:55:19 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_free(t_data *data)
{
	ft_printf("The Game is ended.\n");
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(EXIT_FAILURE);
}

void	init_variables(t_data *data)
{
	data->count_tmar = 0;
	data->content.count_p = 0;
	data->content.count_e = 0;
	data->content.count_c = 0;
	data->count = 0;
}

void	open_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_free_map(data);
		ft_free_second_map(data);
		exit(EXIT_FAILURE);
	}
	set_image(data);
	data->mlx_win = mlx_new_window(data->mlx, data->width * (data->imgs.width),
			(data->height * data->imgs.height), "So_long");
	if (data->mlx_win == NULL)
	{
		ft_free_map(data);
		ft_free_second_map(data);
		exit(EXIT_FAILURE);
	}
}

void	call_render(char **str, t_data *data)
{
	int	x;
	int	y;

	init_variables(data);
	set_content(&(data->content));
	data->map = map_core(str, data);
	if (data->width > 53 || data->height > 28)
		print_string("Map size not valid. ");
	data->map_tmp = get_clone(data);
	check_if_can_play(data->map_tmp, data);
	open_window(data);
	fill_the_map(*data, &x, &y);
	mlx_key_hook(data->mlx_win, &input_key, data);
	mlx_hook(data->mlx_win, 17, 0, &ft_free, data);
	mlx_loop(data->mlx);
	end(data);
}
