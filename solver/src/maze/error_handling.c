/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "solver.h"

int is_valid_char(char *line)
{
    for (int i = 0; line[i]; i++)
        if (line[i] != 'X' && line[i] != '*' && line[i])
            return (0);
    return (1);
}

int check_char(char **arr)
{
    for (int i = 0; arr[i]; i++)
        if (!is_valid_char(arr[i]))
            return (0);
    return (1);
}

int is_valid_maze(maze_t *maze)
{
    if (!check_char(maze->arr))
        return (0);
    if (maze->arr[0][0] != '*' || maze->arr[maze->y - 1][maze->x- 1] != '*')
        return (0);
    return (1);
}

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
