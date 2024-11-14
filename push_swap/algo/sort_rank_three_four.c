/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rank_three_four.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:20:45 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/14 01:25:10 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_temp_to_top(t_stack *stack, int temp_target)
{
	int		i;
	t_list	*check;

	check = stack->stack;
	i = 0;
	while (((t_data *)check->content)->temp_index != temp_target)
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

void	set_temp_indicies(t_stack *stack)
{
	t_list	*check;
	t_list	*comp;
	int		check_num;

	check = stack->stack;
	while (check != NULL)
	{
		((t_data *)check->content)->temp_index = 0;
		check_num = ((t_data *)check->content)->num;
		comp = stack->stack;
		while (comp != NULL)
		{
			if (check_num > ((t_data *)comp->content)->num)
				((t_data *)check->content)->temp_index += 1;
			comp = comp->next;
		}
		check = check->next;
	}
}

void	sort_rank_three(t_stack *stack)
{
	t_list	*check;
	int		option;

	set_temp_indicies(stack);
	check = stack->stack;
	while (((t_data *)check->content)->temp_index != 0)
		check = check->next;
	if (check->next != NULL)
		check = check->next;
	else
		check = stack->stack;
	option = ((t_data *)check->content)->temp_index;
	if (option == 2)
		ps_swap(stack);
	rotate_temp_to_top(stack, 0);
}

static void	load_options_four(int (*options)[2], t_stack *stack)
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
}

void	sort_rank_four(t_stack *stack)
{
	int	options[2];

	set_temp_indicies(stack);
	load_options_four(&options, stack);
	if (options[0] == 1 && options[1] == 2)
		return (rotate_temp_to_top(stack, 0));
	else if (options[0] == 1 && options[1] == 3)
		rotate_temp_to_top(stack, 3);
	else if (options[0] == 2 && options[1] == 1)
		rotate_temp_to_top(stack, 2);
	else if (options[0] == 2 && options[1] == 3)
		rotate_temp_to_top(stack, 1);
	else if (options[0] == 3 && options[1] == 1)
		rotate_temp_to_top(stack, 0);
	else
	{
		rotate_temp_to_top(stack, 3);
		ps_swap(stack);
		rotate_temp_to_top(stack, 1);
	}
	ps_swap(stack);
	rotate_temp_to_top(stack, 0);
}
