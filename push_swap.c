/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:13:36 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/09 21:28:04 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//int	

int	main(int argc, char *argv[])
{
	char	*str;
	int		i;

	i = 0;
	if (argc < 2 || !input_validation(argc, argv))
	{
		ft_putstr("Error\n", 2);
		return (1);
	}
	//if (!input_validation(argc, argv))
	//{}
	if (argc == 2)
	{
		str = argv[1];
		if (!data_validation(str))
		{
			ft_putstr("Error\n", 2);
			return (1)
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
	//primero pasar los datos a enteros
	//verificar que no haya ninguno repetido
	//que los datos recibidos pasen al stack a y crear un stack b para usarlo de ser necesario
	//
	return (0);
}
