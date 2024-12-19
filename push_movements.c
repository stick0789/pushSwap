/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:44:29 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/19 21:12:24 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers/push_swap"

void	swap_a(t_list **stack_a)
{
	t_list *first;
	t_list *second;

	if (stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = first->next;	
	firs->next = second->next;
	second->next = first;
	stack_a = second
}

void	swap_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_a = second
}

void swap_first_two_values(t_list **stack)
{
    t_list *first;
    t_list *second;
    int temp_value;
    int temp_index;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    first = *stack;
    second = first->next;

    temp_value = first->value;
    temp_index = first->index;

    first->value = second->value;
    first->index = second->index;

    second->value = temp_value;
    second->index = temp_index;
}


void	double_swap(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{

}

void	push_b(t_list **stack_a, t_list **stack_b)
{

}
