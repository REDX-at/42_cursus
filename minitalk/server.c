/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:11:28 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/18 20:49:19 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <libc.h>
#include "libft.h"
#include "ft_printf.h"

pid_t	get_c_pid(void)
{
	static pid_t client_pid = 0;
	return client_pid;
}

void	set_c_pid(pid_t pid)
{
	static pid_t	client_pid = 0;
	client_pid = pid;
}	
void	signal_handler(int signum)
{
	static unsigned char	bit;
	static int				i;
	static pid_t			last_c_pid = 0;

	if (signum == SIGUSR1)
	{
		ft_printf("\033[30m\033[43m RESET \033[0m \033[97mClient PID changed. Resetting...\n");
		last_c_pid = 0;
		return ;
	}
	bit |= (signum == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", bit);
		bit = 0;
		i = 0;
	}
	else
		bit <<= 1;
	pid_t	current_c_pid = get_c_pid();
	if (current_c_pid != last_c_pid)
	{
		ft_printf("\033[30m\033[43m RESET \033[0m \033[97mClient PID changed. Resetting...\n");
		last_c_pid = current_c_pid;
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("    __  ___  ____   _   __   ____   ______   ___       __       __ __\n");
    ft_printf("   /  |/  / /  _/  / | / /  /  _/  /_  __/  /   |     / /      / //_/\n");
    ft_printf("  / /|_/ /  / /   /  |/ /   / /     / /    / /| |    / /      / ,<   \n");
    ft_printf(" / /  / / _/ /   / /|  /  _/ /     / /    / ___ |   / /___   / /| |  \n");
    ft_printf("/_/  /_/ /___/  /_/ |_/  /___/    /_/    /_/  |_|  /_____/  /_/ |_| \n");
	printf("\n");
	ft_printf("\033[30m\033[42m DONE \033[0m \033[97mMinitalk Server PIP : [ %d ]\n", getpid());
	action.sa_handler = &signal_handler;
	action.sa_flags = 0;
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
