/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:36:08 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/23 23:39:51 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include "libftt/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <math.h>
# include "./get_next_line/get_next_line.h"
#include <fcntl.h>

void	args_handler(int argc);
int		check_map_ber(char *str);
int		get_line_double(int fd, char **str);

typedef struct s_vars
{
	void    *mlx;
	void    *win;
	char	**map;
	int		width;
	int		height;
	int		count;
}   t_map;

typedef struct cnt_s
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}				t_cnt;

typedef struct img_s
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}				t_img;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	char	**map;
	t_cnt	content;
	t_img	img;
	t_pos	pos;
	int		count;
}				t_data;

# define RED "\033[30m\033[101m"
# define GREEN "\033[30m\033[42m"
# define WHITE "\033[0m \033[97m"
# define BLUE "\033[0m\033[94m"
# define LIGHT_BLUE "\033[0m\033[96m"
# define YELLOW "\033[0m\033[92m"
# define GREEN_NEW "\033[92m"
# define RED_NEW "\033[31m"

#endif