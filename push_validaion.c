/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_validaion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:24:30 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/09 20:38:22 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	data_validation(char *str)
{
	while (*str)
	{
		if (*str != ' ' && !ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
int	input_validation(int argc, char *argv[])
{
	char	*str;
	int			i;

	if (argc == 2)
	{
		str = argv[1];
		if (!data_validation(str))
		{
			ft_putstr("Error\n", 2);
			return (0);
		}
	}
	else
	{
		i =  1;
		while (i < argc)
		{
			if (!data_validation(str))
			{
				ft_putstr("Error\n", 2);
				return (1);
			}	
			i++;
		}
	}
}
