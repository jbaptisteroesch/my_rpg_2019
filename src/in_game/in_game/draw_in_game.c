/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** main menu
*/

#include "../../../include/rpg.h"

void (*select_draw_in_game[5])(game_t *game) = {
    draw_outside,
    draw_tavern,
    draw_seller,
    draw_cave,
    draw_dungeon,
};

void draw_in_game(game_t *game)
{
    select_draw_in_game[game->player.is_on_scene](game);
    return;
}