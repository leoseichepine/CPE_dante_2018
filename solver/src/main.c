/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "solver.h"

int free_everything(maze_t *maze, int ret)
{
    free_array(maze->arr);
    free(maze);
    return (ret);
}

char choose_carac(list_t *list, char **maze, int y, int x)
{
    if (is_already_point(list, y, x))
        return ('o');
    else
        return (maze[y][x]);
}

int print_solved_maze(list_t *list, maze_t *maze)
{
    for (int y = 0; maze->arr[y]; y++) {
        for (int x = 0; maze->arr[y][x]; x++) {
            putchar(choose_carac(list, maze->arr, y, x));
        }
        if (y < maze->y - 1)
            putchar('\n');
    }
    return (1);
}

int solve_maze(maze_t *maze)
{
    list_t *list = NULL;
    int ret = 0;

    if (!is_valid_maze(maze))
        return (0);
    ret = find_path(maze, 0, 0, &list);
    if (!ret) {
        printf("No solution\n");
        free_list(list);
        return (0);
    }
    print_solved_maze(list, maze);
    free_list(list);
    return (0);
}

int main(int ac, char **av)
{
    maze_t *maze = NULL;

    if (!check_args(ac, av))
        return (84);
    maze = malloc(sizeof(maze_t));
    if (!maze)
        return (84);
    if (!load_maze(maze, av[1]))
        return (84);
    solve_maze(maze);
    free_everything(maze, 0);
    return (0);
}
