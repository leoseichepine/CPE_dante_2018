/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "solver.h"

int check_open(char *path)
{
    int fd = 0;

    fd = open(path, O_RDONLY);
    if (fd < 0) {
        close(fd);
        return (0);
    }
    close(fd);
    return (1);
}

int check_args(int ac, char **av)
{
    if (ac != 2 || *av == NULL)
        return (0);
    if (!check_open(av[1]))
        return (0);
    return (1);
}
