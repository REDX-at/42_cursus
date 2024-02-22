/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exe_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:42:02 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/23 00:15:38 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_built_in(t_cmd *cmd, char **env)
{
	if (ft_strcmp(cmd->cmd, "cd"))
		ft_cd(cmd);
	else if (ft_strcmp(cmd->cmd, "pwd"))
		ft_pwd();
	else if (ft_strcmp(cmd->cmd, "echo"))
		ft_echo(cmd);
	else if (ft_strcmp(cmd->cmd, "env"))
		ft_env(env);
}

int execute_part(t_cmd *cmd, char **env)
{
	int flag = 0;
	int pipefd[2];
	int k = 0;
	pid_t pid[cmd->count_cmd];

	while (cmd)
	{
		if (cmd->count_cmd > 1)
		{
			int	i = 0;
			while (cmd->count_cmd > i)
			{
				if (pipe(pipefd) == -1)
				{
					perror("pipe");
					exit(EXIT_FAILURE);
				}
				i++;
			}
		}
		pid[k] = fork();
		if (pid[k] == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid[k] == 0)
		{
			if (k > 0)
				dup2(pipefd[0], 0);
			if (cmd->next && cmd->count_cmd > 1)
				dup2(pipefd[1], 1);
			if (cmd->cmd && ft_strcmp(cmd->cmd, "cd") || ft_strcmp(cmd->cmd, "pwd")||
				ft_strcmp(cmd->cmd, "echo") || ft_strcmp(cmd->cmd, "env"))
				execute_built_in(cmd, env);
			else
				creat_shild(cmd, pipefd, cmd->argv);
		}
		waitpid(pid[k], NULL, 0);
		close(pipefd[1]);
		k++;
		cmd = cmd->next;
	}
	return 0;
}
