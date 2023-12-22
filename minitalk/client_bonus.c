/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:12:57 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/22 15:14:42 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Tools/Tools.h"

int	g_check = 0;

void	sig_print(int signal)
{
	(void)signal;
	g_check = 1;
}

void	just_print_err(void)
{
	char	*str;
	char	*pid_err;

	str = "Failed to send signal";
	pid_err = "Or PID invalide";
	ft_printf("%s ERROR %s %s %s\n", RED, WHITE, str, pid_err);
}

void	send_character(pid_t server_pid, unsigned char character)
{
	int			i;
	static int	deja;

	i = 7;
	while (i >= 0)
	{
		if (((character >> i) & 1) == 0)
		{
			if (kill(server_pid, SIGUSR1) == -1 && deja == 0)
			{
				deja = 1;
				just_print_err();
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1 && deja == 0)
			{
				deja = 1;
				just_print_err();
			}
		}
		usleep(150);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int				start;
	pid_t			server_pid;

	if (argc != 3)
	{
		ft_printf("%s ERROR %sUsage: %s <server_pid>\n", RED, WHITE, argv[0]);
		return (EXIT_FAILURE);
	}
	signal(SIGUSR2, &sig_print);
	server_pid = ft_atoi(argv[1]);
	start = 0;
	if (argv[2][0] == '\0')
	{
		ft_printf("%s ERROR %sMessage is Empty.\n", RED, WHITE);
		return (EXIT_FAILURE);
	}
	while (argv[2][start])
	{
		send_character(server_pid, argv[2][start]);
		start++;
	}
	if (g_check == 1)
		ft_printf("%s DONE %s Signal received.\n", GREEN, WHITE);
	return (EXIT_FAILURE);
}
