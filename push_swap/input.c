/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:43:38 by dnovak            #+#    #+#             */
/*   Updated: 2024/09/30 12:46:24 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicate(int *content, t_stack *stack)
{
	t_list	*check;

	check = stack->stack;
	while (check != NULL)
	{
		if (*((int *)check->content) == *content)
		{
			free(content);
			error_exit(stack);
		}
		check = check->next;
	}
}

static void	check_int(char *nptr, t_stack *stack)
{
	int	i;
	int	res;
	int	comp;

	i = 1;
	res = 0;
	comp = -2147483647;
	if (*nptr == '-')
		comp = -2147483648;
	else
		i = 0;
	while (ft_isdigit(*(nptr + i)))
	{
		if (res < comp / 10 || (res == comp / 10 && -(*(nptr + i) - '0') < comp
				% 10))
			error_exit(stack);
		res = res * 10 - (*(nptr + i++) - '0');
	}
}

static int	stack_len(t_list *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	input(int argc, char **argv, t_stack *a_stack)
{
	int		i;
	int		*content;
	t_list	*new_node;

	i = 1;
	while (i < argc)
	{
		if (!ft_isdigit(*argv[i]) && (*argv[i] != '-' || !ft_isdigit(*(argv[i]
						+ 1))))
			error_exit(a_stack);
		check_int(argv[i], a_stack);
		content = (int *)malloc(sizeof(int));
		if (content == NULL)
			error_exit(a_stack);
		*content = ft_atoi(argv[i++]);
		check_duplicate(content, a_stack);
		new_node = ft_lstnew(content);
		ft_lstadd_back(&(a_stack->stack), new_node);
	}
	a_stack->size = stack_len(a_stack->stack);
}
