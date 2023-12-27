/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 08:21:31 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/27 14:50:16 by aitaouss         ###   ########.fr       */
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
		ft_printf("The Game is ended.\n");
		mlx_destroy_window(data->mlx, data->mlx_win);
        exit(0);
        //end(data);
	}
	if (keycode == KEY_D)
        move_right(data);
	if (keycode == KEY_A)
        move_left(data);
	if (keycode == KEY_W)
		move_top(data);
	if (keycode == KEY_S)
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
                data->map[posY][posX + 1] = data->content.player;
                data->map[posY][posX] = data->content.space;
                data->count += 1;
                ft_printf("Moves : %d\n", data->count);
                fill_the_map(*data, &x, &y);
            }
            else
            {
                if (check_collect(data, data->map) == 0 && data->map[posY][posX + 1] == data->content.exit)
                {
                    data->map[posY][posX + 1] = data->content.player;
                    data->map[posY][posX] = data->content.space;
                    ft_printf("Nadi jbti lgame B %\n", data->count);
                    mlx_destroy_window(data->mlx, data->mlx_win);
                    exit(EXIT_SUCCESS);
                    // end(data);
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
                data->map[posY][posX - 1] = data->content.player;
                data->map[posY][posX] = data->content.space;
                data->count += 1;
                ft_printf("Moves : %d\n", data->count);
                fill_the_map(*data, &x, &y);
            }
            else
            {
                if (check_collect(data, data->map) == 0 && data->map[posY][posX - 1] == data->content.exit)
                {
                    data->map[posY][posX - 1] = data->content.player;
                    data->map[posY][posX] = data->content.space;
                    ft_printf("Nadi jbti lgame B %d\n", data->count);
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
                data->map[posY - 1][posX] = data->content.player;
                data->map[posY][posX] = data->content.space;
                data->count += 1;
                ft_printf("Moves : %d\n", data->count);
                fill_the_map(*data, &x, &y);
            }
            else
            {
                if (check_collect(data, data->map) == 0 && data->map[posY - 1][posX] == data->content.exit)
                {
                    data->map[posY - 1][posX] = data->content.player;
                    data->map[posY][posX] = data->content.space;
                    ft_printf("Nadi jbti lgame B %d\n", data->count);
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
                data->map[posY + 1][posX] = data->content.player;
                data->map[posY][posX] = data->content.space;
                data->count += 1;
                ft_printf("Moves : %d\n", data->count);
                fill_the_map(*data, &x, &y);
            }
            else
            {
                if (check_collect(data, data->map) == 0 && data->map[posY + 1][posX] == data->content.exit)
                {
                    data->map[posY + 1][posX] = data->content.player;
                    data->map[posY][posX] = data->content.space;
                    ft_printf("Nadi jbti lgame B %d\n", data->count);
                    mlx_destroy_window(data->mlx, data->mlx_win);
                    exit(EXIT_SUCCESS);
                }
            }
        }
    }
}
