/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:24:57 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/19 19:19:42 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	envp = NULL;

	char	*input;
	while(1)
	{
		t_cmd	*cmd;
		cmd = list_test();
		// while (cmd)
		// {
		//     printf("| cmd  : %s\n", cmd->cmd);
		//     printf("| path : %s\n", cmd->path);
		//     printf("+------+----------------\n");
		//     cmd = cmd->next;
		// }
		// exit(0);
		input = readline(GREEN"minishell$ "RESET);
		cmd = list_test();
        test_exe(cmd);
		add_history(input);
		
	}
	return (0);
}