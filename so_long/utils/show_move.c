/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:40:09 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/30 17:59:22 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_show_moves(t_data *data)
{
	char	*str;
	char	*join;

	str = ft_itoa(data->count);
	join = ft_strjoint("👣Moves : ", str);

	mlx_string_put(data->mlx, data->mlx_win, data->width, data->height, oxFFFFFF, join);
}
