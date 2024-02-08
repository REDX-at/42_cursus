/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:59:36 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/08 17:32:17 by aitaouss         ###   ########.fr       */
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

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}	t_time_code;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_status;

typedef pthread_mutex_t t_mtx;
typedef	struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

//	PHILO DATA

typedef struct s_philo
{
	int				id;
	long			meal_count;
	bool			full;
	long			last_meal;
	t_fork			*left_fork; // first fork
	t_fork			*right_fork; // secod fork
	pthread_t		philo_thread;
	int				number_philo;
	struct s_philo	*next;
	pthread_mutex_t	mutex;
    t_forum         *table;
}	t_philo;

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
	bool	all_thread_ready;
	t_mtx	table_mutex;
	t_mtx	print_mutex;
	t_fork	*fork;
	t_philo	*philos;
}	t_forum;

int		print_exit(char *str, int flag);
void	ft_puts(char *str);
void	*malloc_pro(size_t byte);
int		check_arg(char **argv);
int	check_num(int n, int flag);
void	initialize_data_forum(t_philo *data, t_forum *forum);
long	ft_atol(const char *str);
int		pro_tnread_handle(pthread_t *thread, void *(*fun)(void *), void *data, t_opcode opcode);
int		pro_mutex_handle(t_mtx *mutex, t_opcode opcode);
void	free_all(t_forum *table, t_philo *data);
void    *dinner_simulation(void *data);
void    dinner_start(t_forum *table);
void    set_bool(t_mtx *mutex, bool *var, bool value);
bool    get_bool(t_mtx *mutex, bool *var);
long	get_long(t_mtx *mutex, long *var);
void	set_long(t_mtx *mutex, long *var, long value);
bool	get_end_sim(t_forum *table);
void	wait_all_thread(t_forum *table);
long	get_time(t_time_code code);
void	ft_usleep(long time, t_forum *table);

#endif