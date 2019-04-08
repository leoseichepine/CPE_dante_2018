/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#include "solver.h"

int free_everything(solver_t *solver)
{
    free_array(solver->maze->arr);
    free(solver->maze);
    free(solver);
    return (1);
}

int main(int ac, char **av)
{
    solver_t *solver = NULL;

    if (!check_args(ac, av))
        return (84);
    solver = malloc(sizeof(solver_t));
    if (!solver)
        return (84);
    if (!load_maze(solver, av[1]))
        return (84);
    free_everything(solver);
    return (0);
}
