/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:41:23 by dnovak            #+#    #+#             */
/*   Updated: 2024/10/02 14:21:11 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stack(t_stack **stack, char name)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (*stack == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	(*stack)->name = name;
	(*stack)->stack = NULL;
	(*stack)->size = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (init_stack(&stack_a, 'a') == 0)
		return (1);
	input(argc, argv, stack_a);
	if (init_stack(&stack_b, 'b') == 0)
		error_exit(stack_a);
	sort(stack_a, stack_b);
	free_all(stack_a);
	free_all(stack_b);
	return (0);
}
