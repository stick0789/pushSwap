/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_easy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:37:32 by jaacosta          #+#    #+#             */
/*   Updated: 2025/01/08 19:19:33 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_min_val(t_l **stack, int val)
{
	t_l	*head;
	int	min_val;

	head = *stack;
	min_val = head->index;
	while (head->next)
	{
		head = head->next;
		if (head->index < min_val && head->index != val)
			min_val = head->index;
	}
	return (min_val);
}

static void	sort_3(t_l **stack_a)
{
	int	min;
	int	next_min;

	min = get_min_val(stack_a, -1);
	next_min = get_min_val(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	s3_util(stack_a, min, next_min);
}

static void	sort_4(t_l **stack_a, t_l **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min_val(stack_a, -1));
	if (is_sorted(stack_a))
		return ;
	if (distance == 1)
		ra(stack_a);
	if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_5(t_l **stack_a, t_l **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min_val(stack_a, -1));
	if (is_sorted(stack_a))
		return ;
	if (distance == 1)
		ra(stack_a);
	if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	easy_sort(t_l **stack_a, t_l **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_lstsize(*stack_a) == 0 \
				|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	if (size == 3)
		sort_3(stack_a);
	if (size == 4)
		sort_4(stack_a, stack_b);
	if (size == 5)
		sort_5(stack_a, stack_b);
}
