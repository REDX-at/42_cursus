/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:16:59 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/07 20:27:27 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int num)
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

static void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
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
		ft_put_hex(x, format);
	return (hex_len(x));
}
