/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:44:09 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/26 12:36:29 by dnovak           ###   ########.fr       */
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

static int	stack_len(t_list *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->stack->next == NULL)
		return ;
	while (!is_sorted(stack_a->stack))
		// adv_bubble_sort(stack_len(stack_a->stack), stack_a, stack_b);
		selection_sort(stack_len(stack_a->stack), stack_a, stack_b);
}
