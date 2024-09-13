/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:51:19 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/12 16:17:32 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	char	name;
	t_list	*stack;
}			t_stack;

void		free_all(t_stack *stack);
void		error_exit(t_stack *stack);
void		input(int argc, char **argv, t_stack *stack);

// Rules
void		ps_swap(t_stack *stack);
void		ps_push(t_stack *from, t_stack *to);
void		ps_rotate(t_stack *stack);
void		ps_rev_rotate(t_stack *stack);
void		sort(t_stack *stack_a, t_stack *stack_b);

#endif // PUSH_SWAP_H
