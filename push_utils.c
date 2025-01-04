/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:39:09 by jaacosta          #+#    #+#             */
/*   Updated: 2025/01/03 18:39:08 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers/push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{

}
