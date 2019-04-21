/*
** EPITECH PROJECT, 2019
** generator
** File description:
** __DESCRIPTION__
*/

#include "generator.h"

int free_gen(gen_t *gen)
{
    for (int i = 0; gen->maze[i]; i++)
        free(gen->maze[i]);
    free(gen->maze);
    free(gen);
    return (0);
}

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2) || !str1 || !str2)
        return (0);
    for (int i = 0; str1[i]; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}

int check_args(int ac, char **av)
{
    if (ac != 3 && ac != 4 && !(*av))
        return (0);
    if (!is_str_num(av[1]) || !is_str_num(av[2]))
        return (0);
    if (ac == 4 && !my_strcmp(av[3], "perfect"))
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    gen_t *gen = NULL;

    if (!check_args(ac, av))
        return (84);
    gen = init_struct(av);
    print_arr(gen->maze);
    free_gen(gen);
    return (0);
}
