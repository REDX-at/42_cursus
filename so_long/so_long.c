/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:14:14 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/26 19:53:26 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	print_err()
{
	printf("%sMap Invalide %sX\n", WHITE, RED_NEW);
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
		data->map[i] = NULL;
		free(data->map);
		mlx_destroy_image(data->mlx, data->imgs.img_floor);
		mlx_destroy_image(data->mlx, data->imgs.img_collect);
		mlx_destroy_image(data->mlx, data->imgs.img_wall);
		mlx_destroy_image(data->mlx, data->imgs.img_exit);
		mlx_destroy_image(data->mlx, data->imgs.img_player);
		mlx_destroy_image(data->mlx, data->mlx_win);
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
	// data->content.exit = NULL;
	// data->content.collect = NULL;
	// data->content.player = NULL;
	// data->content.wall = NULL;
	// data->content.space = NULL;
	data->content.count_p = 0;
	data->content.count_e = 0;
	data->content.count_c = 0;
}
int main(int argc, char **argv)
{
	t_data		data;
	
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
			data.count = 0;
			init_variables(&data);
			set_content(&(data.content));
			data.map = map_core(argv, &data);
			data.mlx = mlx_init();
			if (!data.mlx)
				return 0;
			char	*xpmjust = "brick.xpm";
			data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "So_long");
			data.img = mlx_xpm_file_to_image(data.mlx, xpmjust, &data.width, &data.height);
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
			mlx_hook(data.mlx_win, 2, 0, input_key, &data);
			mlx_loop(data.mlx);
		}
	}
	return 0;
}