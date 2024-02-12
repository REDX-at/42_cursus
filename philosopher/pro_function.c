/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pro_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:23:49 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/12 14:35:33 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*pro_malloc(size_t bytes)
{
	void	*ret;
	int		retu;

	retu = 1;
	ret = malloc(bytes);
	if (NULL == ret)
	{
		retu = print_error("Error with the malloc");
		return (NULL);
	}
	return (ret);
}

static int	handle_mutex_error(int status, t_opcode opcode)
{
	int	retu;

	retu = 1;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		retu = print_error("The value specified by mutex is invalid");
	else if (EINVAL == status && INIT == opcode)
		retu = print_error("The value specified by attr is invalid.");
	else if (EDEADLK == status)
		retu = print_error("A deadlock would occur if the thread "
		"blocked waiting for mutex.");
	else if (EPERM == status)
		retu = print_error("The current thread does not hold a lock on mutex.");
	else if (ENOMEM == status)
		retu = print_error("The process cannot allocate enough memory"
				" to create another mutex.");
	else if (EBUSY == status)
		retu = print_error("Mutex is locked");
	if (!retu)
		return (0);
	return (1);
}

static int	handle_thread_error(int status, t_opcode opcode)
{
	int	retu;

	retu = 1;
	if (0 == status)
		return (0);
	if (EAGAIN == status)
		retu = print_error("No resources to create another thread");
	else if (EPERM == status)
		retu = print_error("The caller does not have appropriate permission\n");
	else if (EINVAL == status && CREATE == opcode)
		retu = print_error("The value specified by attr is invalid.");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		retu = print_error("The value specified by thread is not joinable\n");
	else if (ESRCH == status)
		retu = print_error("No thread could be found corresponding to that"
			"specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		retu = print_error("A deadlock was detected or the value of"
			"thread specifies the calling thread.");
	if (!retu)
		return (0);
	return (1);
}

int	pro_mutex(t_mtx *mutex, t_opcode opcode)
{
	int	retu;

	retu = 1;
	if (LOCK == opcode)
		retu = handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		retu = handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		retu = handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		retu = handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
	{
		if (retu)
		{
			retu = print_error("Wrong opcode for mutex_handle:"
				"use <LOCK> <UNLOCK> <INIT> <DESTROY>");
		}
	}
	if (!retu)
		return (0);
	return (1);
}

int	pro_thread(pthread_t *thread, void *(*foo)(void *),
		void *data, t_opcode opcode)
{
	int	retu;

	retu = 1;
	if (CREATE == opcode)
		retu = handle_thread_error(pthread_create
			(thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		retu = handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		retu = handle_thread_error(pthread_detach(*thread), opcode);
	else
	{
		if (retu)
		{
			retu = print_error("Wrong opcode for thread_handle:"
				" use <CREATE> <JOIN> <DETACH>");
		}
	}
	if (!retu)
		return (0);
	return (1);
}
