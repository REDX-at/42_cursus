/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:56:29 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/13 13:17:43 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	if (s1 < s2)
	{
		while (n > 0)
		{
			*s1++ = *s2++;
			n--;
		}
	}
	else if (s1 > s2)
	{
		s1 += n;
		s2 += n;
		while (n > 0)
		{
			*(--s1) = *(--s2);
			n--;
		}
	}
	return (str1);
}
