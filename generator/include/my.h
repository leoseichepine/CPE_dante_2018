/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

typedef struct maze
{
    int x;
    int y;
    int count;
    int random;
} maze_t;

int my_str_isnum(char const *str);
void create_imperfect(char **map, maze_t *gen);
int init_imperfect(char *x, char *y, maze_t *gen);
void algorithm_imperfect(char **map, int i, int j, maze_t *gen);
char **generate_map(int x, int y, maze_t *gen);
void display_map(char **map);
int random_number(int nb);
int random_border(int nb);
int init_perfect(char *x, char *y, maze_t *gen);
void perfect_alea(char **map, maze_t *gen, int i, int j);
void perfect_alea2(char **map, maze_t *gen, int i, int j);
void create_perfect(char **map, maze_t *gen);
void random_perfect(maze_t *gen, char **map, int i, int j);
char **generate_perfect(int x, int y, maze_t *gen);
int count_stars(char **map, maze_t *gen, int i, int j);
void map_perfect(maze_t *gen, char **map);

#endif
