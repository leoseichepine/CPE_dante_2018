/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "solver.h"

int get_y_file(char *path)
{
    int res = 0;
    char *s = NULL;
    size_t len = 0;
    FILE *stream = fopen(path, "r");

    if (!stream)
        return (-1);
    for (; getline(&s, &len, stream) > 0; res++);
    free(s);
    fclose(stream);
    return (res);
}

int get_x_file(char *path)
{
    int res = 0;
    char *s = NULL;
    size_t len = 0;
    FILE *stream = fopen(path, "r");

    if (!stream)
        return (-1);
    if (getline(&s, &len, stream) < 0)
        return (-1);
    for (int i = 0; s[i] != '\n'; i++, res++);
    free(s);
    fclose(stream);
    return (res);
}

int get_coord_maze(maze_t *maze, char *path)
{
    maze->y = get_y_file(path);
    if (maze->y <= 1)
        return (0);
    maze->x = get_x_file(path);
    if (maze->x <= 1)
        return (0);
    return (1);
}

int copy_maze(maze_t *maze, char *path)
{
    FILE *stream = fopen(path, "r");
    char *s = NULL;
    size_t len = 0;
    int i = 0;

    if (!stream)
        return (0);
    while (getline(&s, &len, stream) > 0) {
        maze->arr[i] = my_strncpy(s, maze->x);
        if (!maze->arr[i]) {
            free(s);
            fclose(stream);
            return (0);
        }
        i++;
    }
    maze->arr[i] = NULL;
    free(s);
    fclose(stream);
    return (1);
}

int load_maze(maze_t *maze, char *path)
{
    if (!get_coord_maze(maze, path))
        return (0);
    maze->arr = malloc(sizeof(char *) * (maze->y + 1));
    if (!maze->arr)
        return (0);
    if (!copy_maze(maze, path))
        return (0);
    if (!check_error_maze(maze->arr))
        return (free_everything(maze, 0));
    return (1);
}
