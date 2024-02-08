/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:52:31 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/08 16:31:08 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *dinner_simulation(void *data)
{
	t_philo *philo;

	philo = (t_philo *)philo;
	wait_all_thread(philo->table);
	while (!get_end_sim(philo->table))
	{
		if (philo->full)
			break ;
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}	
	return (NULL);
}

void    dinner_start(t_forum *table)
{
	int i;
	
	i = -1;
	if (0 == table->number_limit_meals)
		return ;
	else if (1 == table->philo_number)
		;
	else
	{
		while (++i < table->philo_number)
			pro_tnread_handle(&table->philos[i].philo_thread, dinner_simulation, &table->philos[i], CREATE);
	}
	table->start_sim = get_time(MILLISECOND);
	set_bool(&table->table_mutex, &table->all_thread_ready, true);
	i = -1;
	while (++i < table->philo_number)
		pro_thread_handle(&table->philos[i].philo_thread, JOIN);
}