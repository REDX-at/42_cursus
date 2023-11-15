/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:15:21 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/08 14:32:41 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	bignumber(void)
{
	write(1, "-2147483648", 11);
	return (11);
}

int	ft_d(int nb)
{
	int	count;
	int	sign;

	sign = 0;
	if (nb < 0)
		sign = 1;
	count = digcount (nb);
	if (nb == -2147483648)
		return (bignumber());
	if (nb < 0)
	{
		count += ft_c('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_d(nb / 10);
		ft_d(nb % 10);
	}
	else
		ft_c(nb + 48);
	return (count);
}
