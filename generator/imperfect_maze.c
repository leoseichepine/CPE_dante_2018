/*
** EPITECH PROJECT, 2018
** imperfect_maze.c
** File description:
** imperfect
*/

#include "include/my.h"

int init_imperfect(char *x, char *y, maze_t *gen)
{
    char **map;

    if (my_str_isnum(x) == 0 && my_str_isnum(y) == 0) {
        printf("%s\n", "error: we don't have numbers");
        return (84);
    } else {
        gen->x = atoi(x);
        gen->y = atoi(y);
    }
    map = generate_map(gen->x, gen->y, gen);
    create_imperfect(map, gen);
    display_map(map);
}

int random_number(int nb)
{
    int random = 0;

    srand(clock());
    random = rand() % nb;
    return (random);
}

int count_stars(char **map, maze_t *gen, int i, int j)
{
    int count = 0;

    if (i - 1 >= 0 && map[i - 1][j] == '*')
        count++;
    if (i + 1 < gen->y && map[i + 1][j] == '*')
        count++;
    if (j - 1 >= 0 && map[i][j - 1] == '*')
        count++;
    if (j + 1 < gen->x && map[i][j + 1] == '*')
        count++;
    return (count);
}

void print_alea(char **map, maze_t *gen, int i, int j)
{
    int random = random_number(6);
    int count = count_stars(map, gen, i, j);

    if (count > 0) {
        if (random == 1 || random == 3 || random == 4)
            map[i][j] = '*';
    }
}

void create_imperfect(char **map, maze_t *gen)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'X')
                print_alea(map, gen, i, j);
        }
    }
}
