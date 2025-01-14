/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:15:44 by jaacosta          #+#    #+#             */
/*   Updated: 2025/01/08 19:43:36 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	rra(t_l **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_l **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_l **stack_a, t_l **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	rra(stack_a);
	rrb(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}

void	s3_util(t_l **stack_a, int min, int next_min)
{
	t_l	*head;

	head = *stack_a;
	if (head->index == min && head->next->index != next_min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
		return ;
	}
	if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
		return ;
	}
	if (head->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	free_stack(t_l **stack)
{
	t_l	*head;
	t_l	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
