/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:11:28 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/20 22:36:40 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <libc.h>
#include "./Tools/Tools.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	character = 0;
	static pid_t			current_pid;
	static pid_t			client_pid;
	static int				i = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	current_pid = info->si_pid;
	if (current_pid != client_pid)
	{
		client_pid = current_pid;
		character = 0;
		i = 7;
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
	char	*str;
	char	*str2;
	char	*two;
	char	*twot;
	char	*thre;
	char	*thret;
	char	*four;
	char	*fourf;
	char	*five;
	char	*fivef;
	
	str2 = "  ______   ___       __       __ __";
	str = "    __  ___  ____   _   __   ____ ";
	two = "   /  |/  / /  _/  / | / /  /  _/ ";
	twot = " /_  __/  /   |     / /      / //_/";
	thre = "  / /|_/ /  / /   /  |/ /   / /    ";
	thret = " / /    / /| |    / /      / ,<   ";
	four = " / /  / / _/ /   / /|  /  _/ /    ";
	fourf = " / /    / ___ |   / /___   / /| |  ";
	five = "/_/  /_/ /___/  /_/ |_/  /___/    /_/  ";
	fivef = "  /_/  |_|  /_____/  /_/ |_| ";
	ft_printf("%s%s\n", str, str2);
	ft_printf("%s%s\n", two, twot);
	ft_printf("%s%s\n", thre, thret);
	ft_printf("%s%s\n", four, fourf);
	ft_printf("%s%s\n", five, fivef);
	ft_printf("\n");
	ft_printf("%s WAITING %s Minitalk Server PID : [ %d ]\n", GREEN, WHITE, getpid());
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
