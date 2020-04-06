/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** draw file
*/

#include "../../../../include/rpg.h"

void draw_cave(game_t *game)
{
    drawSprite(WINDOW,
            game->game_scenes[CAVE_MAP].ui_scene[MAP].sprite, NULL);
    drawSprite(WINDOW, game->player.character.sprite, NULL);
    return;
}