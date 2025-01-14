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
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_l
{
	int			value;
	int			index;
	struct s_l	*next;
}	t_l;

//Validations input
int		input_validation(int argc, char *argv[]);
//Stacks
void	init_stack(t_l **stack, int argc, char **argv);
void	free_stack(t_l **stack);
//Ordenation Algorithms 
void	easy_sort(t_l **stack_a, t_l **stack_b);
void	radix_sort(t_l **stack_a, t_l **stack_b);
//Utils
int		is_sorted(t_l **stack);
int		get_distance(t_l **stack, int index);
void	s3_util(t_l **stack_a, int min, int next_min);
//List
int		ft_lstsize(t_l *lst);
t_l		*ft_lstlast(t_l *lst);
t_l		*ft_lstnew(int value);
void	ft_lstadd_front(t_l **lst, t_l *new);
void	ft_lstadd_back(t_l **lst, t_l *new);
//Swap Movements
int		swap(t_l **stack);
int		push(t_l **stack_to, t_l **stack_from);
int		rotate(t_l **stack);
int		reverse_rotate(t_l **stack);
int		sa(t_l **stack_a);
int		sb(t_l **stack_b);
int		ss(t_l **stack_a, t_l **stack_b);
int		pa(t_l **stack_a, t_l **stack_b);
int		pb(t_l **stack_a, t_l **stack_b);
int		ra(t_l **stack_a);
int		rb(t_l **stack_b);
int		rr(t_l **stack_a, t_l **stack_b);
int		rra(t_l **stack_a);
int		rrb(t_l **stack_b);
int		rrr(t_l **stack_a, t_l **stack_b);

#endif
