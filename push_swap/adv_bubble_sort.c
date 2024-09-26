/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_bubble_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:46:54 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/15 18:46:41 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_pick(int pick_index, int i, t_stack *stack_a, t_stack *stack_b)
{
	int	j;

	if (i - pick_index > 2)
	{
		j = pick_index + 1;
		ps_push(stack_a, stack_b);
		while (j < i)
		{
			ps_rotate(stack_a);
			j++;
		}
		ps_push(stack_b, stack_a);
		ps_rotate(stack_a);
	}
	else if (i - pick_index == 2)
	{
		ps_swap(stack_a);
		ps_rotate(stack_a);
		ps_rotate(stack_a);
	}
	else
		ps_rotate(stack_a);
}

static t_list	*new_curr_stack(t_list *curr_stack, t_stack *stack_a)
{
	if (curr_stack->next == NULL)
		return (stack_a->stack);
	else
		return (curr_stack->next);
}

void	adv_bubble_sort(int size, t_stack *stack_a, t_stack *stack_b)
{
	int		pick_index;
	int		pick;
	int		i;
	t_list	*curr_stack;

	pick_index = 0;
	pick = *((int *)stack_a->stack->content);
	curr_stack = stack_a->stack->next;
	i = 1;
	while (i < size)
	{
		if (pick < *((int *)curr_stack->content))
		{
			move_pick(pick_index, i, stack_a, stack_b);
			pick_index = i;
			pick = *((int *)stack_a->stack->content);
			curr_stack = stack_a->stack->next;
		}
		else
			curr_stack = new_curr_stack(curr_stack, stack_a);
		i++;
	}
	move_pick(pick_index, size, stack_a, stack_b);
}
