/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:44:09 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/30 15:29:24 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	is_sorted(t_list *stack)
// {
// 	int	compare;

// 	if (stack == NULL || stack->next == NULL)
// 		return (1);
// 	compare = *((int *)stack->content);
// 	stack = stack->next;
// 	while (stack != NULL)
// 	{
// 		if (*((int *)stack->content) < compare)
// 			return (0);
// 		compare = *((int *)stack->content);
// 		stack = stack->next;
// 	}
// 	return (1);
// }

static void	sort_rank_two(t_stack *stack)
{
	int	a;
	int	b;

	a = *((int *)stack->stack->content);
	b = *((int *)stack->stack->next->content);
	if (a > b)
		ps_swap(stack);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 1)
		return ;
	if (stack_a->size == 2)
		return (sort_rank_two(stack_a));
	minimalist_sort(stack_a, stack_b);
}
