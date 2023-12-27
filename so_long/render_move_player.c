/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 08:21:31 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/27 20:09:37 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_whereis_p(char **map, char p, int *row, int *col) 
{
	*row = 0;
	while (map[*row] != NULL)
	{
		*col = 0;
		while (map[*row][*col] != '\0')
		{
			if (map[*row][*col] == p)
				return 1;
			(*col)++;
		}
		(*row)++;
	}
	return 0;
}

int	input_key(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("\033[97mThe Game is ended 💀.\n");
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
		//end(data);
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
void    move_right(t_data *data)
{
	int posX;
	int posY;
	int check = 0;
	int x;
	int y;
	check = ft_check_whereis_p(data->map, 'P', &posY, &posX);
	if (check == 1)
	{
		if (data->map[posY][posX + 1] != data->content.wall)
		{
			if (data->map[posY][posX + 1] != data->content.exit)
			{
				if (data->map[posY][posX + 1] == data->content.collect)
                {
                    data->count_tmar += 1;
                    ft_printf("------------------\n");
					ft_printf("🌴Collect Tmra : %d\n", data->count_tmar);
					ft_printf("------------------\n");
				}
				data->map[posY][posX + 1] = data->content.player;
				data->map[posY][posX] = data->content.space;
				data->count += 1;
				ft_printf("\033[97m👣Moves : %d\n", data->count);
				if (check_collect(data, data->map) == 0)
					fill_the_map_forsmall(*data, &x, &y);
				if (check_collect(data, data->map) != 0)
					fill_the_map(*data, &x, &y);
			}
			else
			{
				if (check_collect(data, data->map) == 0 && data->map[posY][posX + 1] == data->content.exit)
				{
					data->map[posY][posX + 1] = data->content.player;
					data->map[posY][posX] = data->content.space;
					ft_printf("\033[97mNadi jbti lgame B : 👣%d Moves\nAnd Drbti : 🌴%d TMRAT", data->count, data->count_tmar);
					mlx_destroy_window(data->mlx, data->mlx_win);
					exit(EXIT_SUCCESS);
				}
			}
		}
	}
}
void    move_left(t_data *data)
{
	int posX;
	int posY;
	int check = 0;
	int x;
	int y;
	check = ft_check_whereis_p(data->map, 'P', &posY, &posX);
	if (check == 1)
	{
		if (data->map[posY][posX - 1] != data->content.wall)
		{
			if (data->map[posY][posX - 1] != data->content.exit)
			{
				if (data->map[posY][posX - 1] == data->content.collect)
                {
                    data->count_tmar += 1;
                    ft_printf("------------------\n");
					ft_printf("🌴Collect Tmra : %d\n", data->count_tmar);
					ft_printf("------------------\n");
				}
				data->map[posY][posX - 1] = data->content.player;
				data->map[posY][posX] = data->content.space;
				data->count += 1;
				ft_printf("\033[97m👣Moves : %d\n", data->count);
				if (check_collect(data, data->map) == 0)
					fill_the_map_forsmall(*data, &x, &y);
				if (check_collect(data, data->map) != 0)
					fill_the_map(*data, &x, &y);
			}
			else
			{
				if (check_collect(data, data->map) == 0 && data->map[posY][posX - 1] == data->content.exit)
				{
					data->map[posY][posX - 1] = data->content.player;
					data->map[posY][posX] = data->content.space;
					ft_printf("\033[97mNadi jbti lgame B : 👣%d Moves\nAnd Drbti : 🌴%d TMRAT", data->count, data->count_tmar);
					mlx_destroy_window(data->mlx, data->mlx_win);
					exit(EXIT_SUCCESS);
				}
			}
		}
	}
}
void    move_top(t_data *data)
{
	int posX;
	int posY;
	int check = 0;
	int x;
	int y;
	
	check = ft_check_whereis_p(data->map, 'P', &posY, &posX);
	if (check == 1)
	{
		if (data->map[posY - 1][posX] != data->content.wall)
		{
			if (data->map[posY - 1][posX] != data->content.exit)
			{
				if (data->map[posY - 1][posX] == data->content.collect)
				{
					data->count_tmar += 1;
					ft_printf("------------------\n");
					ft_printf("🌴Collect Tmra : %d\n", data->count_tmar);
					ft_printf("------------------\n");
				}
				data->map[posY - 1][posX] = data->content.player;
				data->map[posY][posX] = data->content.space;
				data->count += 1;
				ft_printf("\033[97m👣Moves : %d\n", data->count);
				if (check_collect(data, data->map) == 0)
					fill_the_map_forsmall(*data, &x, &y);
				if (check_collect(data, data->map) != 0)
					fill_the_map_fortop(*data, &x, &y);
			}
			else
			{
				if (check_collect(data, data->map) == 0 && data->map[posY - 1][posX] == data->content.exit)
				{
					data->map[posY - 1][posX] = data->content.player;
					data->map[posY][posX] = data->content.space;
					ft_printf("\033[97mNadi jbti lgame B : 👣%d Moves\nAnd Drbti : 🌴%d TMRATT", data->count, data->count_tmar);
					mlx_destroy_window(data->mlx, data->mlx_win);
					exit(EXIT_SUCCESS);
				}
			}
		}
	}
}
void    move_down(t_data *data)
{
	int posX;
	int posY;
	int check = 0;
	int x;
	int y;
	check = ft_check_whereis_p(data->map, 'P', &posY, &posX);
	if (check == 1)
	{
		if (data->map[posY + 1][posX] != data->content.wall)
		{
			if (data->map[posY + 1][posX] != data->content.exit)
			{
				if (data->map[posY + 1][posX] == data->content.collect)
				{
					data->count_tmar += 1;
					ft_printf("------------------\n");
					ft_printf("🌴Collect Tmra : %d\n", data->count_tmar);
					ft_printf("------------------\n");
				}
				data->map[posY + 1][posX] = data->content.player;
				data->map[posY][posX] = data->content.space;
				data->count += 1;
				ft_printf("\033[97m👣Moves : %d\n", data->count);
				if (check_collect(data, data->map) == 0)
					fill_the_map_forsmall(*data, &x, &y);
				if (check_collect(data, data->map) != 0)
					fill_the_map(*data, &x, &y);
			}
			else
			{
				if (check_collect(data, data->map) == 0 && data->map[posY + 1][posX] == data->content.exit)
				{
					data->map[posY + 1][posX] = data->content.player;
					data->map[posY][posX] = data->content.space;
					ft_printf("\033[97mNadi jbti lgame B : 👣%d Moves\nAnd Drbti : 🌴%d TMRAT", data->count, data->count_tmar);
					mlx_destroy_window(data->mlx, data->mlx_win);
					exit(EXIT_SUCCESS);
				}
			}
		}
	}
}
