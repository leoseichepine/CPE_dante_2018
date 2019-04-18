/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "solver.h"

int is_wall(maze_t *maze, int y, int x)
{
    if (maze->arr[y][x] == 'X')
        return (1);
    else
        return (0);
}

int is_outside(maze_t *maze, int y, int x)
{
    if (x > maze->x - 1 || y > maze->y - 1)
        return (1);
    else if (x < 0 || y < 0)
        return (1);
    else
        return (0);
}

int is_solution(maze_t *maze, int y, int x)
{
    if (x == maze->x - 1 && y == maze->y - 1)
        return (1);
    else
        return (0);
}

int is_valid_point(maze_t *maze, int y, int x, list_t **list)
{
    if (is_already_point((*list), y, x))
        return (0);
    if (is_outside(maze, y, x))
        return (0);
    if (is_wall(maze, y, x))
        return (0);
    return (1);
}

int find_path(maze_t *maze, int y, int x, list_t **list)
{
    add_point(list, y, x);
    if (is_solution(maze, y, x))
        return (1);
    if (is_valid_point(maze, y, x + 1, list)) {
        if (find_path(maze, y, x + 1, list))
            return (1);
    }
    if (is_valid_point(maze, y + 1, x, list)) {
        if (find_path(maze, y + 1, x, list))
            return (1);
    }
    if (is_valid_point(maze, y, x - 1, list)) {
        if (find_path(maze, y, x - 1, list))
            return (1);
    }
    if (is_valid_point(maze, y - 1, x, list)) {
        if (find_path(maze, y - 1, x, list))
            return (1);
    }
    delete_point(list);
    return (0);
}
