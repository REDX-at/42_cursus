/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:24:57 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/23 00:19:21 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// For signal
void sig_handler(int signum)
{
	if (signum == SIGINT)
		ft_putstr_fd(GREEN"\nminishell$"RESET, 1);
}

// For free
void ft_cmd_free(t_cmd **cmd)
{
	while ((*cmd))
	{
		// free((*cmd)->cmd);
		ft_free((*cmd)->argv);
		//free((*cmd)->file);
		(*cmd) = (*cmd)->next;
	}
	free(*cmd);
	(*cmd) = NULL;
}

// For coutn cmd
void	count_cmd(t_cmd *cmd)
{
	t_cmd *tmp = cmd;
	tmp->count_cmd = 0;
	int i = 0;
	while (tmp)
	{
		while (tmp)
		{
			i += 1;
			tmp = tmp->next;
		}
	}
	cmd->count_cmd = i;
}

// MIne
int	ft_strcmp(char *str, char *str2)
{
	int i;

	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] != str2[i])
			return (0);
		i++;
	}
	if (str[i] != str2[i])
		return (0);
	return (1);
}

int main(int argc, char **argv, char **envp)
{
	char *line;
	t_cmd *cmd;

	(void)argc;
	(void)argv;
	cmd = NULL;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	while (1)
	{
		line = readline(GREEN"minishell$ "RESET);
		if (ft_strcmp(line, "exit") == 1)
		{
			free(line);	
			exit(0);
		}
		if(line)
		{
			add_history(line);
			ft_tokenizing(line, &cmd);
			count_cmd(cmd);
			execute_part(cmd, envp);
			ft_cmd_free(&cmd);
		}
		if (!line)
		{
			free(line);
			exit(0);
		}
		free(line);
	}
}