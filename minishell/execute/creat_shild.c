/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_shild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:51:03 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/22 01:16:34 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// creat shild with pipe and use execve
void    creat_shild(t_cmd *cmd, int pipefd[2], char **argv)
{
	// if (check_access(cmd->cmd, cmd) == 0)
	// {
	// 	printf("msh: command not found: %s\n", cmd->cmd);
	// 	exit(1);
	// }
	check_access(cmd->cmd, cmd);
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	if (execve(cmd->path, argv, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}