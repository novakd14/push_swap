/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_to_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:26:34 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/30 15:30:09 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_move_arr(t_move *move)
{
	move->position = 0;
	move->order = 0;
	move->moves = -1;
}

static void	copy_move_arr(t_move *from, t_move *to)
{
	to->position = from->position;
	to->order = from->order;
	to->moves = from->moves;
}

static int	check_order(int start, t_list *stack_a, t_list *stack_b)
{
	int	order;

	order = 0;
	if (*((int *)stack_b->content) > *((int *)stack_a->content) && start != 0)
	{
		while ((order < start)
			&& (*((int *)stack_b->content) > *((int *)stack_a->content)))
		{
			stack_a = stack_a->next;
			order++;
		}
		return (order);
	}
	while (order < start)
	{
		stack_a = stack_a->next;
		order++;
	}
	while (stack_a != NULL
		&& *((int *)stack_b->content) > *((int *)stack_a->content))
	{
		stack_a = stack_a->next;
		order++;
	}
	return (order);
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

int	choose_to_move(int start, t_stack *stack_a, t_stack *stack_b)
{
	t_move	curr_move;
	t_move	min_move;
	t_list	*position;

	init_move_arr(&min_move);
	init_move_arr(&curr_move);
	position = stack_b->stack;
	while (position != NULL)
	{
		curr_move.order = check_order(start, stack_a->stack, position);
		if (curr_move.position <= stack_b->size / 2)
			curr_move.moves = curr_move.position;
		else
			curr_move.moves = stack_b->size - curr_move.position;
		if (curr_move.order <= stack_a->size / 2)
			curr_move.moves += curr_move.order;
		else
			curr_move.moves += stack_a->size - curr_move.order;
		if (min_move.moves < 0 || curr_move.moves < min_move.moves)
			copy_move_arr(&curr_move, &min_move);
		position = position->next;
		curr_move.position++;
	}
	move_to_position(min_move.position, stack_b);
	return (min_move.order);
}
