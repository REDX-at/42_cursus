/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_parrent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:09:10 by aitaouss          #+#    #+#             */
/*   Updated: 2024/03/04 20:51:44 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	max_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void    into_parrent(t_cmd *cmd, int pid[], int k, t_table *table, char buf[])
{
	int bytes;

	if (ft_strncmp(cmd->cmd, "exit", 4) == 0)
	{
		waitpid(pid[k], NULL, 0);
		int fd_in = open("exit", O_RDONLY);
		bytes = 1;
		while ((bytes = read(fd_in, buf, 1)));
		unlink("exit");
		if (buf[0] == '1')
			exit(EXIT_SUCCESS);
	}
	if (ft_strncmp(cmd->cmd, "cd", 2) == 0)
	{
		char *join = ft_strdup("");
		waitpid(pid[k], NULL, 0);
		int fd_in = open("cd", O_RDONLY);
		char *path;
		path = (char *)malloc(1000);
		bytes = 1;
		while (bytes)
		{
			bytes = read(fd_in, path, 1000);
			path[bytes] = '\0';
			join = ft_strjoin(join, path);
		}
		unlink("cd");
		chdir(join);
	}
	if (ft_strncmp(cmd->cmd, "export", 6) == 0)
	{
		waitpid(pid[k], NULL, 0);
		if (cmd->argv[1])
		{
			int fd_in;
			char    *buffer;
			char 	*join;

			fd_in = open("export.txt", O_RDONLY);
			bytes = 1;
			buffer = (char *)malloc(1000);
			join = ft_strdup("");
			while(bytes)
			{
				bytes = read(fd_in, buffer, sizeof(buffer) - 1);
				buffer[bytes] = '\0';
				if (bytes)
					join = ft_strjoin(join, buffer);
			}
			table->env = ft_split(join, '\n');
		}
		unlink("export.txt");
	}
	if (ft_strncmp(cmd->cmd, "unset", 6) == 0)
	{
		waitpid(pid[k], NULL, 0);
		if (cmd->argv[1])
		{
			int	fd_in;
			char *buffer;
			char *join;
			
			fd_in = open("unset.txt", O_RDONLY);
			bytes = 1;
			buffer = (char *)malloc(1000);
			join = ft_strdup("");
			while(bytes)
			{
				bytes = read(fd_in, buffer, sizeof(buffer) - 1);
				buffer[bytes] = '\0';
				if (bytes)
					join = ft_strjoin(join, buffer);
			}
			table->env = ft_split(join, '\n');
		}
		unlink("unset.txt");
	}
}