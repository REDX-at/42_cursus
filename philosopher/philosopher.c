/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:29:13 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/02 17:45:58 by aitaouss         ###   ########.fr       */
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

int	print_exit(char *str, int flag)
{
	printf("%s\n", str);
	if (flag == 1)
		return(1);
	if (flag == 0)
		return(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data = malloc(sizeof(t_data));
	t_forum	*forum = malloc(sizeof(t_forum));
	long	number;

	number = 0;
	if (argc < 5 || argc > 6)
	{
		if(!print_exit("<usage:./philo number_of_philosophers time_to_die time_to_eat time_to_sleep>", 0))
			return (0);
	}
	if (!check_arg(argv))
		return (0);
	number = ft_atol(argv[2]);
	if (!check_num(number))
		return (0);
	number = ft_atol(argv[3]);
	if (!check_num(number))
		return (0);
	number = ft_atol(argv[4]);
	if (!check_num(number))
		return (0);
	forum->philo_number = ft_atol(argv[1]);
	initialize_data_forum(data, forum);
	data = philo_list(forum);
	while (data)
	{
		pthread_join(data->philo_thread, NULL);
		data = data->next;
	}
}

