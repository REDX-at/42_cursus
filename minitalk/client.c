/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:44:14 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/18 20:51:19 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <libc.h>
#include "libft.h"
#include "ft_printf.h"

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}
void set_client_pid(pid_t pid)
{
    static pid_t client_pid = 0;
    client_pid = pid;
}

int	main(int argc, char **argv)
{
	int	i;
	int	server_pid;

	ft_printf("    __  ___  ____   _   __   ____   ______   ___       __       __ __\n");
    ft_printf("   /  |/  / /  _/  / | / /  /  _/  /_  __/  /   |     / /      / //_/\n");
    ft_printf("  / /|_/ /  / /   /  |/ /   / /     / /    / /| |    / /      / ,<   \n");
    ft_printf(" / /  / / _/ /   / /|  /  _/ /     / /    / ___ |   / /___   / /| |  \n");
    ft_printf("/_/  /_/ /___/  /_/ |_/  /___/    /_/    /_/  |_|  /_____/  /_/ |_| \n");
	printf("\n");
	i = 0;
	if (argc != 3)
	{
		printf("\033[30m\033[101m ERROR \033[0m \033[97mUsage: %s <server_pid>\n", argv[0]);	
		return (EXIT_FAILURE);
	}
	server_pid = atoi(argv[1]);
	kill(server_pid(getpid()));
	set_client_pid(getpid());
	if (argv[2][0] == '\0')
    {
        printf("Error: Message is empty.\n");
        return (EXIT_FAILURE);
    }
	ft_printf("\033[30m\033[102m DONE \033[0m \033[97mSignal Received.\n");
	while (argv[2][i])
		send_signal(server_pid, argv[2][i++]);
	return (EXIT_FAILURE);
}
