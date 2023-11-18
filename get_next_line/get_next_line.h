/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:13:29 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/16 18:19:22 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>

int		ft_len(const char *str);
char	*ft_calloc(int count, int size);
void	*ft_memset(void *ptr, int c, int n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlcpy(char *dest, const char *src, int size);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif
