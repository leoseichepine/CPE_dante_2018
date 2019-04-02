/*
** EPITECH PROJECT, 2018
** generate_map.c
** File description:
** generate_map
*/

#include "include/my.h"

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

char **generate_map(int x, int y, maze_t *gen)
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
            if (i == gen->y - 1 || i == 0 || j == 0 || j == gen->x - 1)
                map[i][j] = '*';
            j++;
        }
        map[i][j] = '\0';
        j = 0;
        i++;
    }
    map[i] = NULL;
    return (map);
}
