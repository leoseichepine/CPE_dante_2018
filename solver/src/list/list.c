/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "solver.h"

int is_already_point(list_t *list, int y, int x)
{
    list_t *tmp = list;

    while (tmp != NULL) {
        if (tmp->x == x && tmp->y == y)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int print_list(list_t *list)
{
    list_t *tmp = list;

    while (tmp != NULL) {
        printf("x = %i, y = %i\n", tmp->x, tmp->y);
        tmp = tmp->next;
    }
    return (0);
}

int add_point(list_t **head, int y, int x)
{
    list_t *new_node = malloc(sizeof(list_t));

    if (new_node == NULL)
        return (0);
    new_node->y = y;
    new_node->x = x;
    new_node->next = *head;
    *head = new_node;
    return (1);
}

int delete_point(list_t **list)
{
    list_t *tmp = (*list);

    (*list) = (*list)->next;
    free(tmp);
    return (0);
}

int free_list(list_t *list)
{
    list_t *tmp = list;

    while (list->next != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
    free(list);
    return (0);
}
