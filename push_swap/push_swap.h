/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovak <dnovak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:51:19 by dnovak            #+#    #+#             */
/*   Updated: 2024/11/12 02:09:23 by dnovak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
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
t_status	load_input(int argc, char **argv, t_stack *stack);

// Sort
void		sort(t_stack *stack_a, t_stack *stack_b);
void		sort_low_rank(t_stack *stack_a, t_stack *stack_b);
void		move_to_positions(int ra, int rb, t_stack *stack_a,
				t_stack *stack_b);
void		rotate_to_top(t_stack *stack, int target);

// Utils
void		exit_message(t_status status, char *message);
void		print_stack(t_stack *stack);
void		update_border_indicies(t_stack *update, t_list *values);
void		setup_border_indicies(t_stack *update);
int			find_index(t_stack *stack, int target);

// Clean
void		del_content(void *data);

// Sort algorithms
void		insertion_sort(t_stack *stack_a, t_stack *stack_b);
void		group_sort(t_stack *stack_a, t_stack *stack_b);
void		push_back_groups(t_stack *stack_a, t_stack *stack_b);

// Rules
void		ps_swap(t_stack *stack);
void		ps_push(t_stack *from, t_stack *to);
void		ps_rotate(t_stack *stack);
void		ps_rev_rotate(t_stack *stack);
void		ps_swap_all(t_stack *stack_a, t_stack *stack_b);
void		ps_rotate_all(t_stack *stack_a, t_stack *stack_b);
void		ps_rev_rotate_all(t_stack *stack_a, t_stack *stack_b);

#endif // PUSH_SWAP_H
