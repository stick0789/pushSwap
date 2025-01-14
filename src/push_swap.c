/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:13:36 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/19 19:46:01 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"	

static void	sort(t_l **stack_a, t_l **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		easy_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_l	**stack_a;
	t_l	**stack_b;

	if (argc < 2)
		return (1);
	if (input_validation(argc, argv) == 1)
	{
		stack_a = (t_l **)malloc(sizeof (t_l));
		stack_b = (t_l **)malloc(sizeof (t_l));
		*stack_a = NULL;
		*stack_b = NULL;
		init_stack(stack_a, argc, argv);
		if (is_sorted(stack_a))
		{
			free_stack(stack_a);
			free_stack(stack_b);
			return (0);
		}
		sort(stack_a, stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
