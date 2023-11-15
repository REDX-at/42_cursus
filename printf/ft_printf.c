/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:33:34 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/15 20:23:51 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	digcount(int n)
{
	int	digit;

	digit = !n;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static int	ft_nxtperc(const char *format, va_list args, int i, int j)
{
	i = 0;
	if (format[j] == 'c')
		i = ft_c(va_arg(args, int));
	else if (format[j] == 's')
		i = ft_s(va_arg(args, char *));
	else if (format[j] == 'p')
		i = ft_p(va_arg(args, unsigned long));
	else if (format[j] == 'd' || format[j] == 'i')
		i = ft_d(va_arg(args, int));
	else if (format[j] == 'u')
		i = ft_u(va_arg(args, unsigned int));
	else if (format[j] == 'x' || format[j] == 'X')
		i = ft_x(va_arg(args, int), format[j]);
	else if (format[j] == '%')
		i = ft_c('%');
	else if (format[j] == ' ')
		return (i);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	j = 0;
	i = 0;
	va_start(args, format);
	while (format[j] != '\0')
	{
		if (format[j] == '%')
		{
			j++;
			while (format[j] == ' ')
			{
				j++;
			}
			i += ft_nxtperc(format, args, i, j);
		}
		else if (format[j])
			i += ft_c(format[j]);
		j++;
	}
	va_end(args);
	return (i);
}

// int	main()
// {  
// 	int d = printf("");
// 	printf("\n");
// 	int i = ft_printf("");
// 	printf("\n");
// 	printf("Orig : %d\n", d);
// 	printf("Mine : %d\n", i);
// }
