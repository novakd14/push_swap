/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_positions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:36:57 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/03 12:07:55 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_all_to_position(int position, int end, t_stack *stack_a,
		t_stack *stack_b)
{
	if (end == 0)
		while (position-- > 0)
			ps_rotate_all(stack_a, stack_b);
	else
		while (position++ < end)
			ps_rev_rotate_all(stack_a, stack_b);
}

static void	move_to_position(int position, t_stack *stack)
{
	if (position <= stack->size / 2)
		while (position-- > 0)
			ps_rotate(stack);
	else
		while (position++ < stack->size)
			ps_rev_rotate(stack);
}

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

// static int	ft_max(int a, int b)
// {
// 	if (a > b)
// 		return (a);
// 	return (b);
// }

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static void	use_rotate_all(int position, int order, t_stack *stack_a,
		t_stack *stack_b)
{
	move_all_to_position(ft_min(position, order), 0, stack_a, stack_b);
	if (position > order)
		move_to_position(position - order, stack_b);
	else if (position < order)
		move_to_position(order - position, stack_a);
}

static void	use_rev_rotate_all(int position, int order, t_stack *stack_a,
		t_stack *stack_b)
{
	if (stack_b->size - position > stack_a->size - order)
	{
		move_all_to_position(order, stack_a->size, stack_a, stack_b);
		move_to_position(position + stack_a->size - order, stack_b);
	}
	else if (stack_b->size - position <= stack_a->size - order)
	{
		move_all_to_position(position, stack_b->size, stack_a, stack_b);
		move_to_position(order + stack_b->size - position, stack_a);
	}
}

void	move_to_positions(int position, int order, t_stack *stack_a,
		t_stack *stack_b)
{
	int	strat_moves[3];

	strat_moves[0] = ft_min(position, stack_b->size - position) + ft_min(order,
			stack_a->size - order);
	strat_moves[1] = ft_min(position, order) + ft_abs(position - order);
	strat_moves[2] = ft_min(stack_b->size - position, stack_a->size - order)
		+ ft_abs(stack_b->size - position - stack_a->size + order);
	// ft_printf("%i,%i,%i\n", strat_moves[0], strat_moves[1], strat_moves[2]);
	if ((strat_moves[1] < strat_moves[0]) && (strat_moves[1] < strat_moves[2]))
	{
		use_rotate_all(position, order, stack_a, stack_b);
		return ;
	}
	else if ((strat_moves[2] < strat_moves[0])
		&& (strat_moves[2] < strat_moves[1]))
	{
		use_rev_rotate_all(position, order, stack_a, stack_b);
		return ;
	}
	move_to_position(position, stack_b);
	move_to_position(order, stack_a);
}
