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

int print_output(maze_t *maze, int res)
{
    if (!res) {
        my_putstr("No solution\n");
        return (res);
    } else {
        print_array(maze->arr);
        return (res);
    }
}

int is_valid_maze(maze_t *maze)
{
    if (maze->arr[0][0] != '*' || maze->arr[maze->y - 1][maze->x- 1] != '*')
        return (0);
    return (1);
}

int find_path(maze_t *maze, int y, int x)
{
    if (x == maze->x - 1 && y == maze->y - 1)
        return (1);
    if (x < 0 || y < 0 || x >= maze->x || y >= maze->y)
        return (0);
    if (maze->arr[y][x] == 'X')
        return (0);
    maze->arr[y][x] = 'o';
    if (find_path(maze, y, x + 1) || find_path(maze, y + 1, x))
        return (1);
    if (find_path(maze, y, x - 1) || find_path(maze, y - 1, x))
        return (1);
    maze->arr[y][x] = '*';
    return (0);
}

int solve_maze(maze_t *maze)
{
    if (!is_valid_maze(maze))
        return (0);
    find_path(maze, 0, 0);
    return (0);
}

int main(int ac, char **av)
{
    maze_t *maze = malloc(sizeof(maze_t));

    if (!check_args(ac, av))
        return (84);
    if (!load_maze(maze, av[1]))
        return (84);
    solve_maze(maze);
    print_array(maze->arr);
    free_everything(maze, 0);
    return (0);
}
