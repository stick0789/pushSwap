/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:31:55 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/19 19:45:49 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers/push_swap.h"
void	easy_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (is_sorted(stack_a) || size <2)
		return ;
	if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		sort_3val(stack_a);
	else if (size == 4)
		sort_4val(stack_a);
	else if (size == 5)
		sort_5val(stack_a);
}
