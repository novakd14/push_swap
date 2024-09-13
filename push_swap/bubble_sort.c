/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:46:54 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/13 17:50:35 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int size, t_stack *stack_a, t_stack *stack_b)
{
	int		pick_index;
	int		pick;
	int		i;
	int		j;
	t_list	*curr_stack;

	pick_index = 0;
	pick = *((int *)stack_a->stack->content);
	curr_stack = stack_a->stack->next;
	i = 1;
	while (i < size)
	{
		if (pick < *((int *)curr_stack->content))
		{
			ft_printf("Found bigger number\n");
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
			break ;
			pick_index = i;
			pick = *((int *)stack_a->stack->content);
			curr_stack = stack_a->stack->next;
		}
		else
		{
			if (curr_stack->next == NULL)
				curr_stack = stack_a->stack;
			else
				curr_stack = curr_stack->next;
			ft_printf("Next\n");
		}
		i++;
	}
	if (stack_b)
		return ;
	// if (i - pick_index > 1)
	// {
	// 	j = pick_index;
	// 	ps_push(stack_a, stack_b);
	// 	while (j < i)
	// 	{
	// 		ps_rotate(stack_a);
	// 		j++;
	// 	}
	// 	ps_push(stack_b, stack_a);
	// 	ps_rotate(stack_a);
	// }
	// curr_stack = stack_a->stack->next;
	// pick = *((int *)stack_a->stack->content);
	// pick_index = i;
}
