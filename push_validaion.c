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

}
int	input_validation(int argc, char *argv[])
{
	char	*str;

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

	}
}
