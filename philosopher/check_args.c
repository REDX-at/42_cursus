/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:06:48 by aitaouss          #+#    #+#             */
/*   Updated: 2024/02/02 12:02:26 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	check_num(int n)
{
	if (n < 60)
	{
		if(!print_exit("Error N < 60", 0))
		{
			return (0);
		}
	}
	return(1);
}

int util_check_arg(char **str, int *j)
{
    if ((*str)[*j] != '+' && (*str)[*j] != '-' && (*str)[*j] != 32)
    {
        if (!print_exit("Error : Usage<./philo just digit>", 0))
            return (0);
    }
    if (((*str)[*j] == '-' || (*str)[*j] == '+') && !ft_isdigit((*str)[*j + 1]))
    {
        if (!print_exit("Error : Usage<./philo -digit or +digit>", 0))
            return (0);
    }
    if (ft_isdigit((*str)[*j + 1]) && ft_isdigit((*str)[*j - 1]))
    {
        if (!print_exit("Error : Usage<./philo Not dig-dig>", 0))
            return (0);
    }
    if ((*str)[*j] == '-')
    {
        if (!print_exit("Error : Usage<./philo Positive value>", 0))
            return (0);
    }
    return (1);
}

int check_arg(char **argv)
{
	int i;
	char	*str;
	int		j;

	j= 0;
	i = 1;
	while (argv[i])
	{
		str = argv[i];
		j = 0;
		while (str[j])
		{
			if (!ft_isdigit(str[j]))
			{
				if(!util_check_arg(&str, &j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
