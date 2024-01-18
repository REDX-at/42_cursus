/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_instruction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitaouss <aitaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 01:30:43 by aitaouss          #+#    #+#             */
/*   Updated: 2024/01/18 22:57:06 by aitaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_one(t_swap **stack)
{
	reverse_rotate_a(stack, 1);
	swap_a(*stack);
}

void	case_two(t_swap **stack)
{
	swap_a(*stack);
}

void	case_three(t_swap **stack)
{
	reverse_rotate_a(stack, 1);
}

void	case_four(t_swap **stack)
{
	reverse_rotate_a(stack, 1);
	reverse_rotate_a(stack, 1);
}

void	case_five(t_swap **stack)
{
	swap_a(*stack);
	reverse_rotate_a(stack, 1);
}
