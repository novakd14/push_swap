/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:18:35 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/07 23:05:23 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_by_lead_bit(t_stack *from, t_stack *to, int lead_bit, int keep)
{
	int	i;
	int	index_count;
	int	curr_index;

	i = 0;
	index_count = from->size;
	while (i++ < index_count)
	{
		curr_index = ((t_data *)from->stack->content)->index;
		if (((lead_bit & curr_index) > 0) == keep)
			ps_rotate(from);
		else
			ps_push(from, to);
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	lead_bit;
	int	bit_count;

	bit_count = stack_a->size - 1;
	lead_bit = 1;
	while (bit_count != 0)
	{
		sort_by_lead_bit(stack_b, stack_a, lead_bit, 0);
		sort_by_lead_bit(stack_a, stack_b, lead_bit, 1);
		bit_count >>= 1;
		lead_bit <<= 1;
	}
	while (stack_b->stack != NULL)
		ps_push(stack_b, stack_a);
}
