/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:44:09 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/07 21:07:40 by dnovak           ###   ########.fr       */
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

static void	rotate_to_top(t_stack *stack)
{
	int		i;
	t_list	*check;

	check = stack->stack;
	i = 0;
	while (((t_data *)check->content)->index != 0)
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

static void	sort_rank_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;
	int	order;

	a = ((t_data *)stack->stack->content)->index;
	b = ((t_data *)stack->stack->next->content)->index;
	c = ((t_data *)stack->stack->next->next->content)->index;
	order = 0;
	if (a > b)
		order += 1;
	if (b > c)
		order += 2;
	if (a > c)
		order += 3;
	if (order == 1 || order == 2 || order == 6)
		ps_swap(stack);
	if (order == 2 || order == 4)
		ps_rotate(stack);
	if (order == 5 || order == 6)
		ps_rev_rotate(stack);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_issorted(stack_a) == TRUE)
		return ;
	if (ft_isrotated(stack_a) == TRUE)
		return (rotate_to_top(stack_a));
	if (stack_a->size == 3)
		return (sort_rank_three(stack_a));
	radix_sort(stack_a, stack_b);
}
