/*
** EPITECH PROJECT, 2023
** solver
** File description:
** solver
*/

#include "dante.h"

int find_way(cell_t **cell, char **map, size_t map_i, size_t map_j)
{
    size_t x = (*cell)->x;
    size_t y = (*cell)->y;
    if (y + 1 < map_i && map[x][y + 1] == '*') {
        *cell = add_cell(x, y + 1, *cell);
        return 0;
    }
    if (x + 1 < map_j && map[x + 1][y] == '*') {
        *cell = add_cell(x + 1, y, *cell);
        return 0;
    }
    if (x > 0 && map[x - 1][y] == '*') {
        *cell = add_cell(x - 1, y, *cell);
        return 0;
    }
    if (y > 0 && map[x][y - 1] == '*') {
        *cell = add_cell(x, y - 1, *cell);
        return 0;
    }
    map[x][y] = '1';
    return -1;
}

int dijkstra(char **maze, cell_t *cell, size_t map_i, size_t map_j)
{
    bool stop = false;
    int result = -1;

    while (!stop) {
        maze[cell->x][cell->y] = 'o';
        if (cell->x == map_j - 1 && cell->y == map_i - 1) {
            result = 0;
            break;
        }
        if (find_way(&cell, maze, map_i, map_j) == -1) {
            stop = !cell->x && !cell->y;
            cell = stop ? cell : delete_last_cell(cell);
        }
    }
    return result;
}

char **replace_map(char **maze, size_t map_i, size_t map_j)
{
    for (size_t i = 0; i < map_j; i++) {
        for (size_t j = 0; j < map_i; j++)
            maze[i][j] = maze[i][j] == '1' ? '*' : maze[i][j];
    }
    return maze;
}

void solver(char **maze, size_t map_i, size_t map_j)
{
    cell_t *head;

    if (maze[0][0] != '*' || maze[map_j - 1][map_i - 1] != '*') {
        write(1, "no solution found", 17);
        exit(84);
    }
    head = create_cell();
    if (dijkstra(maze, head, map_i, map_j) == -1) {
        write(1, "no solution found", 17);
        free_map(maze, map_j);
        free_list(head);
        exit(84);
    }
    maze = replace_map(maze, map_i, map_j);
    displays(maze, map_i);
    free_map(maze, map_j);
    free_list(head);
}
