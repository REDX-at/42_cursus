/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:54:53 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/30 10:41:36 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	args_handler(int argc)
{
	if (argc > 2)
		ft_printf("%sArgument More than 2.\n", WHITE);
	if (argc == 1)
		ft_printf("%sArgumet not enough ADD one More ...\n", WHITE);
}
