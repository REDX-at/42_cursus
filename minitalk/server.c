/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:11:28 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/22 15:32:20 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Tools/Tools.h"

void	process_character(unsigned char *character, int *i)
{
	write(1, character, 1);
	*character = 0;
	*i = 7;
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	character;
	static pid_t			current_pid;
	static pid_t			client_pid;
	static int				i = 7;

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
		process_character(&character, &i);
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
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
