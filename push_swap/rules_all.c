/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:30:13 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/02 13:32:30 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap_all(t_stack *stack_a, t_stack *stack_b)
{
	ps_swap(stack_a);
	ps_swap(stack_b);
}

void	ps_rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	ps_rotate(stack_a);
	ps_rotate(stack_b);
}

void	ps_rev_rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	ps_rev_rotate(stack_a);
	ps_rev_rotate(stack_b);
}
