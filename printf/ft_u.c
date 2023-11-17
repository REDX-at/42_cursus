/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:16:13 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/16 15:50:08 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_u(unsigned int nb, int *i)
{
	if (nb >= 10)
	{
		ft_u(nb / 10, i);
		ft_u(nb % 10, i);
	}
	else
		*(i) += ft_c(nb % 10 + '0');
}
