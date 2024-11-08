/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_positions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:29:08 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/08 08:30:26 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_position(int position, t_stack *stack)
{
	if (position <= stack->size - position)
		while (position-- > 0)
			ps_rotate(stack);
	else
		while (position++ < stack->size)
			ps_rev_rotate(stack);
}

static void	use_rotate_all(int ra, int rb, t_stack *stack_a, t_stack *stack_b)
{
	int	rr;

	rr = 0;
	while (rr < ft_min(ra, rb))
	{
		ps_rotate_all(stack_a, stack_b);
		rr++;
	}
	move_to_position(ra - rr, stack_a);
	move_to_position(rb - rr, stack_b);
}

static void	use_rev_rotate_all(int ra, int rb, t_stack *stack_a,
		t_stack *stack_b)
{
	int	rra;
	int	rrb;
	int	rrr;

	rra = stack_a->size - ra;
	rrb = stack_b->size - rb;
	rrr = 0;
	while (rrr < ft_min(rra, rrb))
	{
		ps_rev_rotate_all(stack_a, stack_b);
		rrr++;
	}
	move_to_position(ra + rrr, stack_a);
	move_to_position(rb + rrr, stack_b);
}

void	move_to_positions(int ra, int rb, t_stack *stack_a, t_stack *stack_b)
{
	int	rra;
	int	rrb;
	int	min_steps;

	rra = stack_a->size - ra;
	rrb = stack_b->size - rb;
	min_steps = ft_max(ra, rb);
	min_steps = ft_min(min_steps, ft_max(rra, rrb));
	min_steps = ft_min(min_steps, ra + rrb);
	min_steps = ft_min(min_steps, rra + rb);
	if (ft_max(ra, rb) == min_steps)
		use_rotate_all(ra, rb, stack_a, stack_b);
	else if (ft_max(rra, rrb) == min_steps)
		use_rev_rotate_all(ra, rb, stack_a, stack_b);
	else
	{
		move_to_position(ra, stack_a);
		move_to_position(rb, stack_b);
	}
}
