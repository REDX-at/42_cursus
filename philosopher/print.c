/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:23:57 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/12 15:34:50 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <time.h>

void	write_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = gettime(MILLISECOND) - philo->table->start_simulation;
	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	pro_mutex(&philo->table->print_mutex, LOCK);
	if ((TAKE_left_fork == status || TAKE_right_fork == status)
		&& !simulation_finished(philo->table))
		printf(W"%-6ld %d has taken a fork\n", elapsed, philo->id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf(W"%-6ld %d is eating\n", elapsed, philo->id);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf(W"%-6ld %d is sleeping\n", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf(W"%-6ld %d is thinking\n", elapsed, philo->id);
	else if (DIED == status)
		printf(W"%-6ld %d died\n", elapsed, philo->id);
	pro_mutex(&philo->table->print_mutex, UNLOCK);
}
