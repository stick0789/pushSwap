/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:35:20 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/17 20:51:04 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_list	*find_min_val(t_list **stack)
{
	t_list	*head;
	t_list	*min_val;
	int	f_min;

	head = stack;
	min_val = NULL;
	f_min = 0;
	if (head)
	{
		while (head)
		{
			//busca por los valores que no se encuentren
			// indexados (-1), y cuando f_min valga 0 y el
			//  valor del num en la lista head sea menor
			//  que el valor de la lista min_val
			if ((head->inndex == -1) && (!f_min || head->value < min_val->value))
			{
				min_val = head;
				f_min = 1;
			}
			head = head->next;
		}
	}
	return (min_val)
}

static void	set_index(t_list **stack)
{
	t_list	*head;
	int	index;

	index = 0;
	//aqui encontramos el valor mas pequeno que se encuentre en el stack
	head = find_min_val(stack);
	while (head)
	{
		//aqui usamos la lista 'head' y vamos aumentando el indice de 0 a n 
		//mientras vamos iterando sobre los valores encontrando el mas pequeno cada vez
		//y asignandole un indice para cada valor
		head->index = index++;
		head = find_min_val(stack);
	}
}

void	init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	*args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	setIndex(stack);
	if (argc == 2)
		free_split(args);
}
