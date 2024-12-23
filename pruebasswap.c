/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:13:58 by jaacosta          #+#    #+#             */
/*   Updated: 2024/12/23 17:14:01 by jaacosta         ###   ########.fr       */
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

// Función para realizar el swap de los dos primeros elementos
/*
void swap(t_list **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("No se puede realizar el swap, el stack tiene menos de 2 elementos.\n");
        return;
    }

    t_list *first = *stack;
    t_list *second = first->next;

    // Realizar el swap
    first->next = second->next;
    second->next = first;
    *stack = second; // Actualizar la cabeza del stack
}
*/
void swap(t_list **stack)
{
    t_list *first;
    t_list *second;
    int temp_value;
    int temp_index;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    first = *stack;
    second = first->next;

    temp_value = first->value;
    temp_index = first->index;

    first->value = second->value;
    first->index = second->index;

    second->value = temp_value;
    second->index = temp_index;
}

int main()
{
    // Crear un stack de 3 a 5 números
    t_list *stack = create_node(1, 0);
    stack->next = create_node(2, 1);
    stack->next->next = create_node(3, 2);

    // Imprimir el stack antes del swap
    printf("Stack antes del swap:\n");
    print_stack(stack);

    // Realizar el swap
    swap(&stack);

    // Imprimir el stack después del swap
    printf("\nStack después del swap:\n");
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
