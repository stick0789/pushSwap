/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:13:36 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/04 20:30:29 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//int	

int	main(int argc, char *argv[])
{
	char	*str;
	int		i;

	i = 0;
	//str = argv[1];
	//while (argc > 1)

	if (argc < 2)
	{
		ft_putstr("Error\n", 2);
		return (1);
	}
	if (argc == 2)
	{
		str = argv[1];
		if (!data_validation(str))
			
	}
	else
	{

	}
	//primero pasar los datos a enteros
	//verificar que no haya ninguno repetido
	//que los datos recibidos pasen al stack a y crear un stack b para usarlo de ser necesario
	//
	return (0);
}
