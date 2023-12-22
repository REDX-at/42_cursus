/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:14:05 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/22 16:05:51 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Tools/Tools.h"

void	process_character(unsigned char *character, int *i)
{
	write(1, character, 1);
	*character = 0;
	*i = 7;
}

void	set_back(struct variables *helps)
{
	helps->client_pid = helps->current_pid;
	helps->receive = 0;
	helps->character = 0;
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static struct variables	helps;
	static int				i = 7;

	(void)context;
	if (!helps.client_pid)
		helps.client_pid = info->si_pid;
	helps.current_pid = info->si_pid;
	if (helps.current_pid != helps.client_pid)
	{
		set_back(&helps);
		i = 7;
	}
	if (!helps.receive)
	{
		kill(helps.current_pid, SIGUSR2);
		helps.receive = 1;
	}
	if (signal == SIGUSR1)
		helps.character |= (0 << i);
	else
		helps.character |= (1 << i);
	i--;
	if (i < 0)
		process_character(&helps.character, &i);
}

void	just_banner(void)
{
	char	*str;
	char	*str2;

	str2 = "---------------- ";
	str = "Minitalk Server PID : ";
	ft_printf("%s __  __ ___ _  _ ___   _____ _   _    _  __\n", GREEN_NEW);
	ft_printf("%s|  \\/  |_ _| \\| |_ _| |_   _/_\\ | |  | |/ /\n", GREEN_NEW);
	ft_printf("%s| |\\/| || || .` || |    | |/ _ \\| |__| ' < \n", GREEN_NEW);
	ft_printf("%s|_|  |_|___|_|\\_|___|   |_/_/ \\_|____|_|\\_\\\n", GREEN_NEW);
	ft_printf("\n");
	ft_printf("%s%s%sR-E-D-X%s-----------------", WHITE, str2, RED_NEW, WHITE);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("%s WAITING %s%s[  %d  ]\n", GREEN, WHITE, str, getpid());
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
