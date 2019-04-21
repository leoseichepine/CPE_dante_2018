/*
** EPITECH PROJECT, 2019
** generator
** File description:
** __DESCRIPTION__
*/

#ifndef GENERATOR_H_
    #define GENERATOR_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

typedef struct s_generator
{
    int rows;
    int cols;
    int perfect;
    char **maze;
} gen_t;

int is_str_num(char *str);
gen_t *init_struct(char **av);
int my_strlen(char *str);
int random_number(int nb);
int my_strcmp(char *str1, char *str2);
int print_arr(char **arr);
int my_atoi(char *str);
int print_maze(gen_t *gen);
int print_matrix(int **matrix, int rows, int cols);
    #endif //GENERATOR_H_
