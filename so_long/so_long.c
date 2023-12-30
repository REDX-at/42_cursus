/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:14:14 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/30 10:37:15 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	print_err(void)
{
	ft_printf("%sMap Invalide %sX\n", WHITE, RED_NEW);
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
	ft_printf("%s%s", WHITE, str);
	exit(EXIT_FAILURE);
}

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	atexit(leaks);
	args_handler(argc);
	i = 0;
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
	return (0);
}
