/*
** EPITECH PROJECT, 2018
** imperfect_maze.c
** File description:
** imperfect
*/

#include "include/my.h"

int random_border(int nb)
{
    int random = 0;

    srand(time(NULL));
    random = rand() % nb;
    return (random);
}

void perfect_alea3(char **map, maze_t *gen, int i, int j)
{
    if (j == 0 || (i == gen->y - 1))
        map[i][j] = '*';
    else if (map[i][j] == 'X') {
        perfect_alea4(map, gen, i, j);
    }
}

void perfect_alea2(char **map, maze_t *gen, int i, int j)
{
    if (gen->count == 0) {
        if (gen->random == 1)
            map[i][j] = '*';
    }
}

void perfect_alea(char **map, maze_t *gen, int i, int j)
{
    int rand2 = 0;

    gen->random = random_number(6);
    gen->count = count_stars(map, gen, i, j);
    rand2 = random_border(4);
    if (rand2 == 1 || rand2 == 3) {
        border_perfect1(map, i, j, gen);
        if (map[i][j] == 'X')
            perfect_alea2(map, gen, i, j);
    } else
        perfect_alea3(map, gen, i, j);
}

void create_perfect(char **map, maze_t *gen)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            perfect_alea(map, gen, i, j);
        }
    }
}
