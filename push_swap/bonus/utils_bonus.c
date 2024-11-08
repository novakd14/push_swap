/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:41:57 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/08 15:38:14 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	exit_message(t_status status, char *message)
{
	if (status == STATUS_SUCCESS)
	{
		write(STDOUT_FILENO, message, ft_strlen(message));
		exit(EXIT_SUCCESS);
	}
	else
	{
		write(STDERR_FILENO, message, ft_strlen(message));
		exit(EXIT_FAILURE);
	}
}

void	del_content(void *data)
{
	if (data != NULL)
		free(data);
}
