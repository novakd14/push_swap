/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:20:24 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/08 11:56:21 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_first_groups(t_stack *stack_a, t_stack *stack_b, int limit)
{
	int	i;
	int	size;

	i = 0;
	while (i < 7)
	{
		size = stack_a->size;
		while (size-- > 0 && stack_a->size > 3)
		{
			if (((t_data *)stack_a->stack->content)->index < limit * i)
				ps_push(stack_a, stack_b);
			else if (((t_data *)stack_a->stack->content)->index < limit * (i
					+ 1))
			{
				ps_push(stack_a, stack_b);
				ps_rotate(stack_b);
			}
			else
				ps_rotate(stack_a);
		}
		i += 2;
	}
}

static void	sort_last_group(t_stack *stack_a, t_stack *stack_b, int limit)
{
	int	size;

	size = stack_a->size;
	while (size-- > 3)
	{
		if (((t_data *)stack_a->stack->content)->index < limit * 7)
			ps_push(stack_a, stack_b);
		else
		{
			ps_push(stack_a, stack_b);
			ps_rotate(stack_b);
		}
	}
}

void	group_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	limit;

	limit = stack_a->size / 8;
	sort_first_groups(stack_a, stack_b, limit);
	sort_last_group(stack_a, stack_b, limit);
}
