/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:54:40 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/12 13:57:24 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ps_swap_utils(t_stack *stack)
{
	t_list	*second;

	second = stack->stack->next;
	stack->stack->next = second->next;
	second->next = stack->stack;
	stack->stack = second;
}

void	ps_swap(t_stack *stack)
{
	if (stack->stack == NULL || stack->stack->next == NULL)
		return ;
	ps_swap_utils(stack);
}

void	ps_swap_all(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->stack == NULL || stack_a->stack->next == NULL)
		|| (stack_b->stack == NULL || stack_b->stack->next == NULL))
		return ;
	ps_swap_utils(stack_a);
	ps_swap_utils(stack_b);
}
