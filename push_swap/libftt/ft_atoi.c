/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:56:10 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/20 16:48:51 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_sifr(const char *s)
{
	while (*s && *s == '0')
	{
		s++;
	}
	return ((char *)s);
}

void	print_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long			result;
	int				count;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	str = ft_sifr(str);
	count = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
		count++;
	}
	if (result * sign > 2147483647 || count > 10 || result * sign < -2147483648)
		print_err();
	return (result * sign);
}
