/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:10:57 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/24 15:15:24 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_c(char c);
int		ft_d(int nb);
int		ft_s(char *s);
void	ft_u(unsigned int nb, int *i);
int		ft_x(unsigned int x, const char format);
int		digcount(int n);
int		ft_p(unsigned long ptr);
int		ft_printf(const char *format, ...);

#endif
