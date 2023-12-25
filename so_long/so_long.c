/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:14:14 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/25 18:10:04 by aitaouss         ###   ########.fr       */
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
		free(data->map);
		mlx_destroy_image(data->mlx, data->imgs.img_floor);
	}
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	exit(0);
}

void	*print_string(char *str)
{
	printf("%s%s",WHITE, str);
	return (0);
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
			// data.mlx = mlx_init();
			set_content(&(data.content));
			data.map = map_core(argv, &data);
			// data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "So_long");
    		// data.img = mlx_new_image(data.mlx, 1920, 1080);
			// data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixels, &data.line_lenght, &data.endian);
			// mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
			// mlx_loop(data.mlx);
		}
	}
}