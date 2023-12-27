/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:36:08 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/27 14:57:57 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include "mlx.h"
# include "./libftt/libft.h"
# include "./printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <math.h>
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>

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
	void	*img_playerback;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}				t_img;

typedef struct pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct data_s
{
	void    *mlx;
	void    *mlx_win;
	int		width;
	int		height;
	char	**map;
	int		count;
	t_cnt	content;
	t_img	imgs;
	t_pos	pos;
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_lenght;
	int		endian;
}				t_data;


void	args_handler(int argc);
int		check_map_ber(char *str);
int		get_line_double(int fd, char **str);
void	*print_string(char *str);
void    set_content(t_cnt *content);
void    set_image(t_data *data);
char	**map_core(char **str, t_data *data);
int		ft_check_col(char *map_line, char wall, t_data *data);
int		ft_check_line(char *map_line, char wall);
int		ft_check_other(char *map_line, t_cnt *content);
void	ft_check_content(t_data *data);
int		ft_check_format(char **map);
char	**ft_splity(char const *s, char c);
char	*ft_strdupy(const char *src);
char	*ft_strjoiny(char const *s1, char const *s2);
size_t	ft_strleny(const char *s);
size_t	ft_strlcpyy(char *dest, const char *src, size_t size);
int		end(t_data *data);
int		ft_check_p(char **map, char p, int *row, int *col) ;
int		check_if_is_playable(char **map);
void	print_img(t_data *data, void *img, int x, int y);
int		check_collect(t_data *data, char **map);
int		input_key(int keycode, t_data *data);
void	render_offic(t_data *data);
int		render(t_data *data);
void	render_mapi(t_data *data);
void    move_right(t_data *data);
void    move_left(t_data *data);
void    move_top(t_data *data);
void	fill_the_map(t_data	data, int *x, int *y);
void    move_down(t_data *data);

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_ESC 53

# define KEY_TOP 126
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_BOTTOM 125

# define RED "\033[30m\033[101m"
# define GREEN "\033[30m\033[42m"
# define WHITE "\033[0m \033[97m"
# define BLUE "\033[0m\033[94m"
# define LIGHT_BLUE "\033[0m\033[96m"
# define YELLOW "\033[0m\033[92m"
# define GREEN_NEW "\033[92m"
# define RED_NEW "\033[31m"

#endif