/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:37:27 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/25 18:02:14 by aitaouss         ###   ########.fr       */
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
    data->imgs.floor = ".xpm";
	data->imgs.wall = ".xpm";
	data->imgs.collect = ".xpm";
	data->imgs.player = ".xpm";
	data->imgs.exit = ".xpm";
}