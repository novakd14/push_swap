/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rank_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:30:54 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/14 01:25:22 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	load_options_five(int (*options)[3], t_stack *stack)
{
	t_list	*check;

	check = stack->stack;
	while (((t_data *)check->content)->temp_index != 0)
		check = check->next;
	if (check->next != NULL)
		check = check->next;
	else
		check = stack->stack;
	(*options)[0] = ((t_data *)check->content)->temp_index;
	if (check->next != NULL)
		check = check->next;
	else
		check = stack->stack;
	(*options)[1] = ((t_data *)check->content)->temp_index;
	if (check->next != NULL)
		check = check->next;
	else
		check = stack->stack;
	(*options)[2] = ((t_data *)check->content)->temp_index;
}

static void	special_case_143(t_stack *stack_a, t_stack *stack_b)
{
	rotate_temp_to_top(stack_a, 0);
	ps_push(stack_a, stack_b);
	ps_push(stack_a, stack_b);
	ps_swap(stack_a);
	ps_rev_rotate(stack_a);
	ps_push(stack_b, stack_a);
	ps_push(stack_b, stack_a);
}

static void	special_case_214(t_stack *stack_a)
{
	rotate_temp_to_top(stack_a, 2);
	ps_swap(stack_a);
	rotate_temp_to_top(stack_a, 4);
	ps_swap(stack_a);
	rotate_temp_to_top(stack_a, 0);
}

static void	special_case_321(t_stack *stack_a)
{
	rotate_temp_to_top(stack_a, 3);
	ps_swap(stack_a);
	ps_rotate(stack_a);
	ps_swap(stack_a);
	ps_rev_rotate(stack_a);
	ps_swap(stack_a);
	rotate_temp_to_top(stack_a, 0);
}

void	sort_rank_five(t_stack *stack_a, t_stack *stack_b)
{
	int	options[3];

	set_temp_indicies(stack_a);
	load_options_five(&options, stack_a);
	if (options[0] == 1 && options[1] == 2 && options[2] == 3)
		rotate_temp_to_top(stack_a, 0);
	else if (options[0] == 1 && options[1] == 2 && options[2] == 4)
	{
		rotate_temp_to_top(stack_a, 4);
		ps_swap(stack_a);
		rotate_temp_to_top(stack_a, 0);
	}
	else if (options[0] == 1 && options[1] == 4 && options[2] == 3)
		special_case_143(stack_a, stack_b);
	else if (options[0] == 2 && options[1] == 1 && options[2] == 4)
		special_case_214(stack_a);
	else if (options[0] == 3 && options[1] == 2 && options[2] == 1)
		special_case_321(stack_a);
	else
	{
		rotate_temp_to_top(stack_a, 0);
		ps_push(stack_a, stack_b);
		sort_rank_four(stack_a);
		ps_push(stack_b, stack_a);
	}
}
