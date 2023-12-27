/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 08:21:31 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/27 12:57:29 by aitaouss         ###   ########.fr       */
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
	}
	if (keycode == KEY_A)
        move_left(data);
	if (keycode == KEY_W)
		ft_printf("W");
	if (keycode == KEY_S)
		ft_printf("S");
	if (keycode == KEY_D)
        move_right(data);
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
                ft_printf("%d", data->count);
                fill_the_map(*data, &x, &y);
            }
            else
            {
                if (check_collect(data, data->map) == 0 && data->map[posY][posX + 1] == data->content.exit)
                {
                    data->map[posY][posX + 1] = data->content.player;
                    data->map[posY][posX] = data->content.space;
                    printf("Nadi jbti lgame B %d", data->count);
                    end(data);
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
        if (data->map[posY][posX - 1] != data->content.wall || data->map[posY][posX - 1] != data->content.collect)
        {
            if (data->map[posY][posX - 1] != data->content.exit)
            {
                data->map[posY][posX - 1] = data->content.player;
                data->map[posY][posX] = data->content.space;
                data->count += 1;
                ft_printf("%d", data->count);
                fill_the_map(*data, &x, &y);
            }
            else
            {
                if (check_collect(data, data->map) == 0 && data->map[posY][posX + 1] == data->content.exit)
                {
                    data->map[posY][posX + 1] = data->content.player;
                    data->map[posY][posX] = data->content.space;
                    printf("Nadi jbti lgame B %d", data->count);
                    end(data);
                }
            }
        }
        
    }
}
// int main() {
//     t_data *data = (t_data *)malloc(sizeof(t_data));
    
//     char *map[] = {
//         "111111",
//         "100011",
//         "1101P1",
//         "101011",
//         "100011",
//         "111111",
//         NULL
//     };
//     data->map = map;
//     int x;
//     int y;
//     if (ft_check_whereis_p(data->map, 'P', &y, &x)) {
//         printf("The p coordination : \n");
//     }
//     printf("%d %d", y, x);
//     return 0;
// }