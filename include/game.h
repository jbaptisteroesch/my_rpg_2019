/*
** EPITECH PROJECT, 2020
** rpg project
** File description:
** game struct
*/

#ifndef GAME_H_
#define GAME_H_

#include "my.h"
#include <SFML/System/Clock.h>

typedef struct game_s
{
    sfMusic *music;
    window_t *window;
    sfVector2i mouse_position;
} game_t;
#endif /* !GAME_H_ */
