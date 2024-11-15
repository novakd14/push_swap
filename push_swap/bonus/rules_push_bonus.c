/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:31:24 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/12 13:57:09 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}
