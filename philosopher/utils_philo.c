/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:01:00 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/06 18:04:30 by aitaouss         ###   ########.fr       */
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

void initialize_data_forum(t_data *data, t_forum *table)
{
	table->end_sim = false;
	table->philos = malloc_pro(table->philo_number);
	if (!table->philos)
		return ;
	pthread_mutex_init(&data->mutex, NULL);
}
