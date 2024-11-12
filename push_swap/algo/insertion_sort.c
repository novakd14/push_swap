/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:08:48 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/08 15:53:15 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_order(t_stack *stack, int index)
{
	t_list	*check;
	int		order;

	if (index < stack->min_index)
		return (find_index(stack, stack->max_index));
	if (index > stack->max_index)
		return (find_index(stack, stack->max_index));
	check = stack->stack;
	order = 0;
	if (index > ((t_data *)check->content)->index)
	{
		while (index > ((t_data *)check->content)->index)
		{
			check = check->next;
			order++;
		}
	}
	while (check != NULL && index < ((t_data *)check->content)->index)
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

static void	count_best_move(t_stack *stack_a, t_stack *stack_b, t_move *move,
		t_move *best_move)
{
	t_list	*check;

	check = stack_a->stack;
	while (check != NULL)
	{
		move->order = check_order(stack_b, ((t_data *)check->content)->index);
		move->steps = count_steps(move->position, move->order, stack_a->size,
				stack_b->size);
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

void	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_move	move;
	t_move	best_move;

	stack_b->min_index = ((t_data *)stack_a->stack->content)->index;
	stack_b->max_index = stack_b->min_index;
	ps_push(stack_a, stack_b);
	if (stack_b->min_index > ((t_data *)stack_a->stack->content)->index)
		stack_b->min_index = ((t_data *)stack_a->stack->content)->index;
	else if (stack_b->max_index < ((t_data *)stack_a->stack->content)->index)
		stack_b->max_index = ((t_data *)stack_a->stack->content)->index;
	ps_push(stack_a, stack_b);
	while (stack_a->size > 20)
	{
		move.position = 0;
		best_move.steps = -1;
		count_best_move(stack_a, stack_b, &move, &best_move);
		move_to_positions(best_move.position, best_move.order, stack_a,
			stack_b);
		update_border_indicies(stack_b, stack_a->stack);
		ps_push(stack_a, stack_b);
	}
	setup_border_indicies(stack_a);
}
