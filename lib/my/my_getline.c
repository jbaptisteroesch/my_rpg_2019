/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** my getline
*/

#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define _GNU_SOURCE

int my_getline(char *filepath)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int size = 0;

    fp = fopen(filepath, "r");
    if (fp == NULL)
        return (0);
    while ((read = getline(&line, &len, fp)) != -1) {
        size += read;
    }
    if (line)
        free(line);
    return (size);
}