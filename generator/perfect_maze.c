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

void perfect_alea2(char **map, maze_t *gen, int i, int j)
{
    if (j == 0 || (i == gen->y - 1))
        map[i][j] = '*';
    else if (map[i][j] == 'X') {
        if (gen->count > 0)
            if (gen->random == 1 || gen->random == 3 || gen->random == 4)
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
        if (i == 0 || (j == gen->x - 1))
            map[i][j] = '*';
        else if (map[i][j] == 'X') {
            if (gen->count > 0) {
                if (gen->random == 1 || gen->random == 3 || gen->random == 4)
                    map[i][j] = '*';
            }
        }
    } else
        perfect_alea2(map, gen, i, j);
}

void create_perfect(char **map, maze_t *gen)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            perfect_alea(map, gen, i, j);
        }
    }
}

char **generate_perfect(int x, int y, maze_t *gen)
{
    int i = 0;
    int j = 0;
    char **map = malloc(sizeof(char *) * (y + 1));

    if (map == NULL)
        return (NULL);
    while (i < gen->y) {
        map[i] = malloc(sizeof(char) * (x + 1));
        while (j < gen->x) {
            map[i][j] = 'X';
            j++;
        }
        map[i][j] = '\0';
        j = 0;
        i++;
    }
    map[i] = NULL;
    return (map);
}
