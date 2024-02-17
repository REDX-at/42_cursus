/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:55:00 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/17 18:56:32 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exe_shell.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	tol(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (tol(src) + 1));
	if (!new)
		return (NULL);
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

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
		strings[index] = ft_strdup(buffer);
		if (!strings[index])
			return (freee(strings, (index - 1)));
		index++;
	}
	return ((void *)1);
}

char	**ft_split(char const *s, char c)
{
	size_t	slen;
	char	**strings;
	int		count_w;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	count_w = count_word(s, c, slen);
	strings = (char **)malloc(sizeof(char *) * (count_w + 1));
	if (!strings)
		return (NULL);
	if (!subs(s, c, slen, strings))
		return (NULL);
	strings[count_w] = NULL;
	return (strings);
}