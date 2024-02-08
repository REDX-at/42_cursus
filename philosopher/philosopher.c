/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:59:24 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/08 16:14:52 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

void	ft_puts(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	free_all(t_forum *table, t_philo *data)
{
	free(data);
	free(table->philos);
	free(table);
}

int	data_init(t_forum *table, char **argv)
{
	table->philo_number = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->number_limit_meals = ft_atol(argv[5]);
	else
		table->number_limit_meals = -1;
}

int	main(int argc, char **argv)
{
	t_philo	*data = malloc(sizeof(t_philo));
	t_forum	*table = malloc(sizeof(t_forum));
	long	number;

	number = 0;
	if (argc < 5 || argc > 6)
	{
		free_all(table, data);
		if(!print_exit("<usage:./philo number_of_philosophers time_to_die time_to_eat time_to_sleep>", 0))
			return (0);
	}
	if (!check_arg(argv))
	{
		free_all(table, data);
		return (0);
	}
	data_init(table, argv);
	initialize_data_forum(data, table);
	free_all(table, data);
}
