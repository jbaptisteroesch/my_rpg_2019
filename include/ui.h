/*
** EPITECH PROJECT, 2020
** my_rpg Project
** File description:
** ui structs
*/

#include "my.h"
#include "elements.h"

#ifndef UI_H_
#define UI_H_

typedef struct button_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    int state;
} button_t;

typedef struct string_s
{
    sfText *string;
    sfFont *font;
    sfColor color;
    sfVector2f place_string;
} string_t;

typedef struct menu_s
{
    elem_t *ui_scene;
    elem_t *buttons;
    string_t *texts;
} menu_t;

#endif /* !UI_H_ */
