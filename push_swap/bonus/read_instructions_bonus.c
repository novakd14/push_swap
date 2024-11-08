/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:45:43 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/08 15:30:59 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	read_push(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(line, "pa\n", 4) == 0)
		ps_push(stack_b, stack_a);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		ps_push(stack_a, stack_b);
	else
	{
		ft_lstclear(&(stack_a->stack), del_content);
		ft_lstclear(&(stack_b->stack), del_content);
		while (line != NULL)
		{
			free(line);
			line = get_next_line(STDIN_FILENO);
		}
		exit_message(STATUS_ERROR, ERROR_MESS);
	}
}

static void	read_swap(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		ps_swap(stack_a);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		ps_swap(stack_b);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		ps_swap_all(stack_a, stack_b);
	else
	{
		ft_lstclear(&(stack_a->stack), del_content);
		ft_lstclear(&(stack_b->stack), del_content);
		while (line != NULL)
		{
			free(line);
			line = get_next_line(STDIN_FILENO);
		}
		exit_message(STATUS_ERROR, ERROR_MESS);
	}
}

static void	read_rotate(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(line, "ra\n", 4) == 0)
		ps_rotate(stack_a);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		ps_rotate(stack_b);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		ps_rotate_all(stack_a, stack_b);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		ps_rev_rotate(stack_a);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		ps_rev_rotate(stack_b);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		ps_rev_rotate_all(stack_a, stack_b);
	else
	{
		ft_lstclear(&(stack_a->stack), del_content);
		ft_lstclear(&(stack_b->stack), del_content);
		while (line != NULL)
		{
			free(line);
			line = get_next_line(STDIN_FILENO);
		}
		exit_message(STATUS_ERROR, ERROR_MESS);
	}
}

void	read_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (*line == 'p')
			read_push(line, stack_a, stack_b);
		else if (*line == 's')
			read_swap(line, stack_a, stack_b);
		else if (*line == 'r')
			read_rotate(line, stack_a, stack_b);
		else
		{
			ft_lstclear(&(stack_a->stack), del_content);
			ft_lstclear(&(stack_b->stack), del_content);
			while (line != NULL)
			{
				free(line);
				line = get_next_line(STDIN_FILENO);
			}
			exit_message(STATUS_ERROR, ERROR_MESS);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}
