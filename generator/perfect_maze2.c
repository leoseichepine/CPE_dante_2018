/*
** EPITECH PROJECT, 2018
** perfect_maze2.c
** File description:
** perfect maze
*/

#include "include/my.h"

void perfect_alea4(char **map, maze_t *gen, int i, int j)
{
    if (gen->count == 0)
        if (gen->random == 1)
            map[i][j] = '*';
}

void border_perfect1(char **map, int i, int j, maze_t *gen)
{
    if (i == 0 || (j == gen->x - 1))
        map[i][j] = '*';
}
