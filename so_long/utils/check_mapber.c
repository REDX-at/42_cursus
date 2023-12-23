/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:03:52 by aitaouss          #+#    #+#             */
/*   Updated: 2023/12/23 22:47:27 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int to_find(char *str, char *to_find)
{
    int j = 0;
    int i = 0;
    while (str[i] && to_find[j])
    {
        if (str[i] == to_find[j])
            j++;
        i++;
    }
    if (to_find[j] == '\0')
        return 1;
    return 0;
}

int check_map_ber(char *str)
{
    int i = 0;
    int find = 0;
    
    while (str[i])
    {
        if (str[i] == '.')
            find = to_find(str, ".ber");
        i++;
    }
    if (find == 1)
        return 1;
    return 0;
}
