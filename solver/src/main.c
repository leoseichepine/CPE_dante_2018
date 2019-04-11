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

int print_solved_maze(list_t *list, char **maze)
{
    for (int j = 0; maze[j]; j++) {
        for (int i = 0; maze[j][i]; i++) {
            if (is_already_point(list, j, i))
                putchar('o');
            else
                putchar(maze[j][i]);
        }
        putchar('\n');
    }
    return (1);
}

int is_valid_maze(maze_t *maze)
{
    if (maze->arr[0][0] != '*' || maze->arr[maze->y - 1][maze->x- 1] != '*')
        return (0);
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
    print_solved_maze(list, maze->arr);
    free_list(list);
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
    free_everything(maze, 0);
    return (0);
}
