/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 00:44:08 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/09 22:31:30 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *stack)
{
	t_list	*next;

	while (stack->stack != NULL)
	{
		if (stack->stack->content != NULL)
			free(stack->stack->content);
		next = stack->stack->next;
		free(stack->stack);
		stack->stack = next;
	}
	free(stack);
}

void	error_exit(t_stack *stack)
{
	free_all(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
