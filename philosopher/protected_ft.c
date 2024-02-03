/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:21:19 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/03 15:21:31 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*malloc_pro(size_t byte)
{
	char	*alloc;

	alloc = malloc(byte);
	if (!alloc)
		return (NULL);
	return (alloc);
}