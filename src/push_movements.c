/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:44:29 by jaacosta          #+#    #+#             */
/*   Updated: 2025/01/08 19:50:18 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	swap(t_l **stack)
{
	t_l	*first;
	t_l	*second;
	int	temp_value;
	int	temp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	first = *stack;
	second = first->next;
	if (!first && !second)
	{
		ft_putstr_fd("Error swaping, node null find\n", 2);
		return (-1);
	}
	temp_value = first->value;
	temp_index = first->index;
	first->value = second->value;
	first->index = second->index;
	second->value = temp_value;
	second->index = temp_index;
	return (0);
}

int	push(t_l **stack_to, t_l **stack_from)
{
	t_l	*tmp;
	t_l	*head_to;
	t_l	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	rotate(t_l **stack)
{
	t_l	*head;
	t_l	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	reverse_rotate(t_l **stack)
{
	t_l	*head;
	t_l	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}
