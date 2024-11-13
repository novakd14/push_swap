/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:44:09 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/12 03:09:00 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ft_issorted(t_stack *stack)
{
	t_list	*check;

	check = stack->stack;
	if (((t_data *)check->content)->index != 0)
		return (FALSE);
	while (check->next != NULL)
	{
		if (((t_data *)check->content)->index
			+ 1 != ((t_data *)check->next->content)->index)
			return (FALSE);
		check = check->next;
	}
	return (TRUE);
}

static t_bool	ft_isrotated(t_stack *stack)
{
	t_list	*check;

	check = stack->stack;
	while (check->next != NULL)
	{
		if ((((t_data *)check->content)->index
				+ 1 != ((t_data *)check->next->content)->index)
			&& ((t_data *)check->next->content)->index != 0)
			return (FALSE);
		check = check->next;
	}
	return (TRUE);
}

void	rotate_to_top(t_stack *stack, int target)
{
	int		i;
	t_list	*check;

	check = stack->stack;
	i = 0;
	while (((t_data *)check->content)->index != target)
	{
		check = check->next;
		i++;
	}
	if (i <= stack->size - i)
		while (i-- > 0)
			ps_rotate(stack);
	else
		while (i++ < stack->size)
			ps_rev_rotate(stack);
}

static void	push_back(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	last_index;

	last_index = ((t_data *)ft_lstlast(stack_a->stack)->content)->index;
	while (stack_b->stack != NULL)
	{
		index = ((t_data *)stack_b->stack->content)->index;
		if (index < stack_a->min_index || index > stack_a->max_index)
		{
			rotate_to_top(stack_a, stack_a->min_index);
			update_border_indicies(stack_a, stack_b->stack);
			ps_push(stack_b, stack_a);
		}
		else if (index > last_index)
		{
			update_border_indicies(stack_a, stack_b->stack);
			ps_push(stack_b, stack_a);
		}
		else
		{
			ps_rev_rotate(stack_a);
			last_index = ((t_data *)ft_lstlast(stack_a->stack)->content)->index;
		}
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_issorted(stack_a) == TRUE)
		return ;
	if (ft_isrotated(stack_a) == TRUE)
		return (rotate_to_top(stack_a, 0));
	if (stack_a->size <= 20)
		return (sort_low_rank(stack_a, stack_b));
	if (stack_a->size <= 185)
	{
		insertion_sort(stack_a, stack_b);
		sort_low_rank(stack_a, stack_b);
		rotate_to_top(stack_b, stack_b->max_index);
		push_back(stack_a, stack_b);
		rotate_to_top(stack_a, 0);
	}
	else
	{
		group_sort(stack_a, stack_b);
		sort_low_rank(stack_a, stack_b);
		push_back_groups(stack_a, stack_b);
		rotate_to_top(stack_a, 0);
	}
}
