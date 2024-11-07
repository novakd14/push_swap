/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:21:03 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/07 15:15:23 by dnovak           ###   ########.fr       */
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
