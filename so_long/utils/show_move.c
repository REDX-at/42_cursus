/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:40:09 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/30 18:12:12 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_show_moves(t_data *data)
{
	char	*str;
	char	*join;

	str = ft_itoa(data->count);
	join = ft_strjoin("👣Moves : ", str);
	mlx_string_put(data->mlx, data->mlx_win, data->width, data->height * data->imgs.width + data->imgs.width / 8, 0xFFFFFF, join);
}
