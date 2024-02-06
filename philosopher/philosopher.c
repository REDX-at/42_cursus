/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:59:24 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/06 18:05:23 by aitaouss         ###   ########.fr       */
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
	t_forum	*table = malloc(sizeof(t_forum));
	long	number;

	number = 0;
	if (argc < 5 || argc > 6)
	{
		if(!print_exit("<usage:./philo number_of_philosophers time_to_die time_to_eat time_to_sleep>", 0))
			return (0);
	}
	if (!check_arg(argv))
		return (0);
	table->philo_number = ft_atol(argv[1]);
	initialize_data_forum(data, table);
}
