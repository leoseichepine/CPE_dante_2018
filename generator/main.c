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

    if (my_str_isnum(x) == 0 && my_str_isnum(y) == 0) {
        printf("%s\n", "error: we don't have numbers");
        return (84);
    } else {
        gen->x = atoi(x);
        gen->y = atoi(y);
    }
    map = generate_perfect(gen->x, gen->y, gen);
    create_perfect(map, gen);
    display_map(map);
    free_map(map);
}

void display_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        write(1, map[i], strlen(map[i]));
        write(1, "\n", 1);
    }
}

int main(int argc, char **argv)
{
    maze_t *gen = malloc(sizeof(maze_t));

    if (argc < 3)
        return (84);
    if (argc == 3)
        init_imperfect(argv[1], argv[2], gen);
    if (argc == 4 && (strcmp(argv[3], "perfect") == 0))
        init_perfect(argv[1], argv[2], gen);
    return (0);
}
