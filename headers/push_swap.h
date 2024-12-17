/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:59:24 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/17 20:34:01 by jaacosta         ###   ########.fr       */
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

void	input_validation(int argc, char *argv[]);
void	init_stack(t_list **stack, int argc, char **argv);
/*void	ft_putstr(char *s, int out);
int	data_validation(char *str);
*/
#endif
