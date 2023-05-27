/*
** EPITECH PROJECT, 2023
** linked_list
** File description:
** linked_list
*/

#include "dante.h"

void displays(char **map, size_t i)
{
    unsigned int j = 0;

    for (j = 0; map[j + 1]; j++) {
        write(1, map[j], i);
        write(1, "\n", 1);
    }
    write(1, map[j], i);
}

cell_t *create_cell(void)
{
    cell_t *cell = malloc(sizeof(cell_t));

    cell->x = 0;
    cell->y = 0;
    cell->next = NULL;
    cell->prev = NULL;
    return cell;
}

cell_t *add_cell(size_t x, size_t y, cell_t *cell)
{
    while (cell->next)
        cell = cell->next;
    cell->next = malloc(sizeof(cell_t));
    cell->next->x = x;
    cell->next->y = y;
    cell->next->prev = cell;
    cell->next->next = NULL;
    return cell;
}

cell_t *delete_last_cell(cell_t *cell)
{
    cell_t *last_cell = cell->prev;
    last_cell->next = NULL;
    free(cell);
    cell = last_cell;
    return cell;
}
