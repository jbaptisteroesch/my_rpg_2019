/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** draw file
*/

#include "rpg.h"

void draw_outside(game_t *game)
{
    drawSprite(WINDOW,
            game->game_scenes[OUTSIDE_MAP].ui_scene[MAP].sprite, NULL);
    return;
}