/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:36:08 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/04 12:48:22 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	char	enemie;
	int		count_p;
	int		count_e;
	int		count_c;
	int		count_n;
	int		count_enemie;
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
	char	*playerback;
	char	*player_right;
	char	*player_left;
	char	*player_down;
	char	*player_top;
	char	*enemie;
	char	*exit_open;
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
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	char	**map;
	char	**map_tmp;
	int		count;
	t_cnt	content;
	t_img	imgs;
	t_pos	pos;
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_lenght;
	int		endian;
	int		count_tmar;
	int		new_e;
	char	*check_exit;
	int		keysend;
	int		render_e;
}				t_data;

void	check_newline(char	**str);
int		sloow_move(t_data *data);
void	ft_show_moves(t_data *data);
void	args_handler(int argc);
int		check_map_ber(char *str);
int		get_line_double(int fd, char **str);
void	*print_string(char *str);
void	set_content(t_cnt *content);
void	set_image(t_data *data);
char	**map_core(char **str, t_data *data);
int		ft_check_col(char *map_line, char wall, t_data *data);
int		ft_check_line(char *map_line, char wall);
int		ft_check_other(char *map_line, t_cnt *content);
void	ft_check_content(t_data *data);
int		ft_check_format(char **map);
char	*ft_strdupy(const char *src);
char	*ft_strjoiny(char const *s1, char const *s2);
size_t	ft_strleny(const char *s);
int		end(t_data *data);
int		ft_check_p(char **map, char p, int *row, int *col);
int		check_if_is_playable(char **map);
int		check_collect(t_data *data, char **map);
int		input_key(int keycode, t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_top(t_data *data);
void	fill_the_map(t_data	data, int *x, int *y);
void	move_down(t_data *data);
void	fill_the_map_forsmall(t_data	data, int *x, int *y);
char	**get_clone(t_data *data);
int		ft_check_whereis_p(char **map, char p, int *row, int *col);
void	print_err(void);
int		check_if_can_play(char **str, t_data *data);
void	*ft_free_second_map(t_data *data);
void	*ft_free_map(t_data *data);
char	**ft_l_split(char *str, char sep);
void	call_render(char **str, t_data *data);
int		move_enemie(t_data *data);
void	swap_move_right(t_data *data, int *x, int *y);
void	swap_move_left(t_data *data, int *x, int *y);
void	swap_move_top(t_data *data, int *x, int *y);
void	swap_move_down(t_data *data, int *x, int *y);
void	check_keysend(t_data *data, char *redx);

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