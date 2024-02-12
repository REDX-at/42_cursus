/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:23:52 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/12 18:00:56 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->thread_ready))
		;
}

void	increase_long(t_mtx *mutex, long *value)
{
	pro_mutex(mutex, LOCK);
	(*value)++;
	pro_mutex(mutex, UNLOCK);
}

bool	all_threads_running(t_mtx *mutex, long *threads,
		long philo_nbr)
{
	bool	ret;

	ret = false;
	pro_mutex(mutex, LOCK);
	if (*threads == philo_nbr)
		ret = true;
	pro_mutex(mutex, UNLOCK);
	return (ret);
}

void	de_synchronize_philos(t_philo *philo)
{
	if (philo->table->philo_nbr % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(3e4, philo->table);
	}
	else
	{
		if (philo->id % 2)
			thinking(philo, true);
	}
}
