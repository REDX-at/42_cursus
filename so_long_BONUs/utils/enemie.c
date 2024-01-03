/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:32:10 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/03 15:46:53 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_die(t_data *data, int *x, int *y)
{
	if (data->map[*y][*x - 1] == data->content.player)
		print_string("You are die 💀 .\n");
	else if (data->map[*y][*x + 1] == data->content.player)
		print_string("You are die 💀 .\n");
}

int	move_enemie(t_data *data)
{
	int	pos_x;
	int	pos_y;

	ft_check_whereis_p(data->map, 'N', &pos_y, &pos_x);
	player_die(data, &pos_x, &pos_y);
	if (data->map[pos_y][pos_x - 1] == '0' && data->content.count_enemie == 1)
	{
		data->content.count_enemie = 1;
		data->map[pos_y][pos_x - 1] = data->content.enemie;
		data->map[pos_y][pos_x] = data->content.space;
		fill_the_map(*data, &pos_x, &pos_y);
	}
	else if (data->map[pos_y][pos_x + 1] == data->content.space)
	{
		data->content.count_enemie = 0;
		data->map[pos_y][pos_x + 1] = data->content.enemie;
		data->map[pos_y][pos_x] = data->content.space;
		fill_the_map(*data, &pos_x, &pos_y);
	}
	else
		data->content.count_enemie = 1;
	return (0);
}

int	sloow_move(t_data *data)
{
	static int	i = 1200;

	i--;
	if (i == 0)
	{
		move_enemie(data);
		i = 1200;
	}
	return (1);
}
