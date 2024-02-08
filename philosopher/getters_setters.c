/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:06:39 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/08 16:09:27 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    set_bool(t_mtx *mutex, bool *var, bool value)
{
	pro_mutex_handle(mutex, LOCK);
	*var = value;
	pro_mutex_handle(mutex, UNLOCK);
}

bool    get_bool(t_mtx *mutex, bool *var)
{
	bool value;

	pro_mutex_handle(mutex, LOCK);
	value = *var;
	pro_mutex_handle(mutex, UNLOCK);
	return (value);
}

long	get_long(t_mtx *mutex, long *var)
{
	long value;

	pro_mutex_handle(mutex, LOCK);
	value = *var;
	pro_mutex_handle(mutex, UNLOCK);
	return (value);
}

void	set_long(t_mtx *mutex, long *var, long value)
{
	pro_mutex_handle(mutex, LOCK);
	*var = value;
	pro_mutex_handle(mutex, UNLOCK);
}

bool	get_end_sim(t_forum *table)
{
	return (get_bool(&table->table_mutex, &table->end_sim));
}