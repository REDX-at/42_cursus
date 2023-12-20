/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:14:05 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/20 22:37:24 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Tools/Tools.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	character = 0;
	static pid_t			current_pid;
	static pid_t			client_pid;
	static int				i = 0;
	static int				receive = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	current_pid = info->si_pid;
	if (current_pid != client_pid)
	{
		client_pid = current_pid;
		receive = 0;
		character = 0;
		i = 7;
	}
	if (!receive)
	{
		kill(current_pid, SIGUSR2);
		receive = 1;
	}
	if (signal == SIGUSR1)
		character |= (0 << i);
	else
		character |= (1 << i);
	i--;
	if (i < 0)
	{
		write(1, &character, 1);
		character = 0;
		i = 7;
	}
}

void	just_banner(void)
{
	ft_printf("    __  ___  ____   _   __   ____   ______   ___       __       __ __\n");
	ft_printf("   /  |/  / /  _/  / | / /  /  _/  /_  __/  /   |     / /      / //_/\n");
	ft_printf("  / /|_/ /  / /   /  |/ /   / /     / /    / /| |    / /      / ,<   \n");
	ft_printf(" / /  / / _/ /   / /|  /  _/ /     / /    / ___ |   / /___   / /| |  \n");
	ft_printf("/_/  /_/ /___/  /_/ |_/  /___/    /_/    /_/  |_|  /_____/  /_/ |_| \n");
	ft_printf("\n");
	ft_printf("\033[30m\033[42m WAITING \033[0m \033[97mMinitalk Server PID : [ %d ]\n", getpid());
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = &handle_signal;
	action.sa_flags = SA_SIGINFO;
	just_banner();
	while (1)
	{
		sigaction(SIGUSR2, &action, NULL);
		sigaction(SIGUSR1, &action, NULL);
		pause();
	}
	return (0);
}
