/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebaspush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:38:35 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/23 17:38:36 by jaacosta         ###   ########.fr       */
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

// Función para realizar el push del primer elemento de stack b a stack a

int	push_a(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	//if (ft_lstsize(*stack_from) == 0)
	//	return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}/*
void push_a(t_list **stack_a, t_list **stack_b)
{
    if (*stack_b == NULL)
    {
        printf("Stack b está vacío. No se puede realizar el push.\n");
        return;
    }

    t_list *node_to_push = *stack_b; // Tomar el primer nodo de stack b
    *stack_b = (*stack_b)->next;      // Mover el puntero de stack b al siguiente nodo

    // Insertar el nodo en la parte superior de stack a
    node_to_push->next = *stack_a;    // Hacer que el siguiente del nodo sea el actual primer nodo de stack a
    *stack_a = node_to_push;          // Actualizar stack a para que apunte al nuevo primer nodo
}
*/
int main()
{
    // Crear stack a y b
    t_list *stack_a = NULL;
    t_list *stack_b = create_node(1, 0);
    stack_b->next = create_node(2, 1);
    stack_b->next->next = create_node(3, 2);

    // Imprimir stack b antes del push
    printf("Stack b antes del push:\n");
    print_stack(stack_b);

    // Realizar el push de b a a
    push_a(&stack_a, &stack_b);

    // Imprimir ambos stacks después del push
    printf("\nStack a después del push:\n");
    print_stack(stack_a);
    printf("\nStack b después del push:\n");
    print_stack(stack_b);

    // Liberar la memoria
    t_list *current = stack_a;
    t_list *next_node;
    while (current)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    current = stack_b;
    while (current)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}

