/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:14:14 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/23 22:45:01 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_lenght;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixels / 8));
	*(unsigned int*)dst = color;
}
void	print_err()
{
	printf("%sMap Invalide %sX\n", WHITE, RED_NEW);
}

void	print_string(char *str)
{
	printf("%s%s",WHITE, str);
	exit(1);
}
int main(int argc, char **argv)
{
	args_handler(argc);
	int i = 0;
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			print_string("Message Empty.\n");
		i = check_map_ber(argv[1]);
		if (i == 0)
			print_err();
		else
			print_string("There is your Map\n");
	}
}