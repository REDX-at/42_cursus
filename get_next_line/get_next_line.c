/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:33:23 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/16 18:20:08 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	if (!buffer || !buf)
		return (NULL);
	temp = ft_strjoin((char const *)buffer, (char const *)buf);
	free(buffer);
	return (temp);
}

static char	*nextline(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	line = ft_calloc((ft_len(str) - i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	free (str);
	return (line);
}

static char	*firstline(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		line[i++] = '\n';
	return (line); 
}

static char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		res = ft_free(res, buffer);
		if (ft_strchr(res, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buff);
		return (NULL);
	}
	buff = read_file(fd, buff);
	if (!buff)
		return (NULL);
	line = firstline(buff);
	buff = nextline(buff);
	return (line);
}

// #include "get_next_line.h"

// char *ft_free(char *buffer, char *buf)
// {
//     if (!buffer || !buf)
//         return (NULL);
//     char *temp = ft_strjoin((char const *)buffer, (const char *)buf);
//     free(buffer);
//     return (temp);
// }

// static char *read_file(int fd, char *result)
// {

//     char *buffer;
//     int byte_read;

//     if (!result)
//         result = ft_calloc(1, 1);
//     if (!result)
//         return (NULL);
//     buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
//     if (!buffer)
//         return (NULL);
//     byte_read = 1;
//     while (byte_read > 0)
//     {
//         byte_read = read(fd, buffer, BUFFER_SIZE);
//         if (byte_read == -1)
//         {
//             free(buffer);
//             return (NULL);
//         }
//         buffer[byte_read] = 0;
//         result = ft_free(result, buffer);
//         if (ft_strchr(result, '\n'))
//             break;
//     }
//     free(buffer);
//     return (result);
// }

// char *ft_next_line(char *buffer)
// {
//     int i;
//     int j;
//     char *line;

//     i = 0;
//     while (buffer[i] && buffer[i] != '\n')
//         i++;
//     if (!buffer[i])
//     {
//         free(buffer);
//         return (NULL);
//     }
//     line = ft_calloc((ft_len(buffer) - i + 1), sizeof(char));
//     if (!line)
//         return (NULL);
//     i++;
//     j = 0;
//     while (buffer[i])
//         line[j++] = buffer[i++];
//     free(buffer);
//     return (line);
// }

// char *ft_get_line(char *buffer)
// {
//     char *line;
//     int i;

//     i = 0;
//     if (!buffer[i])
//         return (NULL);
//     while (buffer[i] && buffer[i] != '\n')
//         i++;
//     line = ft_calloc(i + 2, sizeof(char));
//     i = 0;
//     while (buffer[i] && buffer[i] != '\n')
//     {
//         line[i] = buffer[i];
//         i++;
//     }
//     if (buffer[i] && buffer[i] == '\n')
//         line[i++] = '\n';
//     return (line);
// }

// char *get_next_line(int fd)
// {
//     static char *buffer;
//     char *line;

//     if (fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
//     {
//         free(buffer); 
//         return (NULL);
//     }
//     buffer = read_file(fd, buffer);
//     line = ft_get_line(buffer);
//     buffer = ft_next_line(buffer);
//     return (line);
// }
