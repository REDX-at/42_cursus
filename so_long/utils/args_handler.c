/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:54:53 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/26 08:18:32 by aitaouss         ###   ########.fr       */
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
