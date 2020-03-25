/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** main menu
*/

#include "../../include/my.h"

void draw_main_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->window, game->window->sprite, NULL);
    return;
}