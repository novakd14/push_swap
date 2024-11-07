/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimalist_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:40:42 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/07 21:47:15 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	return_order(int order, t_stack *stack_a)
{
	if (order <= stack_a->size / 2)
		while (order-- > 0)
			ps_rotate(stack_a);
	else
		while (order++ < stack_a->size)
			ps_rev_rotate(stack_a);
}

static int	check_if_bigger(t_stack *small, t_stack *big)
{
	if (*((int *)big->stack->content) > *((int *)small->stack->content))
		return (1);
	return (0);
}

void	minimalist_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	start;
	int	order;

	while (stack_a->size > 3)
		ps_push(stack_a, stack_b);
	sort_rank_three(stack_a);
	start = 0;
	while (stack_b->stack != NULL)
	{
		order = choose_to_move(start, stack_a, stack_b);
		start = (start + stack_a->size - order) % (stack_a->size);
		if (start != 0 || check_if_bigger(stack_a, stack_b))
			start++;
		ps_push(stack_b, stack_a);
	}
	return_order(start, stack_a);
}
