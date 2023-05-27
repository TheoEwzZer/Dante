/*
** EPITECH PROJECT, 2023
** dante
** File description:
** generator.c
*/

#include "dante.h"

void break_walls(var_t *var)
{
    unsigned int x = 0;
    unsigned int limit = var->x - 2;

    for (unsigned int i = 0; i < var->y; i++) {
        x = (unsigned int)rand() % limit + 1;
        if (var->maze[i][x] == 'X')
            var->maze[i][x] = '*';
        else {
            x = (unsigned int)rand() % limit + 1;
            var->maze[i][x] = '*';
        }
    }
}

void maze_generator(var_t *var)
{
    unsigned int re = 0;

    for (unsigned int i = 2; i < var->y; i += 2) {
        for (unsigned int j = 2; j < var->x; j += 2) {
            var->maze[i][j] = '*';
            re = (unsigned int)rand() % 2;
            re == 1 ? (var->maze[i - 1][j] = '*') : (var->maze[i][j - 1] = '*');
        }
    }
    if (!var->perfect)
        break_walls(var);
}
