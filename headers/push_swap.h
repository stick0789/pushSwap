/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:59:24 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/19 19:37:09 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_list
{
	int	value;
	int	index
	struct	s_list *next;
} t_list;

//Validations input
void	input_validation(int argc, char *argv[]);
//Stacks
void	init_stack(t_list **stack, int argc, char **argv);
void	free_stack(t_list **stack);
//Ordenation Algorithms 
void	easy_sort(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);
//Utils
int	is_sorted(t_list **stack);
int	get_distance(t_list **stack, int index);
//Swap Movements
int	swap(t_list **stack);
int	push(t_list **stack_to, t_list **stack_from);
int	rotate(t_list **stack);
int	reverse_rotate(t_list **stack);
int	sa(t_list **stack_a);
int	sb(t_list **stack_b);
int	ss(t_list **stack_a, t_list **stack_b);
int	pa(t_list **stack_a, t_list **stack_b);
int	pb(t_list **stack_a, t_list **stack_b);
int	ra(t_list **stack_a);
int	rb(t_list **stack_b);
int	rr(t_list **stack_a, t_list **stack_b);
int	rra(t_list **stack_a);
int	rrb(t_list **stack_b);
int	rrr(t_list **stack_a, t_list **stack_b);

#endif
