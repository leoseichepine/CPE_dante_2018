/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "solver.h"

int free_array(char **arr)
{
    if (!(*arr))
        return (0);
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
    return (1);
}

int print_array(char **arr)
{
    if (!(*arr))
        return (0);
    for (int i = 0; arr[i]; i++) {
        my_putstr(arr[i]);
        my_putchar('\n');
    }
    return (1);
}

char *my_strncpy(char *str, int n)
{
    char *new = NULL;
    int i = 0;

    if (n > (int)strlen(str) || !str)
        return (NULL);
    new = malloc(sizeof(char) * (n + 1));
    if (!new)
        return (NULL);
    for (; i < n; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}

int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int my_putstr(char *str)
{
    if (!str)
        return (0);
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return (1);
}
