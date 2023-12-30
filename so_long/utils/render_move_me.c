/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move_me.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:38:30 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/30 17:45:20 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	input_key(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("\033[97mThe Game is ended 💀.\n");
		end(data);
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(data);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(data);
	if (keycode == KEY_W || keycode == KEY_TOP)
		move_top(data);
	if (keycode == KEY_S || keycode == KEY_BOTTOM)
		move_down(data);
	return (0);
}

void	move_right(t_data *data)
{
	int	pos_x;
	int	pos_y;
	int	check;
	int	x;
	int	y;

	check = 0;
	check = ft_check_whereis_p(data->map, 'P', &pos_y, &pos_x);
	if (check == 1)
	{
		if (data->map[pos_y][pos_x + 1] != data->content.wall)
		{
			if (data->map[pos_y][pos_x + 1] != data->content.exit)
			{
				if (data->map[pos_y][pos_x + 1] == data->content.collect)
				{
					data->count_tmar += 1;
					ft_printf("------------------\n");
					ft_printf("🥶Collect EXTA : %d\n", data->count_tmar);
					ft_printf("------------------\n");
				}
				data->map[pos_y][pos_x + 1] = data->content.player;
				data->map[pos_y][pos_x] = data->content.space;
				data->count += 1;
				ft_printf("\033[97m👣Moves : %d\n", data->count);
				if (check_collect(data, data->map) == 0)
					fill_the_map_forsmallright(*data, &x, &y);
				if (check_collect(data, data->map) != 0)
					fill_the_map_forright(*data, &x, &y);
			}
			else
			{
				if (check_collect(data, data->map) == 0
					&& data->map[pos_y][pos_x + 1] == data->content.exit)
				{
					data->count += 1;
					ft_printf("👣Moves : %d", data->count);
					data->map[pos_y][pos_x + 1] = data->content.player;
					data->map[pos_y][pos_x] = data->content.space;
					ft_printf("\033[97m\nGAME WON with 👣 %d Moves\nAnd"
						"Collect : 🥶 %d", data->count, data->count_tmar);
					end(data);
				}
			}
		}
	}
}

void	move_left(t_data *data)
{
	int	pos_x;
	int	pos_y;
	int	check;
	int	x;
	int	y;

	check = 0;
	check = ft_check_whereis_p(data->map, 'P', &pos_y, &pos_x);
	if (check == 1)
	{
		if (data->map[pos_y][pos_x - 1] != data->content.wall)
		{
			if (data->map[pos_y][pos_x - 1] != data->content.exit)
			{
				if (data->map[pos_y][pos_x - 1] == data->content.collect)
				{
					data->count_tmar += 1;
					ft_printf("------------------\n");
					ft_printf("🥶Collect EXTA : %d\n", data->count_tmar);
					ft_printf("------------------\n");
				}
				data->map[pos_y][pos_x - 1] = data->content.player;
				data->map[pos_y][pos_x] = data->content.space;
				data->count += 1;
				ft_printf("\033[97m👣Moves : %d\n", data->count);
				if (check_collect(data, data->map) == 0)
					fill_the_map_forsmallleft(*data, &x, &y);
				if (check_collect(data, data->map) != 0)
					fill_the_map_forleft(*data, &x, &y);
			}
			else
			{
				if (check_collect(data, data->map) == 0
					&& data->map[pos_y][pos_x - 1] == data->content.exit)
				{
					data->count += 1;
					ft_printf("👣Moves : %d", data->count);
					data->map[pos_y][pos_x - 1] = data->content.player;
					data->map[pos_y][pos_x] = data->content.space;
					ft_printf("\033[97m\nGAME WON with 👣 %d Moves"
						"\nAnd Collect : 🥶 %d", data->count, data->count_tmar);
					end(data);
				}
			}
		}
	}
}

void	move_top(t_data *data)
{
	int	pos_x;
	int	pos_y;
	int	check;
	int	x;
	int	y;

	check = 0;
	check = ft_check_whereis_p(data->map, 'P', &pos_y, &pos_x);
	if (check == 1)
	{
		if (data->map[pos_y - 1][pos_x] != data->content.wall)
		{
			if (data->map[pos_y - 1][pos_x] != data->content.exit)
			{
				if (data->map[pos_y - 1][pos_x] == data->content.collect)
				{
					data->count_tmar += 1;
					ft_printf("------------------\n");
					ft_printf("🥶Collect EXTA : %d\n", data->count_tmar);
					ft_printf("------------------\n");
				}
				data->map[pos_y - 1][pos_x] = data->content.player;
				data->map[pos_y][pos_x] = data->content.space;
				data->count += 1;
				ft_printf("\033[97m👣Moves : %d\n", data->count);
				if (check_collect(data, data->map) == 0)
					fill_the_map_forsmalltop(*data, &x, &y);
				if (check_collect(data, data->map) != 0)
					fill_the_map_fortop(*data, &x, &y);
			}
			else
			{
				if (check_collect(data, data->map) == 0
					&& data->map[pos_y - 1][pos_x] == data->content.exit)
				{
					data->count += 1;
					ft_printf("👣Moves : %d", data->count);
					data->map[pos_y - 1][pos_x] = data->content.player;
					data->map[pos_y][pos_x] = data->content.space;
					ft_printf("\033[97m\nGAME WON with 👣"
						"%d Moves\nAnd Collect : 🥶 %d",
						data->count, data->count_tmar);
					end(data);
				}
			}
		}
	}
}

void	move_down(t_data *data)
{
	int	pos_x;
	int	pos_y;
	int	check;
	int	x;
	int	y;

	check = 0;
	check = ft_check_whereis_p(data->map, 'P', &pos_y, &pos_x);
	if (check == 1)
	{
		if (data->map[pos_y + 1][pos_x] != data->content.wall)
		{
			if (data->map[pos_y + 1][pos_x] != data->content.exit)
			{
				if (data->map[pos_y + 1][pos_x] == data->content.collect)
				{
					data->count_tmar += 1;
					ft_printf("------------------\n");
					ft_printf("🥶Collect EXTA : %d\n", data->count_tmar);
					ft_printf("------------------\n");
				}
				data->map[pos_y + 1][pos_x] = data->content.player;
				data->map[pos_y][pos_x] = data->content.space;
				data->count += 1;
				ft_printf("\033[97m👣Moves : %d\n", data->count);
				if (check_collect(data, data->map) == 0)
					fill_the_map_forsmalldown(*data, &x, &y);
				if (check_collect(data, data->map) != 0)
					fill_the_map_fordown(*data, &x, &y);
			}
			else
			{
				if (check_collect(data, data->map) == 0
					&& data->map[pos_y + 1][pos_x] == data->content.exit)
				{
					data->count += 1;
					ft_printf("👣Moves : %d", data->count);
					data->map[pos_y + 1][pos_x] = data->content.player;
					data->map[pos_y][pos_x] = data->content.space;
					ft_printf("\033[97m\nGAME WON with 👣 %d Moves\n"
						"And Collect : 🥶 %d", data->count, data->count_tmar);
					end(data);
				}
			}
		}
	}
}
