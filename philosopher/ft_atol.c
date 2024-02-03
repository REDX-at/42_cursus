/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:01:44 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/03 15:01:46 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*ft_sifr(const char *s)
{
	while (*s && *s == '0')
	{
		s++;
	}
	return ((char *)s);
}

long	ft_atol(const char *str)
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
		return (0);
	return (result * sign);
}