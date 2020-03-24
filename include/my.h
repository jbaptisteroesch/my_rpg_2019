/*
** EPITECH PROJECT, 2020
** lib
** File description:
** myh
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/SoundStream.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Music.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <math.h>
#include "window.h"
#include "game.h"

int my_getnbr(char const *nbr);
int my_isneg(int n);
int my_min(int first, int second, int third);
int my_put_nbr(int nb);
void my_putchar(char c);
long int my_putstr(char *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
void my_swap(int *a, int *b);
char *on_lowercase(char *str);
char *on_uppercase(char *str);
char *my_strdup(char *str);
int my_getline(char *filepath);
int open_file(char *filepath);
char *my_nbrtoarray(int nb);
int size_int(int nb);

#endif /* !MY_H_ */
