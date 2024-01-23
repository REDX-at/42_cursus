/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:54:37 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/23 15:45:06 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libftt/libft.h"
# include "./printf/ft_printf.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_swap
{
	int				content;
	int				index;
	int				above_median;
	int				cheapest_move;
	int				cheapest_cost;
	struct s_swap	*next;
	struct s_swap	*prev;
	struct s_swap	*target_node;	
}	t_swap;

typedef struct s_data
{
	int	spy;
	int	midd;
	int	j;
	int	i;
}	t_data;

void	check_arg(char **str);
int		arg_handlers(int total, char **str);
void	swap_a(t_swap *stack);
void	swap_b(t_swap *stack);
void	swap_a_b(t_swap *stack_a, t_swap *stack_b);
void	push_b(t_swap **stack_a, t_swap **stack_b);
void	rotate_a(t_swap **stack_a, int flag);
void	rotate_b(t_swap **stack_b, int flag);
void	rotate_a_b(t_swap **stack_a, t_swap **stack_b);
void	reverse_rotate_a(t_swap **stack_a, int flag);
void	reverse_rotate_b(t_swap **stack_b, int flag);
void	reverse_rotate_a_b(t_swap **stack_a, t_swap **stack_b);
int		check_if_sorted(t_swap **stack);
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
void	find_target(t_swap **stack_a, t_swap **stack_b);
int		find_min(t_swap **stack_a);
t_swap	*find_minswap(t_swap **stack_a);
void	fin_cheap(t_swap **stack_a, t_swap **stack_b);
void	get_cheapest_cost(t_swap **stack_b);
t_swap	*find_cheap_cost(t_swap **stack_b);
void	first_step(t_swap **stack_a, t_swap **stack_b, int *size, int *med);
void	push_back(t_swap **stack_a, t_swap **stack_b);
void	finish_stack(t_swap **stack_a);
void	move_to_top(t_swap **stack_a, t_swap **stack_b, t_swap	*to_push);
void	ft_print_err(void);
t_swap	*create_list(char **str, int i, int d);

#endif