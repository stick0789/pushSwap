/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebasrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:28:23 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/23 20:28:25 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int value;
    int index;
    struct s_list *next;
} t_list;

//auxiliares lstsize y lstlast
int	ft_lstsize(t_list *lst)
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

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
/*
t_list	*ft_lstlast(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}
*/
// Función para crear un nuevo nodo
t_list *create_node(int value, int index)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
    {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->index = index;
    new_node->next = NULL;
    return new_node;
}

// Función para imprimir el stack
void print_stack(t_list *stack)
{
    t_list *current = stack;
    while (current)
    {
        printf("Value: %d, Index: %d\n", current->value, current->index);
        current = current->next;
    }
}

// Función para desplazar hacia arriba todos los elementos del stack
/*
int	rotate_up(t_list **stack)//version optima
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}*/
void rotate_up(t_list *stack)//version GPT
{
    if (stack == NULL || stack->next == NULL)
    {
        // No hay nada que rotar
        return;
    }

    int first_value = stack->value; // Guardar el valor del primer nodo
    t_list *current = stack;

    // Desplazar los valores
    while (current->next)
    {
        current->value = current->next->value; // Mover el valor del siguiente nodo al actual
        current = current->next;
    }

    // Colocar el valor del primer nodo en la última posición
    current->value = first_value;
}

int main()
{
    // Crear un stack con algunos nodos
    t_list *stack = create_node(1, 0);
    stack->next = create_node(2, 1);
    stack->next->next = create_node(3, 2);
    stack->next->next->next = create_node(4, 3);

    // Imprimir el stack antes de la rotación
    printf("Stack antes de la rotación:\n");
    print_stack(stack);

    // Desplazar hacia arriba
    rotate_up(stack);//Para version GPT    
    //rotate_up(&stack);//Para version Optima

    // Imprimir el stack después de la rotación
    printf("\nStack después de la rotación:\n");
    print_stack(stack);

    // Liberar la memoria
    t_list *current = stack;
    t_list *next_node;
    while (current)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}
