/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:01:00 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/03 15:21:29 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void initialize_data_forum(t_data *data, t_forum *forum)
{
	forum->end_sim = false;
	forum->philo = malloc_pro(forum->philo_number);
	if (!forum->philo)
		return ;
	pthread_mutex_init(&data->mutex, NULL);
}