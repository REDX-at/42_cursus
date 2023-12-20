/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:44:14 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/20 21:43:55 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Tools/Tools.h"

int	main(int argc, char **argv)
{
	int				i;
	int				start;
	pid_t			server_pid;
	unsigned char	character;

	if (argc != 3)
	{
		ft_printf("%s ERROR %s Usage: %s <server_pid>\n", RED, WHITE, argv[0]);
		return (EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	start = 0;
	if (argv[2][0] == '\0')
	{
		ft_printf("%s ERROR %s Message is Empty.\n", RED, WHITE);
		return (EXIT_FAILURE);
	}
	while (argv[2][start])
	{
		i = 7;
		character = argv[2][start];
		while (i >= 0)
		{
			if (((character >> i) & 1) == 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(150);
			i--;
		}
		start++;
	}
	return (EXIT_FAILURE);
}
