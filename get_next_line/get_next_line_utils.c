/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:08:55 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/16 18:20:11 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_calloc(int count, int size)
{
	int		totalsize;
	void	*ptr;

	totalsize = count * size;
	ptr = malloc(totalsize);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, totalsize);
	return (ptr);
}

void	*ft_memset(void *ptr, int c, int n)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	int		totallen;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_len(s1);
	lens2 = ft_len(s2);
	totallen = lens1 + lens2;
	res = (char *)malloc(totallen + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, lens1 + 1);
	ft_strlcpy(res + lens1, s2, lens2 + 1);
	return (res);
}

int	ft_strlcpy(char *dest, const char *src, int size)
{
	int	src_len;
	int	i;

	src_len = ft_len(src);
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == '\0' && (char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}
