/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:54:53 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/04 12:39:50 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	args_handler(int argc)
{
	if (argc > 2)
		ft_printf("%sArgument More than 2.\n", WHITE);
	if (argc == 1)
		ft_printf("%sArgumet not enough ADD one More ...\n", WHITE);
}
