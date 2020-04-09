/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** choose_equipment
*/

#include "rpg.h"

int equip_shield(game_t *game, int wich_one)
{
    if (wich_one == INV_RECT_BSH && !game->player.inventory.is_equip_shield)
        game->player.inventory.is_equip_shield = true;
    else if (wich_one == INV_RECT_LSH && game->player.inventory.is_equip_shield)
        game->player.inventory.is_equip_shield = false;
    return (0);
}

int equip_sword(game_t *game, int wich_one)
{
    if (wich_one == INV_RECT_BSW && !game->player.inventory.is_equip_sword)
        game->player.inventory.is_equip_sword = true;
    else if (wich_one == INV_RECT_LSW && game->player.inventory.is_equip_sword)
        game->player.inventory.is_equip_sword = false;
    return (0);
}

int is_on_equip_case(game_t *game)
{
    sfFloatRect rect_rect;

    for (int i = 1; i < 5; ++i) {
        rect_rect = sfRectangleShape_getGlobalBounds(
            game->common.inv_rectangle[i].rect);
        game->common.inv_rectangle[i].is_hover =
            sfFloatRect_contains(&(rect_rect), MOUSEX, MOUSEY);
        if (game->common.inv_rectangle[i].is_hover)
            return (i);
    }
    return (0);
}

int equipment(game_t *game)
{
    int which_case = 0;

    which_case = is_on_equip_case(game);
    if (which_case == 1 || which_case == 3)
        equip_shield(game, which_case);
    if (which_case == 2 || which_case == 4)
        equip_sword(game, which_case);
    return (0);
}