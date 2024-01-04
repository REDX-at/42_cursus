/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoiny.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:18:27 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/30 10:44:17 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	lenn(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static size_t	ft_strlcpyy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = lenn(src);
	i = 0;
	if (size == 0)
	{
		return (src_len);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

char	*ft_strjoiny(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	totallen;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strleny(s1);
	lens2 = ft_strleny(s2);
	totallen = lens1 + lens2;
	res = (char *)malloc(totallen + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpyy(res, s1, lens1 + 1);
	ft_strlcpyy(res + lens1, s2, lens2 + 1);
	return (res);
}
