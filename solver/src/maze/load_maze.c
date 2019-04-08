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

int is_valid_line(char *line)
{
    for (int i = 0; line[i]; i++)
        if (line[i] != 'X' && line[i] != '*')
            return (0);
    return (1);
}

int check_error_maze(char **maze)
{
    for (int i = 0; maze[i]; i++)
        if (!is_valid_line(maze[i]))
            return (0);
    return (1);
}

int load_maze(solver_t *solver, char *path)
{
    solver->maze = malloc(sizeof(maze_t));
    if (!solver->maze || !get_coord_maze(solver->maze, path))
        return (0);
    solver->maze->arr = malloc(sizeof(char *) * (solver->maze->y + 1));
    if (!solver->maze->arr)
        return (0);
    if (!copy_maze(solver->maze, path))
        return (0);
    if (!check_error_maze(solver->maze->arr)) {
        free_everything(solver);
        return (0);
    }
    return (1);
}
