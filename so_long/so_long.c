/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:14:14 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/28 19:43:22 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	print_err()
{
	ft_printf("%sMap Invalide %sX\n", WHITE, RED_NEW);
}
int	ft_free(t_data *data)
{
	ft_printf("The Game is ended.\n");
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(EXIT_FAILURE);
}
int	end(t_data *data)
{
	int		i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		data->map[i] = NULL;
	}
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

void	*print_string(char *str)
{
	ft_printf("%s%s",WHITE, str);
	exit(EXIT_FAILURE);
}
void	init_variables(t_data *data)
{
	data->count_tmar = 0;
	data->content.count_p = 0;
	data->content.count_e = 0;
	data->content.count_c = 0;
}

void check_height_width(char **map, int *x, int *y)
{
    *y = 0;
    *x = 0;
    while (map[*x][*y])
        (*x)++;
    ft_printf("X : %d", *x);
    *x = 0;
    while (map[*x][*y])
        (*y)++;
    ft_printf("Y : %d", *y);
}

void	leaks(void)
{
	system("leaks so_long");
}
void	call_render(char **str, t_data *data)
{	
	data->count = 0;
	init_variables(data);
	set_content(&(data->content));
	data->map = map_core(str, data);
	int x = 0;
	int y = 0;
	data->map_tmp = get_clone(data);
	check_if_can_play(data->map_tmp, data);
	y = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_free_map(data);
		ft_free_second_map(data);
		exit(EXIT_FAILURE);
	}
	set_image(data);
	data->mlx_win = mlx_new_window(data->mlx, data->width * (data->imgs.width), ((data->height + 1) * data->imgs.height), "So_long");
	if (data->mlx_win == NULL)
	{
		ft_free_map(data);
		ft_free_second_map(data);
		free(data->mlx);
		exit(EXIT_FAILURE);
	}
	fill_the_map(*data, &x, &y);
	mlx_hook(data->mlx_win, 2, 0, &input_key, data);
	mlx_hook(data->mlx_win, 17, 0, &ft_free, data);
	mlx_loop(data->mlx);
	end(data);
}
int main(int argc, char **argv)
{
	t_data	data;
	atexit(leaks);
	args_handler(argc);
	int i = 0;
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
		{
			print_string("Message Empty.\n");
			return (0);
		}
		i = check_map_ber(argv[1]);
		if (i == 0)
			print_err();
		else if (i == 2)
			print_string("Right syntax <file.ber>");
		else
		{
			call_render(argv, &data);
		}
	}
	return 0;
}
