/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exe_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:42:02 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/19 19:21:13 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd *list_test(void) 
{
    t_cmd *cmd = malloc(sizeof(t_cmd));
    cmd->path = "/bin/ls";
    cmd->cmd = "ls";
	cmd->is_builtin = true;
    cmd->next = malloc(sizeof(t_cmd));

    cmd->next->path = "/bin/ls";
    cmd->next->cmd = "ls";
	cmd->is_builtin = false;
    cmd->next->next = malloc(sizeof(t_cmd));

    cmd->next->next->path = "/bin/ls";
    cmd->next->next->cmd = "ls";
	cmd->next->next->str = "world";
	cmd->is_builtin = true;
    cmd->next->next->next = NULL;

    return cmd;
}

void test_exe(t_cmd *cmd)
{
	int pipefd[2];
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	while (cmd)
	{
		char *argv[] = {cmd->path, NULL};
		if (cmd->next)
		{
			pid_t pid = fork();
			if (pid == 0)
			{
				dup2(pipefd[1], 1);
				close(pipefd[0]);
				close(pipefd[1]);
				if (ft_strcmp(cmd->cmd, "pwd"))
				{
					ft_pwd();
				}
				else if (ft_strcmp(cmd->cmd, "echo"))
				{
					char *const argv[] = {cmd->path, cmd->str, NULL};
					execve(cmd->path, argv, NULL);
				}
				else if (ft_strcmp(cmd->cmd, "ls"))
					execve(cmd->path, argv, NULL);
				else
					printf("cmd not found\n");
			}
			else
			{
				dup2(pipefd[0], 0);
				close(pipefd[0]);
				close(pipefd[1]);
				waitpid(0, NULL, 0);
				cmd = cmd->next;
			}
		}
		else
		{
			if (ft_strcmp(cmd->cmd, "pwd"))
			{
				ft_pwd();
			}
			else if (ft_strcmp(cmd->cmd, "echo"))
			{
				char *const argv[] = {cmd->path, cmd->str, NULL};
				execve(cmd->path, argv, NULL);
			}
			else if (ft_strcmp(cmd->cmd, "ls"))
				execve(cmd->path, argv, NULL);
			else
				printf("cmd not found\n");
		}
		cmd = cmd->next;
	}
	exit(0);
}