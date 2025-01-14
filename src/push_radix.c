/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:50:19 by jaacosta          #+#    #+#             */
/*   Updated: 2025/01/08 19:18:47 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_max_bits(t_l **stack)
{
	t_l	*head;
	int	max;
	int	max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_l **stack_a, t_l **stack_b)
{
	t_l	*head_a;
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
