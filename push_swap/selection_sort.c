/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:03:10 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/15 20:47:45 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_up_select_sort(int size, t_stack *stack_a)
{
	int		i;
	int		min;
	int		min_index;
	t_list	*check;

	check = stack_a->stack->next;
	min = *((int *)stack_a->stack->content);
	min_index = 0;
	i = 1;
	while (i < size)
	{
		if (min > *((int *)check->content))
		{
			min = *((int *)check->content);
			min_index = i;
		}
		check = check->next;
		i++;
	}
	if (min_index < size / 2)
		while (min_index-- >= 0)
			ps_rotate(stack_a);
	else
		while (++min_index < size)
			ps_rev_rotate(stack_a);
}

static void	sort_min(int min_index, int size, t_stack *stack_a,
		t_stack *stack_b)
{
	int	index;

	index = min_index;
	if (min_index < size / 2)
		while (index-- > 0)
			ps_rotate(stack_a);
	else
		while (index++ < size)
			ps_rev_rotate(stack_a);
	ps_push(stack_a, stack_b);
	index = min_index;
	if (size - (min_index + 1) < (size - 1) / 2)
		while (index++ < size)
			ps_rotate(stack_a);
	else
		while (index-- > 0)
			ps_rev_rotate(stack_a);
	ps_push(stack_b, stack_a);
	ps_rotate(stack_a);
}

static void	one_select_sort(int sort_size, int size, t_stack *stack_a,
		t_stack *stack_b)
{
	int		i;
	int		min;
	int		min_index;
	t_list	*check;

	check = stack_a->stack->next;
	min = *((int *)stack_a->stack->content);
	min_index = 0;
	i = 1;
	while (i < size - sort_size)
	{
		if (min > *((int *)check->content))
		{
			min = *((int *)check->content);
			min_index = i;
		}
		check = check->next;
		i++;
	}
	sort_min(min_index, size, stack_a, stack_b);
}

void	selection_sort(int size, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	set_up_select_sort(size, stack_a);
	i = 1;
	while (i < size)
		one_select_sort(i++, size, stack_a, stack_b);
}
