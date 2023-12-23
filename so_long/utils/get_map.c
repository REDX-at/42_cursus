/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:13:52 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/23 23:15:47 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char    *get_map(int fd)
{
	char    *map_line;
	char    *buffer;
	int     c_count;
	char    *buffer_tmp;

	map_line = ft_strdup("");
	buffer = ft_strdup("");
	c_count = gnl(fd, &map_line);
}