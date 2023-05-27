/*
** EPITECH PROJECT, 2023
** dante
** File description:
** generator.c
*/

#include "dante.h"

void create_grid(var_t *var)
{
    var->maze = malloc(sizeof(char *) * (var->y + 1));
    if (!var->maze)
        exit(84);
    for (unsigned int i = 0; i < var->y; i++) {
        var->maze[i] = malloc(sizeof(char) * (var->x + 1));
        if (!var->maze[i])
            exit(84);
        for (unsigned int j = 0; j < var->x; j++)
            var->maze[i][j] = (i == 0 || j == 0) ? '*' : 'X';
        var->maze[i][var->x] = '\0';
    }
    var->maze[var->y] = NULL;
    if (var->x % 2 == 0)
        var->maze[var->y - 1][var->x - 1] = '*';
    if (var->y % 2 == 0) {
        var->maze[var->y - 1][var->x - 1] = '*';
        var->maze[var->y - 2][var->x - 1] = '*';
    }
}
