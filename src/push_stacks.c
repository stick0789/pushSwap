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

static t_l	*find_min_val(t_l **stack)
{
	t_l	*head;
	t_l	*min_val;
	int	f_min;

	head = *stack;
	min_val = NULL;
	f_min = 0;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!f_min || head->value < min_val->value))
			{
				min_val = head;
				f_min = 1;
			}
			head = head->next;
		}
	}
	return (min_val);
}

static void	set_index(t_l **stack)
{
	t_l	*head;
	int	index;

	index = 0;
	head = find_min_val(stack);
	while (head)
	{
		head->index = index++;
		head = find_min_val(stack);
	}
}

void	init_stack(t_l **stack, int argc, char **argv)
{
	char	**args;
	t_l		*new;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	set_index(stack);
	if (argc == 2)
		free_split(args);
}
