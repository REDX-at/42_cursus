/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:54:37 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/16 00:37:41 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libftt/libft.h"
# include "./printf/ft_printf.h"
#include <stdbool.h>

typedef struct s_swap
{
	int				content;
	int				index;
	int				above_median;
	int				cheapest_move;
	struct s_swap	*next;
	struct s_swap	*prev;
	struct s_swap	*target_node;	
}	t_swap;

int    arg_handlers(int total, char **str);
void    swap_a(t_swap *stack);
void	swap_b(t_swap *list);
void	swap_a_b(t_swap *stack_a, t_swap *stack_b);
void	push_b(t_swap **stack_a, t_swap **stack_b);
void	rotate_a(t_swap **stack_a);
void	rotate_b(t_swap **stack_b);
void	reverse_rotate_a(t_swap **stack_a);
void	reverse_rotate_b(t_swap **stack_b);
void	reverse_rotate_a_b(t_swap **stack_a, t_swap **stack_b);
int		check_if_sorted(t_swap **stack);
int		sort_list(t_swap **stack);
t_swap	*ft_lstlastt(t_swap *lst);
void	sort_three(t_swap **stack);
void	push_a(t_swap **stack_a, t_swap **stack_b);
void	case_one(t_swap **stack);
void	case_two(t_swap **stack);
void	case_three(t_swap **stack);
void	case_four(t_swap **stack);
void	case_five(t_swap **stack);
int		get_med(t_swap **stack_a);
int		ft_lstsizet(t_swap *lst);
void	index_target(t_swap **stack);
void	sort_turk(t_swap **stack_a, t_swap **stack_b);
void	check_above_median(t_swap **stack_a, t_swap ** stack_b);
void	find_target(t_swap **stack_a, t_swap **stack_b);
int		find_min(t_swap **stack_a);

#endif