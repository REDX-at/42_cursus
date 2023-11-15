/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:14:03 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/11 23:33:12 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	const unsigned char	*btr = ptr;
	unsigned char		bvalue;

	bvalue = (unsigned char) value;
	while (n > 0)
	{
		if (*btr == bvalue)
		{
			return ((void *)btr);
		}
		btr++;
		n--;
	}
	return (0);
}
