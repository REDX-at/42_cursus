/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:33:23 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/23 10:28:02 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*readline(int fd, char *line)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(line, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*ft_newline(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i) + 1);
	if (!str)
	{
		free(line);
		return (NULL);
	}
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*ft_getline(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(i + (line[i] == '\n') + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char			*line;
	char				*temp;
	char				*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd >= OPEN_MAX)
		return (NULL);
	temp = readline(fd, line);
	if (!temp)
	{
		if (line)
			free(line);
		line = NULL;
		return (NULL);
	}
	line = temp;
	next_line = ft_getline(line);
	line = ft_newline(line);
	return (next_line);
}

int main(void)
{
	int		fd;
	char	*line;
	int		i;
	int		d;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	d = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		i++;
		printf("---------------------------\n");
		printf("Hawa Line %d", i);
		d += printf(" : %s\n", line);
		printf("---------------------------\n");
		free(line);
		sleep(1);
	}
	if (((line = get_next_line(fd)) == NULL))
	{
		printf("--------------------------------\n");
		printf("-!-!-!-!-!-!-!-'0'-!-!-!-!-!-!-!-\n");
		printf("--------------------------------\n");
	}
	printf("the legnht of the all line : %d", d);
	printf(" - (4");
	printf(" * %d", i);
	printf(")");
	close(fd);
	return (0);
}
