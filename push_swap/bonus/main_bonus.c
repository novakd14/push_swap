/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:30:37 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/12 02:15:52 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	init_stack(t_stack *stack, char name)
{
	stack->name = name;
	stack->stack = NULL;
	stack->size = 0;
	stack->min_index = 0;
	stack->max_index = 0;
}

static t_bool	ft_issorted(t_stack *stack)
{
	t_list	*check;

	check = stack->stack;
	if (((t_data *)check->content)->index != 0)
		return (FALSE);
	while (check->next != NULL)
	{
		if (((t_data *)check->content)->index
			+ 1 != ((t_data *)check->next->content)->index)
			return (FALSE);
		check = check->next;
	}
	return (TRUE);
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
	if (load_input(argc, argv, &stack_a) == STATUS_ERROR)
	{
		ft_lstclear(&(stack_a.stack), &del_content);
		exit_message(STATUS_ERROR, ERROR_MESS);
	}
	stack_a.size = ft_lstsize(stack_a.stack);
	init_stack(&stack_b, 'b');
	read_instructions(&stack_a, &stack_b);
	if (ft_issorted(&stack_a) == TRUE && stack_b.stack == NULL)
		write(STDOUT_FILENO, "OK\n", 4);
	else
		write(STDOUT_FILENO, "KO\n", 4);
	ft_lstclear(&(stack_a.stack), &del_content);
	ft_lstclear(&(stack_b.stack), &del_content);
	return (EXIT_SUCCESS);
}
