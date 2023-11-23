/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:33:34 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/23 15:57:48 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

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
		ft_u(va_arg(args, unsigned int), &i);
	else if (format[j] == 'x' || format[j] == 'X')
		i = ft_x(va_arg(args, int), format[j]);
	else if (format[j] == '%')
		i = ft_c('%');
	else if (format[j] == ' ')
		return (i);
	else if (format[j] != '\0')
		i = ft_c(format[j]);
	return (i);
}

void	handle_d_i(int *count_plus, int *i, int flag)
{
	if (flag == 1)
	{
		if (*count_plus != 0)
			*i += ft_c('+');
		else
			*i += ft_c(' ');
	}
}

void	handle_flags(const char *format, int *j, int *count_plus, int *hplus)
{
	while (format[*j] == ' ' || format[*j] == '+' || format[*j] == '#')
	{
		if (format[*j] == '+')
			(*count_plus)++;
		if (format[*j] == '#')
			(*hplus)++;
		(*j)++;
	}
}

void	process_format(const char *format, va_list args, int *i, int *j)
{
	int	count_plus;
	int	hplus;

	count_plus = 0;
	hplus = 0;
	handle_flags(format, j, &count_plus, &hplus);
	if (hplus != 0 && (format[*j] == 'x' || format[*j] == 'X'))
		*i += ft_s("0x");
	if ((format[*j - 1] == ' ' || format[*j - 1] == '+' || format[*j - 1] 
			== '#') && (format[*j] == 'd' || format[*j] == 'i'))
		handle_d_i(&count_plus, i, 1);
	if (format[*j] != '\0')
		*i += ft_nxtperc(format, args, *i, *j);
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
			process_format(format, args, &i, &j);
			if (format[j] == '\0')
				return (i);
		}
		else if (format[j])
			i += ft_c(format[j]);
		j++;
	}
	return (va_end(args), i);
}

// int main()
// {
// 	int i = ft_printf("%%     ++++++++  ###  % +++++ ###   %%       %%");
// 	printf("\n");
// 	int d = printf("%%     ++++++++  ###  % +++++ ###   %%       %%");
// 	printf("\n");
// 	printf("Mine : %d\n",i);
// 	printf("Orig : %d\n",d);
// }
