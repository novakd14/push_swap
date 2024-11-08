/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:41:23 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/08 12:15:00 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *stack, char name)
{
	stack->name = name;
	stack->stack = NULL;
	stack->size = 0;
	stack->min_index = 0;
	stack->max_index = 0;
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (check_input(argc, argv) == STATUS_ERROR)
		exit_message(STATUS_ERROR, ERROR_MESS);
	init_stack(&stack_a, 'a');
	load_input(argc, argv, &stack_a);
	init_stack(&stack_b, 'b');
	sort(&stack_a, &stack_b);
	ft_lstclear(&(stack_a.stack), &del_content);
	ft_lstclear(&(stack_b.stack), &del_content);
	return (0);
}
