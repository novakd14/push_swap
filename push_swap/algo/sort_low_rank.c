/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low_rank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:11:36 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/14 01:31:25 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_min_index(t_stack *stack)
{
	int		min_index;
	t_list	*check;

	check = stack->stack;
	min_index = ((t_data *)check->content)->index;
	while (check != NULL)
	{
		if (min_index > ((t_data *)check->content)->index)
			min_index = ((t_data *)check->content)->index;
		check = check->next;
	}
	return (min_index);
}

void	sort_low_rank(t_stack *stack_a, t_stack *stack_b)
{
	int	target;
	int	i;

	i = 0;
	if (stack_a->size == 3)
		return (sort_rank_three(stack_a));
	if (stack_a->size == 4)
		return (sort_rank_four(stack_a));
	if (stack_a->size == 5)
		return (sort_rank_five(stack_a, stack_b));
	while (stack_a->size > 5)
	{
		target = find_min_index(stack_a);
		rotate_to_top(stack_a, target);
		ps_push(stack_a, stack_b);
		i++;
	}
	sort_rank_five(stack_a, stack_b);
	while (i-- > 0)
		ps_push(stack_b, stack_a);
}
