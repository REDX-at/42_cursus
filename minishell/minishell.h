/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:25:10 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/19 18:32:26 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <termcap.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
#include <termios.h>
#include <stdbool.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define W "\033[0;37m"

// Linked list for the cmd
typedef struct s_cmd
{
    char			*cmd;
    char            *path;
    bool            is_builtin;
    char            *diretcory;
    char            *str;
    struct s_cmd	*next;
}				t_cmd;

void	execute_test(char *path, char *cmd, char *where);
void    ft_cd(char *path);
void    ft_pwd();
char    **ft_split(char const *s, char c);
int	    ft_strcmp(char *str, char *str2);
t_cmd	*get_cmd(char *cmd, char *path, bool is_builtin);
t_cmd	*the_list(char **splited);
size_t	ft_strlen(const char *s);
int	    check_access(char *path, t_cmd *cmd);
// void    execute_pipeline(t_cmd *cmd);
void    test_exe(t_cmd *cmd);
t_cmd	*list_test(void);
char	*ft_strdup(const char *s1);

#endif