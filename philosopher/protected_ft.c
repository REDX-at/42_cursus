/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protected_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:21:19 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/06 16:35:46 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_mutex_err(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
	{
		if (!print_exit("value spec by mutex is invalide.", 0))
			return ;
	}
	else if (EINVAL == status && INIT == opcode)
	{
		if (!print_exit("value spec by attr is invalid.", 0))
			return ;
	}
	else if (EDEADLK == status)
	{
		if (!print_exit("deadlock.", 0))
			return ;
	}
	else if (EPERM == status)
	{
		if (!print_exit("the curr thread does not hold a lock on mutex", 0))
			return ;
	}
	else if (ENOMEM == status)
	{
		if (!print_exit("teh procc cannot allocate enough memory to create another mutex", 0))
			return ;
	}
	else if (EBUSY == status)
	{
		if (!print_exit("mutex is locked", 0))
			return ;
	}
}

int	pro_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		handle_mutex_err (pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		handle_mutex_err (pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		handle_mutex_err (pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		handle_mutex_err (pthread_mutex_destroy(mutex), opcode);
	else
	{
		if (!print_exit("Opcode wrong .", 0))
			return (0);
	}
	return (1);
}
