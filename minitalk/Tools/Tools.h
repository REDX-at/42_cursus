/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:29:37 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/22 15:51:25 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# define RED "\033[30m\033[101m"
# define GREEN "\033[30m\033[42m"
# define WHITE "\033[0m \033[97m"
# define BLUE "\033[0m\033[94m"
# define LIGHT_BLUE "\033[0m\033[96m"
# define YELLOW "\033[0m\033[92m"
# define GREEN_NEW "\033[92m"
# define RED_NEW "\033[31m"

int		ft_c(char c);
int		ft_d(int nb);
int		ft_s(char *s);
int		digcount(int n);
int		ft_atoi(const char *str);
int		ft_printf(const char *format, ...);

typedef struct variables
{
	unsigned char	character;
	pid_t			current_pid;
	pid_t			client_pid;
	int				receive;
}	t_helps;
#endif