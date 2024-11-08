/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low_rank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:11:36 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/08 11:54:26 by dnovak           ###   ########.fr       */
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

static void	sort_rank_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;
	int	order;

	a = ((t_data *)stack->stack->content)->index;
	b = ((t_data *)stack->stack->next->content)->index;
	c = ((t_data *)stack->stack->next->next->content)->index;
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

void	sort_low_rank(t_stack *stack_a, t_stack *stack_b)
{
	int	target;
	int	i;

	i = 0;
	while (stack_a->size > 3)
	{
		target = find_min_index(stack_a);
		rotate_to_top(stack_a, target);
		ps_push(stack_a, stack_b);
		i++;
	}
	sort_rank_three(stack_a);
	while (i-- > 0)
		ps_push(stack_b, stack_a);
}
