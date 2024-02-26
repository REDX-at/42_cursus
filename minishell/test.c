/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:19:28 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/26 18:50:09 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// write str
int ft_putstr_fda(char *str, int fd)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
    return (i);
}

typedef struct s_test
{
    int fd;
    char *str;
}   t_test;

void    child_process()
{
    int pid;
    t_test cmd;

    cmd.str = "holla\n";
    pid = fork();
    if (pid == 0)
    {
        cmd.fd = dup2(1, 0);
        ft_putstr_fda("from child ", cmd.fd);
        ft_putstr_fda(cmd.str, cmd.fd);
        printf("%d\n", cmd.fd);
    }
    else
    {
        cmd.str = "hello\n";
        ft_putstr_fda(cmd.str, cmd.fd);
        printf("from parrent : %s\n", cmd.str);
    }
    close(cmd.fd);
}

int main()
{
    child_process();
    return (0);
}