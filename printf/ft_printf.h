/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:10:57 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/09 14:57:29 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>

int	ft_c(char c);
int	count_percent(char const *str);
int	ft_d(int nb);
int	ft_s(char *s);
int	ft_u(unsigned int nb);
int	ft_x(unsigned int x, const char format);
int	digcount(int n);
int	ft_p(unsigned long ptr);
int	ft_printf(const char *format, ...);

#endif
