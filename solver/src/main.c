/*
** EPITECH PROJECT, 2023
** dante
** File description:
** solver.c
*/

#include "dante.h"

size_t get_width(const char *buffer)
{
    unsigned int j = 0;
    unsigned int len = 0;

    for (unsigned int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            len = j > len ? j : len;
            j = 0;
        } else {
            j++;
        }
    }
    return len;
}

size_t get_height(const char *buffer)
{
    int i = 0;
    size_t len = 0;

    for (i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            len++;
    }
    return len + 1;
}

char **set_map(const char *buffer, size_t map_i, size_t map_j)
{
    char **map = calloc(map_j + 1, sizeof(char *));

    if (!map)
        exit(84);
    for (size_t i = 0; i < map_j; i++) {
        map[i] = malloc(map_i + 1);
        if (!map[i])
            exit(84);
        strncpy(map[i], buffer, map_i);
        map[i][map_i] = '\0';
        buffer += (map_i + 1);
    }
    return map;
}

int map(const char *filepath)
{
    struct stat st;
    char **map = NULL;
    off_t len = 0; size_t map_i, map_j;
    char *buffer; int file = 0;
    if (!filepath) exit(84);
    file = open(filepath, O_RDONLY);
    if (file == -1 || fstat(file, &st) == -1) exit(84);
    len = st.st_size;
    buffer = malloc(sizeof(char) * (size_t)(st.st_size + 1));
    if (read(file, buffer, (size_t)len) == -1)
        exit(84);
    close(file);
    buffer[len] = '\0';
    map_i = get_width(buffer);
    map_j = get_height(buffer);
    map = set_map(buffer, map_i, map_j);
    if (!map) exit(84);
    solver(map, map_i, map_j);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    map(argv[1]);
    return 0;
}
