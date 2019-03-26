/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "include/my.h"

void free_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}

int init_perfect(char *x, char *y, maze_t *gen)
{
    char **map;

    gen->x = atoi(x);
    gen->y = atoi(y);
    map = generate_perfect(gen->x, gen->y, gen);
    create_perfect(map, gen);
    display_map(map);
    free_map(map);
}

char **generate_map(int x, int y, maze_t *gen)
{
    int i = 0;
    int j = 0;
    char **map = malloc(sizeof(char *) * (y + 1));

    while (i < gen->y) {
        map[i] = malloc(sizeof(char) * (x + 1));
        while (j < gen->x) {
            map[i][j] = 'X';
            if (i == gen->y - 1 || i == 0 || j == gen-> x - 1)
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

void display_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        printf("%s\n", map[i]);
}

int main(int argc, char **argv)
{
    maze_t *gen = malloc(sizeof(maze_t));

    if (argc < 3)
        return (84);
    if (argc == 3)
        init_imperfect(argv[1], argv[2], gen);
    if (argc == 4 && (my_strcmp(argv[3], "perfect") == 0))
        init_perfect(argv[1], argv[2], gen);
    return (0);
}
