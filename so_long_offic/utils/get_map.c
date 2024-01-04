/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:13:52 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/04 12:32:30 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_map(int fd)
{
	char	*line_map;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line_map = ft_strdupy("");
	buff = ft_strdupy("");
	char_count = get_line_double(fd, &line_map);
	if (char_count > 0)
	{
		tmp_buff = buff;
		while (char_count > 0)
		{
			buff = ft_strjoiny(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = ft_strdupy("");
			char_count = get_line_double(fd, &line_map);
			tmp_buff = buff;
		}
		return (buff);
	}
	print_string("Error\nWrong lecture map\n");
	return (NULL);
}

void	*ft_free_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	return (0);
}

void	*ft_free_second_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->map_tmp[i] != NULL)
	{
		free(data->map_tmp[i]);
		i++;
	}
	free(data->map_tmp);
	data->map_tmp = NULL;
	return (0);
}

char	**parse_map(int fd, t_data *data)
{
	int		i;
	int		y;

	i = 0;
	data->map = ft_l_split(get_map(fd), '\n');
	y = 0;
	ft_check_content(data);
	if (!(ft_check_format(data->map)))
		return (ft_free_map(data));
	if (!(ft_check_line(data->map[0], data->content.wall)))
		return (ft_free_map(data));
	while (data->map[i] != NULL)
	{
		if (!(ft_check_col(data->map[i], data->content.wall, data)))
			return (ft_free_map(data));
		else if (!(ft_check_other(data->map[i], &(data->content))))
			return (ft_free_map(data));
		i++;
	}
	data->height = i;
	if (!(ft_check_line(data->map[i - 1], data->content.wall)))
		return (ft_free_map(data));
	if (!(check_if_is_playable(data->map)))
		return (ft_free_map(data));
	return (data->map);
}

char	**map_core(char **str, t_data *data)
{
	int		fd;

	check_newline(str);
	data->map = NULL;
	fd = 0;
	fd = open(str[1], O_RDONLY);
	if (fd > 0)
		data->map = parse_map(fd, data);
	else
	{
		ft_free_map(data);
		return (print_string("Error\nFailed to open file\n"));
	}
	if ((data->content.count_c == 0 || data->content.count_e != 1
			|| data->content.count_p != 1)
		&& data->map != NULL)
	{
		ft_free_map(data);
		return (print_string(
				"Error\nNeed 1 Player/Exit and at least 1 Object\n"));
	}
	return (data->map);
}
