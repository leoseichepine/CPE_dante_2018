/*
** EPITECH PROJECT, 2019
** generator
** File description:
** __DESCRIPTION__
*/

#include "generator.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int my_putstr(char *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return (1);
}

int print_arr(char **arr)
{
    int i = 0;

    if (!arr)
        return (0);
    for (; arr[i + 1]; i++) {
        my_putstr(arr[i]);
        my_putchar('\n');
    }
    my_putstr(arr[i]);
    return (1);
}
