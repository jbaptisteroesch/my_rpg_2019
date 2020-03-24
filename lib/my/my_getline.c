/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** return a number send to the function as a string
*/

#define _GNU_SOURCE

#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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