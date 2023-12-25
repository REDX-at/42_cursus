/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoiny.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 09:18:27 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/25 09:39:36 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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