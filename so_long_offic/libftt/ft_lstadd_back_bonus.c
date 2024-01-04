/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:59:22 by aitaouss          #+#    #+#             */
/*   Updated: 2023/11/14 09:58:18 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *jdida)
{
	t_list	*tmp;

	if (!lst || !jdida)
		return ;
	if (!*lst)
	{
		*lst = jdida;
		return ;
	}
	tmp = *lst;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = jdida;
			return ;
		}
		tmp = tmp->next;
	}
}
