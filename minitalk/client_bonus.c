/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:12:57 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/20 22:46:08 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Tools/Tools.h"

void	sig_print(int signal)
{
	(void)signal;
	ft_printf("%s DONE %s Signal received.\n", GREEN, WHITE);
}

int main(int argc, char **argv)
{
    int i;
    int start;
    pid_t server_pid;
    unsigned char character;

    if (argc != 3)
    {
        ft_printf("\033[30m\033[101m ERROR \033[0m \033[97mUsage: %s <server_pid>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    signal(SIGUSR2, &sig_print);

    server_pid = ft_atoi(argv[1]);
    start = 0;

    if (argv[2][0] == '\0')
    {
        ft_printf("\033[30m\033[101m ERROR \033[0m \033[97mMessage is Empty.\n");
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

