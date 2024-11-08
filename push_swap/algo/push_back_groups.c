/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_groups.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:55:53 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/08 11:56:28 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_order_group(t_stack *stack, int index)
{
	t_list	*check;
	int		order;

	if (index < stack->min_index)
		return (find_index(stack, stack->min_index));
	if (index > stack->max_index)
		return (find_index(stack, stack->min_index));
	check = stack->stack;
	order = 0;
	if (index < ((t_data *)check->content)->index)
	{
		while (index < ((t_data *)check->content)->index)
		{
			check = check->next;
			order++;
		}
	}
	while (check != NULL && index > ((t_data *)check->content)->index)
	{
		check = check->next;
		order++;
	}
	return (order % stack->size);
}

static int	count_steps(int ra, int rb, int size_a, int size_b)
{
	int	rra;
	int	rrb;
	int	min_steps;

	rra = size_a - ra;
	rrb = size_b - rb;
	min_steps = ft_max(ra, rb);
	min_steps = ft_min(min_steps, ft_max(rra, rrb));
	min_steps = ft_min(min_steps, ra + rrb);
	min_steps = ft_min(min_steps, rra + rb);
	return (min_steps);
}

static void	count_best_move(t_stack *from, t_stack *to, t_move *move,
		t_move *best_move)
{
	t_list	*check;

	check = from->stack;
	move->position = 0;
	best_move->steps = -1;
	while (check != NULL)
	{
		move->order = check_order_group(to, ((t_data *)check->content)->index);
		move->steps = count_steps(move->position, move->order, from->size,
				to->size);
		if (best_move->steps == -1 || best_move->steps > move->steps)
		{
			best_move->steps = move->steps;
			best_move->position = move->position;
			best_move->order = move->order;
		}
		check = check->next;
		move->position++;
	}
}

void	push_back_groups(t_stack *stack_a, t_stack *stack_b)
{
	t_move	move;
	t_move	best_move;

	setup_border_indicies(stack_a);
	while (stack_b->stack != NULL)
	{
		count_best_move(stack_b, stack_a, &move, &best_move);
		move_to_positions(best_move.order, best_move.position, stack_a,
			stack_b);
		update_border_indicies(stack_a, stack_b->stack);
		ps_push(stack_b, stack_a);
	}
}
