/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:01:00 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/08 17:27:54 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(t_time_code code)
{
	struct timeval	tv;
	if (gettimeofday(&tv, NULL))
	{
		if (!print_exit("Error: gettimeofday failed", 1))
			return (0);
	}
	if (SECOND == code)
		return (tv.tv_sec + (tv.tv_usec / 1000000.0));
	else if (MILLISECOND == code)
		return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	else if (MICROSECOND == code)
		return (tv.tv_sec * 1000000 + tv.tv_usec);
	else
	{
		if (!print_exit("Error: invalid time code", 1))
			return (0);
	}
	return (1);
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

void	ft_usleep(long time, t_forum *table)
{
	long	start;
	long	elapsed;
	long	remaining;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < time)
	{
		if(get_end_sim(table))
			break ;
		elapsed = get_time(MICROSECOND) - start;
		remaining = time - elapsed;
		if (remaining < 1000)
			usleep(time / 2);
		else
		{
			while(get_time(MICROSECOND) - start < time / 2)
				;
		}
	}
}
