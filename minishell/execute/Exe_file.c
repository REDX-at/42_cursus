/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exe_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:42:02 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/22 01:16:11 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd *list_test(void) 
{
    t_cmd *cmd = malloc(sizeof(t_cmd));
    cmd->cmd = "ls";
	cmd->str = NULL;
	cmd->flag = "-l";
	cmd->is_builtin = true;
    cmd->next = malloc(sizeof(t_cmd));

    cmd->next->cmd = "echo";
	cmd->next->str = "hello";
    cmd->next->flag = NULL;
	cmd->next->is_builtin = false;
	
    cmd->next->next = malloc(sizeof(t_cmd));
    cmd->next->next->cmd = "echo";
	cmd->next->next->str = "alo";
	cmd->next->next->flag = "-l";
	cmd->is_builtin = true;
    cmd->next->next->next = NULL;

    return cmd;
}

int execute_part(t_cmd *cmd)
{
	int flag = 0;
	int pipefd[2];
	while (cmd)
	{
		if (cmd->next)
		{
			if (pipe(pipefd) == -1)
			{
				perror("pipe");
				exit(EXIT_FAILURE);
			}
		}
		pid_t pid = fork();
		if (pid == 0)
		{
			char *argv[] = {cmd->cmd, NULL};
			if (cmd->next)
				dup2(pipefd[1], 1);
			if (ft_strcmp(cmd->cmd, "ls"))
			{
				char *argv[] = {cmd->cmd, cmd->flag, NULL};
				creat_shild(cmd, pipefd, argv);
				flag = 1;
			}
			if (ft_strcmp(cmd->cmd, "pwd"))
			{
				char	*argv[] = {cmd->cmd, NULL};
				creat_shild(cmd, pipefd, argv);
				flag = 1;
			}
			if (ft_strcmp(cmd->cmd, "echo"))
			{
				char *argv[] = {cmd->cmd, cmd->str, NULL};
				creat_shild(cmd, pipefd, argv);
				flag = 1;
			}
			if (ft_strcmp(cmd->cmd, "grep"))
			{
				char *argv[] = {cmd->cmd, cmd->str, NULL};
				creat_shild(cmd, pipefd, argv);
				flag = 1;
			}
		}
		else
		{
			waitpid(pid, NULL, 0);
			close(pipefd[1]);
		}
		cmd = cmd->next;
	}
	return 0;
}