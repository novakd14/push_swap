/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:54:40 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/14 15:16:53 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (stack->stack != NULL && stack->stack->next != NULL)
		ps_swap_utils(stack);
	ft_printf("s%c\n", stack->name);
}

void	ps_swap_all(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack != NULL && stack_a->stack->next != NULL)
		ps_swap_utils(stack_a);
	if (stack_b->stack != NULL && stack_b->stack->next != NULL)
		ps_swap_utils(stack_b);
	ft_printf("ss\n");
}
