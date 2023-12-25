/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:16:15 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/25 09:39:30 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_word(const char *str, char c, size_t slen)
{
	size_t	i;
	size_t	old_i;
	size_t	count;

	count = 0;
	i = 0;
	while (i < slen)
	{
		while (i < slen && str[i] == c)
			i++;
		old_i = i;
		while (i < slen && str[i] != c)
			i++;
		if (i > old_i)
			count++;
	}
	return (count);
}

void	*freee(char **string, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		free(string[i]);
		string[i] = NULL;
		i++;
	}
	free(string);
	string = NULL;
	return (NULL);
}

static void	*subs(char const *s, char c, size_t slen, char **strings)
{
	size_t	i;
	size_t	j;
	size_t	index;
	char	buffer[255];

	index = 0;
	i = 0;
	while (i < slen)
	{
		while (i < slen && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (i < slen && s[i] != c)
			buffer[j++] = s[i++];
		buffer[j] = '\0';
		strings[index] = ft_strdupy(buffer);
		if (!strings[index])
			return (freee(strings, (index - 1)));
		index++;
	}
	return ((void *)1);
}

char	**ft_splity(char const *s, char c)
{
	size_t	slen;
	char	**strings;
	int		count_w;

	if (!s)
		return (NULL);
	slen = ft_strleny(s);
	count_w = count_word(s, c, slen);
	strings = (char **)malloc(sizeof(char *) * (count_w + 1));
	if (!strings)
		return (NULL);
	if (!subs(s, c, slen, strings))
		return (NULL);
	strings[count_w] = NULL;
	return (strings);
}
