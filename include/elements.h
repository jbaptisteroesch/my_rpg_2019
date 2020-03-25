/*
** EPITECH PROJECT, 2020
** my_rpg Project
** File description:
** elements
*/

#include "my.h"

#ifndef ELEMENTS_H_
#define ELEMENTS_H_

typedef struct elem_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f set_position;
    sfVector2f get_position;
    sfIntRect rect;
} elem_t;

typedef struct ennemy_s
{
    elem_t *ennemy;
    struct ennemy_s *next;
} ennemy_t;

#endif /* !ELEMENTS_H_ */
