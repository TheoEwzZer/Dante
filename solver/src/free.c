/*
** EPITECH PROJECT, 2023
** solver
** File description:
** solver
*/

#include "dante.h"

void free_list(cell_t *head)
{
    cell_t *temp = NULL;

    while (head) {
        temp = head->next;
        free(head);
        head = temp;
    }
}

void free_map(char **maze, size_t map_j)
{
    for (size_t i = 0; i < map_j; i++)
        free(maze[i]);
    free(maze);
}
