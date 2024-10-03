/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:00:16 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/02 15:19:49 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (stack->stack == NULL || stack->stack->next == NULL)
		return ;
	ps_rotate_utils(stack);
	ft_printf("r%c\n", stack->name);
}

void	ps_rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->stack == NULL || stack_a->stack->next == NULL)
		|| (stack_b->stack == NULL || stack_b->stack->next == NULL))
		return ;
	ps_rotate_utils(stack_a);
	ps_rotate_utils(stack_b);
	ft_printf("rr\n");
}
