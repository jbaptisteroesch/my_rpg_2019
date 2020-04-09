/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** draw_inventory
*/

#include "rpg.h"

void draw_shield(game_t *game)
{
    if (game->player.inventory.has_drop_shield &&
            game->player.inventory.is_equip_shield) {
        drawSprite(WINDOW,
            game->common.inventory_ui[LITTLE_SHIELD].sprite, NULL);
        drawSprite(WINDOW,
            game->common.inventory_ui[SHIELD_SHADOW].sprite, NULL);
    }
    else if (game->player.inventory.has_drop_shield &&
                !game->player.inventory.is_equip_shield)
        drawSprite(WINDOW,
            game->common.inventory_ui[BIG_SHIELD].sprite, NULL);
    else
        return;
    return;
}

void draw_sword(game_t *game)
{
    if (game->player.inventory.has_drop_sword &&
            game->player.inventory.is_equip_sword == true) {
        drawSprite(WINDOW,
            game->common.inventory_ui[LITTLE_SWORD].sprite, NULL);
        drawSprite(WINDOW,
            game->common.inventory_ui[SWORD_SHADOW].sprite, NULL);
    }
    else if (game->player.inventory.has_drop_sword &&
            !game->player.inventory.is_equip_sword)
        drawSprite(WINDOW,
            game->common.inventory_ui[BIG_SWORD].sprite, NULL);
    else
        return;
    return;
}

void draw_inventory(game_t *game)
{
    drawSprite(WINDOW,
        game->common.inventory_ui[INV_UI].sprite, NULL);
    if (game->common.close_inv_butt.is_hover == true)
        drawSprite(WINDOW, game->common.close_inv_butt.sprite, NULL);
    draw_shield(game);
    draw_sword(game);
    return;
}