/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:29:06 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/20 21:52:50 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "Tools.h"

static int	ft_nxtperc(const char *format, va_list args, int i, int j)
{
	i = 0;
	if (format[j] == 'c')
		i = ft_c(va_arg(args, int));
	else if (format[j] == 'd' || format[j] == 'i')
		i = ft_d(va_arg(args, int));
	else if (format[j] == 's')
		i = ft_s(va_arg(args, char *));
	else if (format[j] != '\0')
		i = ft_c(format[j]);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, format);
	while (format[j] != '\0')
	{
		if (format[j] == '%')
		{
			j++;
			if (format[j] == '\0')
				return (i);
			else
				i += ft_nxtperc(format, args, i, j);
		}
		else if (format[j])
			i += ft_c(format[j]);
		j++;
	}
	return (va_end(args), i);
}
