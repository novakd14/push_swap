/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:21:03 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/02 15:17:23 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{
	ft_printf("\t   ");
	while (stack != NULL)
	{
		ft_printf(" %i", *((int *)stack->content));
		stack = stack->next;
	}
	ft_printf("\n");
}
