/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:29:13 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/20 21:51:23 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tools.h"

static int	ft_check(int sign)
{
	if (sign == -1)
		return (0);
	return (-1);
}

static char	*ft_zero(const char *s)
{
	while (*s && *s == '0')
	{
		s++;
	}
	return ((char *)s);
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	result;
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
	str = ft_zero(str);
	count = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
		count++;
	}
	if (result > 9223372036854775807 || count >= 20)
		return (ft_check(sign));
	return (result * sign);
}
