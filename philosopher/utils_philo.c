/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:30:04 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/02 17:49:09 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*malloc_pro(size_t byte)
{
	char	*alloc;

	alloc = malloc(byte);
	if (!alloc)
		return (NULL);
	return (alloc);
}

void initialize_data_forum(t_data *data, t_forum *forum)
{
	forum->end_sim = false;
	forum->philo = malloc_pro(forum->philo_number);
	if (!forum->philo)
		return ;
	pthread_mutex_init(&data->mutex, NULL);
}

void *threadFunction(void *arg)
{
	t_data  *data = (t_data *)arg;

	static pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;
	static int i = 1;
	pthread_mutex_lock(&myMutex);
	printf("philo %d\n", i);
	i++;
	usleep(300000);
	pthread_mutex_unlock(&myMutex);
	return(NULL);
}

t_data	*new_list(pthread_t philo)
{
	t_data	*new_node;

	new_node = (t_data *)malloc(sizeof(t_data));
	if (!new_node)
		return (NULL);
	new_node->philo_thread = philo;
	new_node->next = NULL;
	return (new_node);
}

t_data *philo_list(t_forum *forum)
{
	t_data *head = NULL;
	t_data *temp = NULL;
	int i;

	i = 0;
	while (i < forum->philo_number)
	{
		pthread_t	philo;
		if (pthread_create(&philo, NULL, threadFunction, new_list(philo)) != 0)
		{
			perror("pthread_create");
			exit(EXIT_FAILURE);
		}
		t_data *new_philo = new_list(philo);
		if (head == NULL)
		{
			head = new_philo;
			temp = head;
		}
		else
		{
			temp->next = new_philo;
			temp = temp->next;
		}
		i++;
	}
	return head;
}
