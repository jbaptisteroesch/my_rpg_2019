/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** main menu
*/

#include "rpg.h"

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
    if (!game->hit.transparent)
        drawSprite(WINDOW, game->player.character.sprite, NULL);
    else
        drawSprite(WINDOW, game->player.pl_not_op.sprite, NULL);
    if (game->player.inventory.inventory_is_open == true)
        draw_inventory(game);
    //if (game->hit.pnj == 1) {
        drawSprite(WINDOW, game->common.common_ui[TEXT_BOX].sprite, NULL);
        sfRenderWindow_drawText(WINDOW,
            game->game_scenes[game->player.is_on_scene].texts.string, NULL);
    //}
    return;
}