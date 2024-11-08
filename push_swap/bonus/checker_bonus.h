/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:51:19 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/08 15:38:42 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"
# include <stdlib.h> // exit(), EXIT_*
# include <unistd.h> // write()

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef ERROR_MESS
#  define ERROR_MESS "Error\n"
# endif

typedef enum e_status
{
	STATUS_ERROR = -1,
	STATUS_SUCCESS = 0,
}			t_status;

typedef enum e_bool
{
	FALSE,
	TRUE,
}			t_bool;

typedef struct s_stack
{
	char	name;
	t_list	*stack;
	int		size;
	int		min_index;
	int		max_index;
}			t_stack;

typedef struct s_move
{
	int		position;
	int		order;
	int		steps;
}			t_move;

typedef struct s_data
{
	int		num;
	int		index;
}			t_data;

// Input
t_status	check_input(int argc, char **argv);
void		load_input(int argc, char **argv, t_stack *stack);

// Read
void		read_instructions(t_stack *stack_a, t_stack *stack_b);

// Utils
void		exit_message(t_status status, char *message);
void		del_content(void *data);

// Rules
void		ps_swap(t_stack *stack);
void		ps_push(t_stack *from, t_stack *to);
void		ps_rotate(t_stack *stack);
void		ps_rev_rotate(t_stack *stack);
void		ps_swap_all(t_stack *stack_a, t_stack *stack_b);
void		ps_rotate_all(t_stack *stack_a, t_stack *stack_b);
void		ps_rev_rotate_all(t_stack *stack_a, t_stack *stack_b);

#endif // CHECKER_BONUS_H
