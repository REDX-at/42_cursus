/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:37:39 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/08 17:52:51 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	len = ft_strlen(needle);
	if (n == 0 || (haystack == NULL && needle == NULL))
		return (NULL);
	while (haystack[i] && i + len <= n)
	{
		j = 0;
		while (j < len && haystack[i + j] == needle[j])
			j++;
		if (j == len)
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
