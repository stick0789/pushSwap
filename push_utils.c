/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:39:09 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/04 18:17:05 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_putstr(char *s, int out)
{
	if (!s)
		return ((void) NULL);
	while (*s)
	{
		if (write(out, s++, 1) != -1)
			write(out, s++, 1);
	}		

}

int	ft_isdigit(int c);
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int	data_validation(char *str)
{
	while (*str)
	{
		if (*str != ' ' && !ft_isdigit(str))
			return (0);
		str++;
	}
	return (1);
}
