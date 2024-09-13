/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:31:24 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/11 22:19:30 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_stack *stack)
{
	t_list	*second;

	if (stack->stack == NULL || stack->stack->next == NULL)
		return ;
	second = stack->stack->next;
	stack->stack->next = second->next;
	second->next = stack->stack;
	stack->stack = second;
	ft_printf("s%c\n", stack->name);
}

void	ps_push(t_stack *from, t_stack *to)
{
	t_list	*move;

	if (from->stack == NULL)
		return ;
	move = from->stack;
	from->stack = move->next;
	move->next = to->stack;
	to->stack = move;
	ft_printf("p%c\n", to->name);
}

// Shift up all elements of stack by 1. The first element becomes the last one.
void	ps_rotate(t_stack *stack)
{
	t_list	*first_to_last;

	if (stack->stack == NULL || stack->stack->next == NULL)
		return ;
	first_to_last = stack->stack;
	stack->stack = first_to_last->next;
	first_to_last->next = NULL;
	ft_lstlast(stack->stack)->next = first_to_last;
	ft_printf("r%c\n", stack->name);
}

// Shift down all elements of stack by 1. The last element becomes the first one.
void	ps_rev_rotate(t_stack *stack)
{
	t_list	*second_last;

	if (stack->stack == NULL || stack->stack->next == NULL)
		return ;
	second_last = stack->stack;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	second_last->next->next = stack->stack;
	stack->stack = second_last->next;
	second_last->next = NULL;
	ft_printf("rr%c\n", stack->name);
}
