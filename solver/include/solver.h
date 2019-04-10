/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** __DESCRIPTION__
*/

#ifndef _SOLVER_H_
#define _SOLVER_H_

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_maze
{
    int y;
    int x;
    char **arr;
} maze_t;

typedef struct s_list
{
    int y;
    int x;
} list_t;

typedef struct s_solver
{
    int **arr;
    list_t *path;
} solver_t;

int check_open(char *path);
int is_valid_line(char *line);
int free_everything(maze_t *maze, int ret);
int check_error_maze(char **maze);
int print_array(char **arr);
int free_array(char **arr);
int check_args(int ac, char **av);
int get_y_file(char *path);
int get_x_file(char *path);
int get_coord_maze(maze_t *maze, char *path);
int load_maze(maze_t *maze, char *path);
char *my_strncpy(char *str, int n);
int my_putchar(char c);
int my_putstr(char *str);

#endif //_SOLVER_H_
