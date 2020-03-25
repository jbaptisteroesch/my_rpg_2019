/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** main menu
*/

#include "../../../include/my.h"

void draw_in_game(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window,
                            game->game_scenes[0].ui_scene[MAP].sprite, NULL);
    return;
}