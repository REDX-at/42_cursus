/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:37:27 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/23 23:40:42 by aitaouss         ###   ########.fr       */
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
    data->img.height = 80;
    data->img.width= 80;
}