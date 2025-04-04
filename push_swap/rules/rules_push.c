/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:31:24 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/08 11:54:33 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_push(t_stack *from, t_stack *to)
{
	t_list	*move;

	if (from->stack == NULL)
		return ;
	move = from->stack;
	from->stack = move->next;
	move->next = to->stack;
	to->stack = move;
	from->size--;
	to->size++;
	ft_printf("p%c\n", to->name);
}
