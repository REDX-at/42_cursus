/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:54:37 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/08 01:20:26 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libftt/libft.h"
# include "./printf/ft_printf.h"

typedef struct s_swap
{
	int					content;
	struct s_swap	*next;
	struct s_swap	*prev;
}	t_swap;

int    arg_handlers(int total, char **str);
void    swap_a(t_swap *list);
void	swap_b(t_swap *list);
void	swap_a_b(t_swap *stack_a, t_swap *stack_b);
void	push_b(t_swap *stack_a, t_swap *stack_b);
void	rotate_a(t_swap *stack_a);
void	rotate_b(t_swap *stack_b);
t_swap	*create_empty_stack();

#endif