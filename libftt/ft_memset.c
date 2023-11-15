/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:15:51 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/10 15:36:46 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*btr;
	unsigned char	bvalue;

	btr = ptr;
	bvalue = (unsigned char) c;
	while (n > 0)
	{
		*btr++ = bvalue;
		n--;
	}
	return (ptr);
}
