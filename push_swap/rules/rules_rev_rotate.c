/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:03:32 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/08 11:54:38 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ps_rev_rotate_utils(t_stack *stack)
{
	t_list	*second_last;

	second_last = stack->stack;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	second_last->next->next = stack->stack;
	stack->stack = second_last->next;
	second_last->next = NULL;
}

// Shift down all elements of stack by 1. The last element becomes
// the first one.
void	ps_rev_rotate(t_stack *stack)
{
	if (stack->stack == NULL || stack->stack->next == NULL)
		return ;
	ps_rev_rotate_utils(stack);
	ft_printf("rr%c\n", stack->name);
}

void	ps_rev_rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->stack == NULL || stack_a->stack->next == NULL)
		|| (stack_b->stack == NULL || stack_b->stack->next == NULL))
		return ;
	ps_rev_rotate_utils(stack_a);
	ps_rev_rotate_utils(stack_b);
	ft_printf("rrr\n");
}
