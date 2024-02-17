/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:23:31 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/17 10:15:20 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo, bool pre_simulation)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (!pre_simulation)
		write_status(THINKING, philo);
	if (philo->table->philo_nbr % 2 == 0)
		return ;
	t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		t_think = 0;
	ft_usleep(t_think * 0.42, philo->table);
}

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal, gettime(MILLISECOND));
	increase_long(&philo->table->table_mutex,
		&philo->table->thread_exe_nbr);
	write_status(TAKE_left_fork, philo);
	while (!simulation_finished(philo->table))
		ft_usleep(200, philo->table);
	return (NULL);
}

static void	eat(t_philo *philo)
{
	pro_mutex(&philo->left_fork->fork, LOCK);
	write_status(TAKE_left_fork, philo);
	pro_mutex(&philo->right_fork->fork, LOCK);
	write_status(TAKE_right_fork, philo);
	set_long(&philo->philo_mutex, &philo->last_meal, gettime(MILLISECOND));
	philo->count_meals++;
	write_status(EATING, philo);
	ft_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->meal_limit_number > 0
		&& philo->count_meals == philo->table->meal_limit_number)
		set_bool(&philo->philo_mutex, &philo->full, true);
	pro_mutex(&philo->left_fork->fork, UNLOCK);
	pro_mutex(&philo->right_fork->fork, UNLOCK);
}

static void	*dinner_simulation(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal,
		gettime(MILLISECOND));
	increase_long(&philo->table->table_mutex,
		&philo->table->thread_exe_nbr);
	de_synchronize_philos(philo);
	while (!simulation_finished(philo->table))
	{
		if (get_bool(&philo->philo_mutex, &philo->full))
			break ;
		eat(philo);
		write_status(SLEEPING, philo);
		ft_usleep(philo->table->time_to_sleep, philo->table);
		thinking(philo, false);
	}
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int			i;

	i = -1;
	if (0 == table->meal_limit_number)
		return ;
	else if (1 == table->philo_nbr)
		pro_thread(&table->philos[0].thread_id, one_philo,
			&table->philos[0], CREATE);
	else
		while (++i < table->philo_nbr)
			pro_thread(&table->philos[i].thread_id, dinner_simulation,
				&table->philos[i], CREATE);
	pro_thread(&table->monitor, watch_dinner, table, CREATE);
	table->start_simulation = gettime(MILLISECOND);
	set_bool(&table->table_mutex, &table->thread_ready, true);
	i = -1;
	while (++i < table->philo_nbr)
		pro_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&table->table_mutex, &table->end_simulation, true);
	pro_thread(&table->monitor, NULL, NULL, JOIN);
}
