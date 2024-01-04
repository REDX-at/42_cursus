/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:53:00 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/04 17:28:26 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	swap_move_right(t_data *data, int *x, int *y)
{
	if (data->map[*y][*x + 1] == data->content.collect)
		data->count_tmar += 1;
	data->map[*y][*x + 1] = data->content.player;
	data->map[*y][*x] = data->content.space;
	data->count += 1;
	if (check_collect(data, data->map) == 0)
		fill_the_map_forsmall(*data, x, y);
	if (check_collect(data, data->map) != 0)
		fill_the_map(*data, x, y);
	ft_printf("%sMoves 👣 : %d  |\n", WHITE, data->count);
	ft_printf("%s---------------\n", WHITE);
}

void	swap_move_left(t_data *data, int *x, int *y)
{
	if (data->map[*y][*x - 1] == data->content.collect)
		data->count_tmar += 1;
	data->map[*y][*x - 1] = data->content.player;
	data->map[*y][*x] = data->content.space;
	data->count += 1;
	if (check_collect(data, data->map) == 0)
		fill_the_map_forsmall(*data, x, y);
	if (check_collect(data, data->map) != 0)
		fill_the_map(*data, x, y);
	ft_printf("%sMoves 👣 : %d  |\n", WHITE, data->count);
	ft_printf("%s---------------\n", WHITE);
}

void	swap_move_top(t_data *data, int *x, int *y)
{
	if (data->map[*y - 1][*x] == data->content.collect)
		data->count_tmar += 1;
	data->map[*y - 1][*x] = data->content.player;
	data->map[*y][*x] = data->content.space;
	data->count += 1;
	if (check_collect(data, data->map) == 0)
		fill_the_map_forsmall(*data, x, y);
	if (check_collect(data, data->map) != 0)
		fill_the_map(*data, x, y);
	ft_printf("%sMoves 👣 : %d  |\n", WHITE, data->count);
	ft_printf("%s---------------\n", WHITE);
}

void	swap_move_down(t_data *data, int *x, int *y)
{
	if (data->map[*y + 1][*x] == data->content.collect)
		data->count_tmar += 1;
	data->map[*y + 1][*x] = data->content.player;
	data->map[*y][*x] = data->content.space;
	data->count += 1;
	if (check_collect(data, data->map) == 0)
		fill_the_map_forsmall(*data, x, y);
	if (check_collect(data, data->map) != 0)
		fill_the_map(*data, x, y);
	ft_printf("%sMoves 👣 : %d  |\n", WHITE, data->count);
	ft_printf("%s---------------\n", WHITE);
}
