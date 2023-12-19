/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:11:28 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/19 21:53:30 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <libc.h>
#include "libft.h"
#include "ft_printf.h"

// pid_t g_client_pid = 0;

// pid_t	get_c_pid(void)
// {
// 	return g_client_pid;
// }

// void	set_c_pid(pid_t pid)
// {
// 	g_client_pid = pid;
// }	
// void	signal_handler(int signum, siginfo_t *info, void *context)
// {
// 	static unsigned char	bit;
// 	static int				i;
// 	static pid_t			last_c_pid = 0;
	
// 	(void)info;
// 	(void)context;
	
// 	// if (signum == SIGUSR1)
// 	// {
// 	// 	ft_printf("\033[30m\033[43m RESET \033[0m \033[97mClient PID changed. Resetting...\n");
// 	// 	last_c_pid = 0;
// 	// 	return ;
// 	// }
	
// 	pid_t					current_c_pid = get_c_pid();
	
// 	if (current_c_pid != last_c_pid)
// 	{
// 		ft_printf("\033[30m\033[43m RESET \033[0m \033[97mClient PID changed. Resetting...\n");
// 		last_c_pid = current_c_pid;
// 		bit = 0;
// 		i = 0;
// 	}
// 	bit |= (signum == SIGUSR2);
// 	i++;
// 	if (i == 8)
// 	{
// 		write(1, &bit, 1);
// 		//ft_printf("%c", bit);
// 		bit = 0;
// 		i = 0;
// 	}
// 	else
// 		bit <<= 1;
// }

// int	main(void)
// {
// 	struct sigaction	action;

	// ft_printf("    __  ___  ____   _   __   ____   ______   ___       __       __ __\n");
    // ft_printf("   /  |/  / /  _/  / | / /  /  _/  /_  __/  /   |     / /      / //_/\n");
    // ft_printf("  / /|_/ /  / /   /  |/ /   / /     / /    / /| |    / /      / ,<   \n");
    // ft_printf(" / /  / / _/ /   / /|  /  _/ /     / /    / ___ |   / /___   / /| |  \n");
    // ft_printf("/_/  /_/ /___/  /_/ |_/  /___/    /_/    /_/  |_|  /_____/  /_/ |_| \n");
	// printf("\n");
	// ft_printf("\033[30m\033[42m DONE \033[0m \033[97mMinitalk Server PIP : [ %d ]\n", getpid());
// 	action.sa_sigaction = &signal_handler;
// 	action.sa_flags = SA_SIGINFO;
	
// 	sigaction(SIGUSR2, &action, NULL);
// 	sigaction(SIGUSR1, &action, NULL);
// 	while (1)
// 		pause();
// 	return (EXIT_SUCCESS);
// }
void handle_signal(int signal, siginfo_t *info, void *context)
{
    static unsigned char    character = 0;
    static pid_t            current_pid;
    static pid_t            client_pid;
    static int                i = 7;

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
	
void print_server()
{
	ft_printf("    __  ___  ____   _   __   ____   ______   ___       __       __ __\n");
    ft_printf("   /  |/  / /  _/  / | / /  /  _/  /_  __/  /   |     / /      / //_/\n");
    ft_printf("  / /|_/ /  / /   /  |/ /   / /     / /    / /| |    / /      / ,<   \n");
    ft_printf(" / /  / / _/ /   / /|  /  _/ /     / /    / ___ |   / /___   / /| |  \n");
    ft_printf("/_/  /_/ /___/  /_/ |_/  /___/    /_/    /_/  |_|  /_____/  /_/ |_| \n");
	printf("\n");
	ft_printf("\033[30m\033[42m WAITING \033[0m \033[97mMinitalk Server PIP : [ %d ]\n", getpid());
}

int main(void)
{
    struct sigaction    action;

    action.sa_sigaction = &handle_signal;
    action.sa_flags = SA_SIGINFO;

    print_server();
    

    while (1)
    {
        sigaction(SIGUSR2, &action, NULL);
        sigaction(SIGUSR1, &action, NULL);
        pause();

    }
    return (0);
}
