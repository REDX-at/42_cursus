/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:16:59 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/20 14:09:52 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	xlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len ++;
		num = num / 16;
	}
	return (len);
}

static void	ft_putx(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_putx(num / 16, format);
		ft_putx(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_c((num + '0'));
		else
		{
			if (format == 'x')
				ft_c((num - 10 + 'a'));
			if (format == 'X')
				ft_c((num - 10 + 'A'));
		}
	}
}

int	ft_x(unsigned int x, const char format)
{
	if (x == 0)
		return (write(1, "0", 1));
	else
		ft_putx(x, format);
	return (xlen(x));
}
