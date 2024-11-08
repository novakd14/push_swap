/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:21:03 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/08 08:39:03 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_message(t_status status, char *message)
{
	if (status == STATUS_SUCCESS)
	{
		write(STDOUT_FILENO, message, ft_strlen(message));
		exit(EXIT_SUCCESS);
	}
	else
	{
		write(STDERR_FILENO, message, ft_strlen(message));
		exit(EXIT_FAILURE);
	}
}

// TEMP
void	print_stack(t_stack *stack)
{
	t_list	*print;

	ft_printf("\t%c:", stack->name);
	print = stack->stack;
	while (print != NULL)
	{
		ft_printf(" %i(%i)", ((t_data *)print->content)->num,
			((t_data *)print->content)->index);
		print = print->next;
	}
	ft_printf("\n");
}

void	update_border_indicies(t_stack *update, t_list *values)
{
	if (update->min_index > ((t_data *)values->content)->index)
		update->min_index = ((t_data *)values->content)->index;
	else if (update->max_index < ((t_data *)values->content)->index)
		update->max_index = ((t_data *)values->content)->index;
}

void	setup_border_indicies(t_stack *stack)
{
	t_list	*check;

	check = stack->stack;
	stack->min_index = ((t_data *)check->content)->index;
	stack->max_index = stack->min_index;
	while (check != NULL)
	{
		update_border_indicies(stack, check);
		check = check->next;
	}
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
