/*
** EPITECH PROJECT, 2020
** rpg project
** File description:
** window h
*/

#ifndef WINDOW_H_
#define WINDOW_H_

#include "my.h"

typedef struct s_window
{
    sfVector2f scale;
    sfEvent event;
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfTexture *texture;
    sfSprite *sprite;
    int pos;
} window_t;

#endif /* !WINDOW_H_ */
