/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:37:27 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/26 09:20:40 by aitaouss         ###   ########.fr       */
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
    data->imgs.height = 80;
    data->imgs.width= 80;
    data->imgs.floor = "floor.xpm";
	data->imgs.wall = "brick.xpm";
	data->imgs.collect = "brick.xpm";
	data->imgs.player = "brick.xpm";
	data->imgs.exit = "brick.xpm";
	data->imgs.img_wall = mlx_xpm_file_to_image(data->mlx, data->imgs.wall, 
						&(data->imgs.width), &(data->imgs.height));
	data->imgs.img_floor = mlx_xpm_file_to_image(data->mlx, data->imgs.floor, 
						&(data->imgs.width), &(data->imgs.height));
	data->imgs.img_exit = mlx_xpm_file_to_image(data->mlx, data->imgs.exit, 
						&(data->imgs.width), &(data->imgs.height));
	data->imgs.img_collect = mlx_xpm_file_to_image(data->mlx, data->imgs.collect, 
						&(data->imgs.width), &(data->imgs.height));
	data->imgs.img_player = mlx_xpm_file_to_image(data->mlx, data->imgs.player, 
						&(data->imgs.width), &(data->imgs.height));
}