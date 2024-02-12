/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:23:34 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/12 18:02:03 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(t_mtx	*mutex, bool *dest, bool value)
{
	pro_mutex(mutex, LOCK);
	*dest = value;
	pro_mutex(mutex, UNLOCK);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	ret;

	pro_mutex(mutex, LOCK);
	ret = *value;
	pro_mutex(mutex, UNLOCK);
	return (ret);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	ret;

	pro_mutex(mutex, LOCK);
	ret = *value;
	pro_mutex(mutex, UNLOCK);
	return (ret);
}

void	set_long(t_mtx *mutex, long *dest, long value)
{
	pro_mutex(mutex, LOCK);
	*dest = value;
	pro_mutex(mutex, UNLOCK);
}

bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}
