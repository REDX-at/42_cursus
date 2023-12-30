/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:32:10 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/30 20:53:45 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_enemie(t_data *data)
{
	int	pos_x;
	int	pos_y;
	int	check;
	check = 0;

	check = ft_check_whereis_p(data->map, 'N', &pos_y, &pos_x);
	if (check == 1)
	{
		if (data->map[pos_y][pos_x - 1] != data->content.wall)
		{
			if (data->map[pos_y][pos_x - 1] != data->content.exit && data->map[pos_y][pos_x - 1] != data->content.collect
				&& data->map[pos_y][pos_x - 1] != data->content.exit != data->content.player)
			{
				data->map[pos_y][pos_x - 1] = data->content.enemie;
				data->map[pos_y][pos_x] = data->content.space;
			}
		}
		if (data->map[pos_y][pos_x + 1] != data->content.wall)
		{
			if (data->map[pos_y][pos_x + 1] != data->content.exit && data->map[pos_y][pos_x + 1] != data->content.collect
				&& data->map[pos_y][pos_x + 1] != data->content.exit != data->content.player)
			{
				data->map[pos_y][pos_x + 1] = data->content.enemie;
				data->map[pos_y][pos_x] = data->content.space;
			}
		}
		if (data->map[pos_y - 1][pos_x] != data->content.wall)
		{
			if (data->map[pos_y - 1][pos_x] != data->content.exit && data->map[pos_y - 1][pos_x] != data->content.collect
				&& data->map[pos_y - 1][pos_x] != data->content.exit != data->content.player)
			{
				data->map[pos_y - 1][pos_x] = data->content.enemie;
				data->map[pos_y][pos_x] = data->content.space;
			}
		}
		if (data->map[pos_y + 1][pos_x] != data->content.wall)
		{
			if (data->map[pos_y + 1][pos_x] != data->content.exit && data->map[pos_y + 1][pos_x] != data->content.collect
				&& data->map[pos_y + 1][pos_x] != data->content.exit != data->content.player)
			{
					data->map[pos_y + 1][pos_x] = data->content.enemie;
					data->map[pos_y][pos_x] = data->content.space;
			}
		}
	}
	return 0;
}