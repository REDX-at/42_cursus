/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:37:27 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/28 13:49:15 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    set_content(t_cnt *content)
{
    content->exit = 'E';
    content->player = 'P';
    content->wall = '1';
	content->space = '0';
	content->collect = 'C';
	content->count_p = 0;
	content->count_e = 0;
	content->count_c = 0;
}

void    set_image(t_data *data)
{
    data->imgs.height = 48;
    data->imgs.width= 48;
	char	*wall = "./xpmfile/new_wall.xpm";
	char	*floorxpm = "./xpmfile/new_floor.xpm";
	char	*redx = "./xpmfile/new_redx.xpm";
	char	*collect = "./xpmfile/new_collect.xpm";
	char	*exit = "./xpmfile/new_exit.xpm";
	data->imgs.collect = mlx_xpm_file_to_image(data->mlx, collect, &data->imgs.width, &data->imgs.height);
	data->imgs.wall = mlx_xpm_file_to_image(data->mlx, wall, &data->imgs.width, &data->imgs.height);
	data->imgs.floor = mlx_xpm_file_to_image(data->mlx, floorxpm, &data->imgs.width, &data->imgs.height);
	data->imgs.player = mlx_xpm_file_to_image(data->mlx, redx, &data->imgs.width, &data->imgs.height);
	data->imgs.exit = mlx_xpm_file_to_image(data->mlx, exit, &data->imgs.width, &data->imgs.height);
}