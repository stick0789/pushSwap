/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:34:50 by jaacosta          #+#    #+#             */
/*   Updated: 2025/01/10 17:34:51 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_lstsize(t_l *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_l	*ft_lstlast(t_l *lst)
{
	t_l	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

t_l	*ft_lstnew(int value)
{
	t_l	*new_node;

	new_node = (t_l *)malloc(sizeof(t_l));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_l **lst, t_l *new)
{
	if (lst)
	{
		if (lst)
			new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_l **lst, t_l *new)
{
	t_l	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
			new->next = NULL;
		}
		else
		{
			*lst = new;
			new->next = NULL;
		}
	}
}
