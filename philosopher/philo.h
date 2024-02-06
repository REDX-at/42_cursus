/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:59:36 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/06 17:58:38 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <errno.h>

typedef enum	e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

typedef pthread_mutex_t t_mtx;
typedef	struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

//	PHILO DATA

typedef struct s_data
{
	int				id;
	long			meal_count;
	bool			full;
	long			last_meal;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		philo_thread;
	int				number_philo;
	struct s_data	*next;
	pthread_mutex_t	mutex;
    struct t_forum         *forum;
}	t_data;

//  TABLE

typedef	struct s_forum
{
	long	philo_number;
	long	number_limit_meals;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	start_sim;
	bool	end_sim;
	t_fork	*fork;
	t_data	*philos;
}	t_forum;

int		print_exit(char *str, int flag);
void	ft_puts(char *str);
void	*malloc_pro(size_t byte);
int		check_arg(char **argv);
int	check_num(int n, int flag);
void	initialize_data_forum(t_data *data, t_forum *forum);
long	ft_atol(const char *str);

#endif