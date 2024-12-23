#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int value;
    int index;
    struct s_list *next;
} t_list;

// Prototipos de funciones
t_list *ft_lstnew(int value, int index);
void ft_lstadd_back(t_list **lst, t_list *new);
t_list *ft_lstlast(t_list *lst);
int ft_lstsize(t_list *lst);
void print_list(t_list *lst);
int rotate_up(t_list **stack);

// Crear un nuevo nodo
t_list *ft_lstnew(int value, int index)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->index = index;
    new_node->next = NULL;
    return (new_node);
}

// Agregar un nodo al final de la lista
t_list *ft_lstlast(t_list *lst)
{
    while (lst && lst->next)
        lst = lst->next;
    return (lst);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;

    if (!lst || !new)
        return;
    if (!*lst)
        *lst = new;
    else
    {
        last = ft_lstlast(*lst);
        last->next = new;
    }
}

// Contar el tamaño de la lista
t_list *ft_lstlast(t_list *lst);
int ft_lstsize(t_list *lst)
{
    int size = 0;
    while (lst)
    {
        size++;
        lst = lst->next;
    }
    return size;
}

// Imprimir la lista
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("[Value: %d, Index: %d] -> ", lst->value, lst->index);
        lst = lst->next;
    }
    printf("NULL\n");
}

// Implementar la rotación hacia arriba
int rotate_up(t_list **stack)
{
    t_list *head;
    t_list *tail;

    if (ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
    tail = ft_lstlast(head);
    *stack = head->next;
    head->next = NULL;
    tail->next = head;
    return (0);
}

// Programa principal
int main()
{
    t_list *stack = NULL;

    // Crear lista inicial
    ft_lstadd_back(&stack, ft_lstnew(10, 0));
    ft_lstadd_back(&stack, ft_lstnew(20, 1));
    ft_lstadd_back(&stack, ft_lstnew(30, 2));
    ft_lstadd_back(&stack, ft_lstnew(40, 3));

    // Mostrar lista original
    printf("Lista original:\n");
    print_list(stack);

    // Realizar rotación hacia arriba
    if (rotate_up(&stack) == 0)
    {
        printf("\nLista después de rotación hacia arriba:\n");
        print_list(stack);
    }
    else
    {
        printf("\nNo se pudo realizar la rotación (lista demasiado corta).\n");
    }

    return 0;
}

