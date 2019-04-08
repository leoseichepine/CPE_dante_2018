/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "solver.h"

int is_valid_line(char *line)
{
    for (int i = 0; line[i]; i++)
        if (line[i] != 'X' && line[i] != '*')
            return (0);
    return (1);
}

int check_error_maze(char **maze)
{
    for (int i = 0; maze[i]; i++)
        if (!is_valid_line(maze[i]))
            return (0);
    return (1);
}
