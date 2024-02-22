/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:11:23 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/23 00:20:35 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Function echo with printf
void	ft_echo(t_cmd *cmd)
{
	int i;

	i = 1;
	while (cmd->argv[i])
	{
		ft_putstr_fd(cmd->argv[i], 1);
		if (cmd->argv[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

// fucntion cd with opendir and readdir
void	ft_cd(t_cmd *cmd)
{
	DIR		*dir;
	struct dirent	*dp;
	char	*path;

	if (cmd->argv[1] == NULL)
		path = "/Users/aitaouss";
	else
		path = cmd->argv[1];
	dir = opendir(path);
	if (dir == NULL)
	{
		ft_putstr_fd("msh: ", 2);
		ft_putstr_fd(cmd->argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else
	{
		chdir(path);
		closedir(dir);
	}
}
//function of pwd command
void    ft_pwd()
{
	char    cwd[1024];
	if (!getcwd(cwd, sizeof(cwd)))
		exit(1);
	printf("%s\n", cwd);
	exit(0);
}

void	ft_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putstr_fd(env[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

// function of export command
void	ft_export(t_cmd *cmd, char **env)
{
	int i;
	int j;
	char **new_env;

	i = 0;
	while (env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(cmd->argv[1]);
	new_env[i + 1] = NULL;
	free(env);
	env = new_env;
}