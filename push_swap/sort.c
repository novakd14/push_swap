/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:44:09 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/13 14:28:04 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list *stack)
{
	int	compare;

	if (stack == NULL || stack->next == NULL)
		return (1);
	compare = *((int *)stack->content);
	stack = stack->next;
	while (stack != NULL)
	{
		if (*((int *)stack->content) < compare)
			return (0);
		compare = *((int *)stack->content);
		stack = stack->next;
	}
	return (1);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a->stack))
		ft_printf("Stack is sorted!\n");
	else
		ft_printf("Stack is NOT sorted!\n");
	is_sorted(stack_b->stack);
}
