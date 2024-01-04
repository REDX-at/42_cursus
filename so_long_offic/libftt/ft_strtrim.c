/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:30:39 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/28 15:56:42 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	qlb(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*substr;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] != '\0' && qlb(s1[i], set))
	{
		i++;
	}
	j = ft_strlen(s1) - 1;
	while (j > 0 && qlb(s1[j], set))
	{
		j--;
	}
	if (i > j)
		return (ft_strdup(""));
	substr = ft_substr(s1, i, j - i + 1);
	if (!substr)
		return (NULL);
	return (substr);
}
