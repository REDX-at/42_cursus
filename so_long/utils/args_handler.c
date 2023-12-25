/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:54:53 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/25 19:56:07 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    args_handler(int argc)
{
    if (argc > 2)
		printf("%sArgument More than 2.\n", WHITE);
	if (argc == 1)
		printf("%sArgumet not enough ADD one More ...\n", WHITE);
}

int check_if_is_playable(char **map) {
    t_data data;
    int row, col;
    
    if (ft_check_p(map, 'P', &row, &col)) {
        if (row > 0 && row < data.width - 1 && col > 0 && col < data.width - 1) {
            if (map[row + 1][col] == '1' || map[row - 1][col] == '1' ||
                map[row][col + 1] == '1' || map[row][col - 1] == '1') {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    
    return 1;
}