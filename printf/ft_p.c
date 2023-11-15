/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:07 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/09 14:57:11 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_ptr(unsigned long ptr, int *total)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(sizeof(char) * 16);
	if (!result)
		return ;
	while (ptr >= 16)
	{
		result[i] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
		i++;
	}
	if (ptr < 16)
		result[i] = "0123456789abcdef"[ptr];
	while (i >= 0)
	{
		*total += ft_c(result[i]);
		i--;
	}
	free(result);
}

int	ft_p(unsigned long ptr)
{
	int	total;

	total = 0;
	total += ft_s("0x");
	handle_ptr(ptr, &total);
	return (total);
}
