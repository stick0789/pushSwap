/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_easy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:37:32 by jaacosta          #+#    #+#             */
/*   Updated: 2025/01/04 20:05:38 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers/push_swap.h"

static int	get_min_val(t_list **stack, int val)
{
	t_list	*head;
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

void	sort_3(t_list	**stack_a)
{
	t_list	*head;
	int	min;
	int	next_min;

	head = *stack;
	min = get_min_val(stack_a, -1);
	next_min = get_min_val(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (*stack == NULL || (*head)->next == NULL)
		return ;

}
void	easy_sort(t_list **stack_a, t_list **stack_b)
{

}
