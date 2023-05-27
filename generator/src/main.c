/*
** EPITECH PROJECT, 2023
** dante
** File description:
** generator.c
*/

#include "dante.h"

void print_maze(var_t *var)
{
    for (int i = 0; var->maze[i + 1]; i++) {
        write(1, var->maze[i], var->x);
        write(1, "\n", 1);
    }
    write(1, var->maze[var->y - 1], var->x);
}

int main(int argc, char **argv)
{
    var_t *var = NULL;
    if (argc != 3 && argc != 4)
        return 84;
    srand((unsigned int)(getpid() * time(NULL)));
    var = malloc(sizeof(var_t));
    if (!var)
        return 84;
    var->x = (unsigned int)atoi(argv[1]);
    var->y = (unsigned int)atoi(argv[2]);
    if (var->x < 3 || var->y < 3)
        return 84;
    var->perfect = (argc == 4);
    create_grid(var);
    maze_generator(var);
    print_maze(var);
    for (unsigned int i = 0; i < var->y; i++)
        free(var->maze[i]);
    free(var->maze);
    free(var);
    return 0;
}
