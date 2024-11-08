/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:43:38 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/08 10:48:26 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ft_isnumber(char *nptr)
{
	int	i;

	i = 0;
	if (*nptr == '-' || *nptr == '+')
		i++;
	while (*(nptr + i) != '\0')
	{
		if (ft_isdigit(*(nptr + i)) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	ft_isinteger(char *nptr)
{
	int	i;
	int	res;
	int	last_digit;

	i = 0;
	last_digit = INT_MAX % 10;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			last_digit = -(INT_MIN % 10);
		i++;
	}
	res = 0;
	while (*(nptr + i) != '\0')
	{
		if (res > INT_MAX / 10)
			return (FALSE);
		if (res == INT_MAX / 10 && (*(nptr + i) - '0') > last_digit)
			return (FALSE);
		res = res * 10 + (*(nptr + i) - '0');
		i++;
	}
	return (TRUE);
}

t_status	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_isnumber(argv[i]) == FALSE)
			return (STATUS_ERROR);
		if (ft_isinteger(argv[i]) == FALSE)
			return (STATUS_ERROR);
		i++;
	}
	return (STATUS_SUCCESS);
}

static t_status	check_duplicate(t_data *data, t_stack *stack)
{
	t_list	*check;

	check = stack->stack;
	while (check != NULL)
	{
		if (data->num == ((t_data *)check->content)->num)
			return (STATUS_ERROR);
		else if (data->num > ((t_data *)check->content)->num)
			data->index += 1;
		else
			((t_data *)check->content)->index += 1;
		check = check->next;
	}
	return (STATUS_SUCCESS);
}

void	load_input(int argc, char **argv, t_stack *stack)
{
	int		i;
	t_data	*content;
	t_list	*new_node;

	i = 1;
	while (i < argc)
	{
		content = (t_data *)malloc(sizeof(t_data));
		if (content == NULL)
		{
			ft_lstclear(&(stack->stack), &del_content);
			exit_message(STATUS_ERROR, ERROR_MESS);
		}
		content->num = ft_atoi(argv[i++]);
		content->index = 0;
		if (check_duplicate(content, stack) == STATUS_ERROR)
		{
			free(content);
			ft_lstclear(&(stack->stack), &del_content);
			exit_message(STATUS_ERROR, ERROR_MESS);
		}
		new_node = ft_lstnew(content);
		ft_lstadd_back(&(stack->stack), new_node);
	}
	stack->size = ft_lstsize(stack->stack);
}
