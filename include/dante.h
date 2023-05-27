/*
** EPITECH PROJECT, 2022
** dante.h
** File description:
** dante
*/

#ifndef DANTE_H_

    #define DANTE_H_

    #include <fcntl.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <time.h>
    #include <unistd.h>

typedef struct cell_s {
    size_t x;
    size_t y;
    struct cell_s *prev;
    struct cell_s *next;
} cell_t;

typedef struct var {
    unsigned int x;
    unsigned int y;
    bool perfect;
    char **maze;
} var_t;

cell_t *add_cell(size_t x, size_t y, cell_t *cell);
cell_t *create_cell(void);
cell_t *delete_last_cell(cell_t *cell);
char **replace_map(char **maze, size_t map_i, size_t map_j);
char **set_map(const char *buffer, size_t map_i, size_t map_j);
int dijkstra(char **maze, cell_t *cell, size_t map_i, size_t map_j);
int find_way(cell_t **cell, char **madp, size_t map_i, size_t map_j);
int map(const char *filepath);
void solver(char **maze, size_t map_i, size_t map_j);
size_t get_height(const char *buffer);
size_t get_width(const char *buffer);
void break_walls(var_t *var);
void create_grid(var_t *var);
void displays(char **map, size_t i);
void free_list(cell_t *head);
void free_map(char **maze, size_t map_j);
void maze_generator(var_t *var);
void print_maze(var_t *var);

#endif /* DANTE_H_ */
