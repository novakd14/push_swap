/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimalist_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:40:42 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/26 15:01:56 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_rank_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;
	int	order;

	a = *((int *)stack->stack->content);
	b = *((int *)stack->stack->next->content);
	c = *((int *)stack->stack->next->next->content);
	order = 0;
	if (a > b)
		order += 1;
	if (b > c)
		order += 2;
	if (a > c)
		order += 3;
	if (order == 1 || order == 2 || order == 6)
		ps_swap(stack);
	if (order == 2 || order == 4)
		ps_rotate(stack);
	if (order == 5 || order == 6)
		ps_rev_rotate(stack);
}

void	minimalist_sort(int size, t_stack *stack_a, t_stack *stack_b)
{
	while (size > 3)
	{
		ps_push(stack_a, stack_b);
		size--;
	}
	sort_rank_three(stack_a);
}
