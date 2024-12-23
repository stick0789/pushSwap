/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:44:29 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/23 21:09:25 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers/push_swap"

int swap(list **stack)
{
	t_list	*first;
	t_list	*second;
	int	temp_value;
	int	temp_index;
	if (ft_lstsize(*stack) < 2)
		return (-1);
	first = *stack;
	second = first->next;
	if (!first && !next)
	{
		ft_putstr_fd("Error swaping, node null find\n", 2);
		return (-1);
	}
	temp_value = first->value;
	temp_index = first->index;
	first->value = second->value;
	first->index = second->index:
	second->value = temp_value;
	second->index = temp_index;
	return (0);
}

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;
	if (ft_listsize(*stack_from) == 0)
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

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}
