/*
** EPITECH PROJECT, 2019
** generator
** File description:
** __DESCRIPTION__
*/

#include "generator.h"

int my_strlen(char *str)
{
    int res = 0;

    if (!str)
        return (-1);
    for (; str[res]; res++);
    return (res);
}

int random_number(int nb)
{
    int random = 1;

    srand(clock());
    random = rand() % nb;
    while (random <= 1)
        random = rand() % nb;
    return (random);
}

int my_atoi(char *str)
{
    int res = 0;
    int i = 0;
    int sign = 1;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i] && str[i] != '\n'; i++)
        res = res * 10 + (str[i] - '0');
    return (res * sign);
}

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int is_str_num(char *str)
{
    for (int i = 0; str[i] && str[i] != '\n'; i++)
        if (!is_num(str[i]))
            return (0);
    return (1);
}
