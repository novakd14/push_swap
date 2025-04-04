/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:00:16 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/14 15:13:11 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ps_rotate_utils(t_stack *stack)
{
	t_list	*first_to_last;

	first_to_last = stack->stack;
	stack->stack = first_to_last->next;
	first_to_last->next = NULL;
	ft_lstlast(stack->stack)->next = first_to_last;
}

// Shift up all elements of stack by 1. The first element becomes the last one.
void	ps_rotate(t_stack *stack)
{
	if (stack->stack != NULL && stack->stack->next != NULL)
		ps_rotate_utils(stack);
}

void	ps_rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack != NULL && stack_a->stack->next != NULL)
		ps_rotate_utils(stack_a);
	if (stack_b->stack != NULL && stack_b->stack->next != NULL)
		ps_rotate_utils(stack_b);
}
