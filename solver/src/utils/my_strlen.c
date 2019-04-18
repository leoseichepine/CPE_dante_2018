/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "solver.h"

int my_strlen(char *str)
{
    int res = 0;

    if (!str)
        return (-1);
    for (; str[res]; res++);
    return (res);
}
