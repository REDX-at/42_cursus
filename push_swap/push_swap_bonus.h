/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:41:20 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/23 16:00:00 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libftt/libft.h"
# include "./printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
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
int		check_if_sorted(t_swap **stack);
void	print_ok_ko(int flag);
void	ft_free_stack_a(t_swap **stack_a);
void	ft_free_stack_b(t_swap **stack_b);
t_swap	*new_list(int content);
void	setup_list(t_swap **new, t_swap **hea, int *c, t_swap **curr);
t_swap	*create_list(char **str, int i, int d);
void	init_stack(t_swap **h, t_swap **c, int *con, t_swap **n_d);
int		check_duplicate(t_swap *list);
int		arg_handlers_bonus(int total, char **str);
void	checker_swap_a(t_swap *stack);
void	checker_swap_b(t_swap *stack);
void	checker_swap_a_b(t_swap *stack_a, t_swap *stack_b);
void	checker_push_a(t_swap **stack_a, t_swap **stack_b);
void	checker_push_b(t_swap **stack_a, t_swap **stack_b);
void	checker_rotate_a(t_swap **stack_a);
void	checker_rotate_b(t_swap **stack_b);
void	checker_rotate_a_b(t_swap **stack_a, t_swap **stack_b);
void	checker_reverse_rotate_a(t_swap **stack_a);
void	checker_reverse_rotate_b(t_swap **stack_b);
void	checker_reverse_rotate_a_b(t_swap **stack_a, t_swap **stack_b);
int		check_if_sorted(t_swap **stack);
t_swap	*ft_lstlastt(t_swap *lst);
void	sort_three(t_swap **stack);
void	case_one(t_swap **stack);
void	case_two(t_swap **stack);
void	case_three(t_swap **stack);
void	case_four(t_swap **stack);
void	case_five(t_swap **stack);
int		ft_lstsizet(t_swap *lst);
void	ft_print_err(void);

#endif