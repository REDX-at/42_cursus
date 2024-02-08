/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:54:46 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/08 17:36:47 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status_debug(t_status status, t_philo *philo, long getm)
{
	if (TAKE_FIRST_FORK == status && !get_end_sim(philo->table))
		printf("%6ld %d has taken the 1 fork\n %d", getm, philo->id, philo->left_fork->fork_id);
	else if (TAKE_SECOND_FORK == status && !get_end_sim(philo->table))
		printf("%6ld %d has taken the 2 fork\n %d", getm, philo->id, philo->right_fork->fork_id);
	else if (EATING == status && !get_end_sim(philo->table))
		printf("%6ld %d is eating %d\n", getm, philo->id, philo->meal_count);
	else if (SLEEPING == status && !get_end_sim(philo->table))
		printf("%6ld %d is sleeping\n", getm, philo->id);
	else if (THINKING == status && !get_end_sim(philo->table))
		printf("%6ld %d is thinking\n", getm, philo->id);
	else if (DIED == status)
		printf("%6ld %d died\n", getm, philo->id);
}

void	print_status(t_status status, t_philo *philo, bool deend)
{
	long	getm;

	getm = get_time(MILLISECOND);
	if (!philo->table->end_sim)
		return ;
	pro_mutex_handle(&philo->table->print_mutex, LOCK);
	if (deend)
		print_status_debug(status, philo, getm);
	else
	{
		if (TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status && get_end_sim(philo->table))
			printf("%-6ld %d has taken a fork\n", getm, philo->id);
		else if (EATING == status && !get_end_sim(philo->table))
			printf("%-6ld %d is eating\n", getm, philo->id);
		else if (SLEEPING == status && !get_end_sim(philo->table))
			printf("%-6ld %d is sleeping\n", getm, philo->id);
		else if (THINKING == status && !get_end_sim(philo->table))
			printf("%-6ld %d is thinking\n", getm, philo->id);
		else if (DIED == status)
			printf("%-6ld %d died\n", getm, philo->id);
		pro_mutex_handle(&philo->table->print_mutex, UNLOCK);
	}
}
