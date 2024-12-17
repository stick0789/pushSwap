/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:13:36 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/17 20:51:02 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"	

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	if (argc < 2 )
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	input_validation(argc, argv);
	stack_a = (t_list **)malloc(sizeof (t_list));
	stack_b = (t_list **)malloc(sizeof (t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	//primero pasar los datos a enteros, HEHCO con inputvalidation 
	//asignar memoria a las listas e inicializarlas a null, HECHO
	//verificar que no haya ninguno repetido HECHO
	//que los datos recibidos pasen al stack a y crear un stack b para usarlo de ser necesario
	init_stack(stack_a, argc, argv);
	//verificamos que se encuentre ordenado 
	if (is_sorted)
	{

	}
	return (0);
}
