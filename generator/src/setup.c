/*
** EPITECH PROJECT, 2019
** generator
** File description:
** __DESCRIPTION__
*/

#include "generator.h"

int add_random(char *line, gen_t *gen)
{
    int random = 1;

    if (!gen->perfect)
        random = random_number(gen->cols);
    for (int i = 0; line[i]; i++)
        if (line[i] != 'X')
            return (0);
    for (int i = 0; i < random; i++)
        line[random_number(gen->cols)] = '*';
    return (1);
}

char *create_line(int index, gen_t *gen)
{
    char *line = malloc(sizeof(char) * (gen->cols + 1));
    int i = 0;

    if (!line)
        return (NULL);
    for (; i < gen->cols; i++) {
        if (index % 2 == 0)
            line[i] = '*';
        else
            line[i] = 'X';
    }
    line[i] = '\0';
    add_random(line, gen);
    return (line);
}

char **load_maze(gen_t *gen)
{
    char **maze = malloc(sizeof(char *) * (gen->rows + 1));
    int i = 0;

    if (!maze)
        return (NULL);
    for (; i < gen->rows; i++) {
        maze[i] = create_line(i, gen);
        if (!maze[i])
            return (NULL);
    }
    maze[i] = NULL;
    maze[gen->rows - 1][gen->cols - 1] = '*';
    return (maze);
}

char **create_maze(gen_t *gen)
{
    char **maze = load_maze(gen);

    if (!maze)
        return (NULL);
    return (maze);
}

gen_t *init_struct(char **av)
{
    gen_t *gen = malloc(sizeof(gen_t));

    if (!gen)
        return (NULL);
    if (my_strcmp(av[3], "perfect"))
        gen->perfect = 1;
    else
        gen->perfect = 0;
    gen->cols = my_atoi(av[1]);
    if (gen->cols <= 0)
        return (NULL);
    gen->rows = my_atoi(av[2]);
    if (gen->cols <= 0)
        return (NULL);
    gen->maze = create_maze(gen);
    if (!gen->maze)
        return (NULL);
    return (gen);
}
