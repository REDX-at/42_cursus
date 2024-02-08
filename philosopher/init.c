/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:48:17 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/08 16:42:11 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_forks(t_philo *philo, t_fork *fork, int i)
{
	
	int	philo_number;

	philo_number = philo->table->philo_number;
	philo->right_fork = &fork[(i + 1) % philo_number];
	philo->left_fork = &fork[i];
	if (philo->id % 2 == 0)
	{
		philo->right_fork = &fork[i];
		philo->left_fork = &fork[(i + 1) % philo_number];
	}
}

static void philo_init(t_forum *table)
{
	int i;
	t_philo *philo;

	i = -1;
	while (++i < table->philo_number)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->meal_count = 0;
		philo->full = false;
		philo->table = table;
		assign_forks(philo, table->fork, i);
	}
}	

void initialize_data_forum(t_philo *data, t_forum *table)
{
	int i;
	
	i = -1;
	table->end_sim = false;
	table->all_thread_ready = false;
	table->philos = malloc_pro(sizeof(t_philo) * table->philo_number);
	if (!table->philos)
		return ;
	pro_mutex_handle(&table->table_mutex, INIT);
	pro_mutex_handle(&table->print_mutex, INIT);
	table->fork = malloc_pro(sizeof(t_fork) * table->philo_number);
	if (!table->fork)
		return ;
	while (++i < table->philo_number)
	{
		safe_mutex(&table->fork[i].fork, INIT);
		table->fork[i].fork_id = i;
	}
	philo_init(table);
}
