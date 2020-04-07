/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hitbox_player
*/

#include "rpg.h"

static int hitbox_verification(elem_t *c, hitbox_t *h, game_t *ga)
{
    sfVector2i p = h->player.pos;
    int bool_blue = 0;

    for (int y = 0; y < c->rect.height; ++y) {
        for (int x = 0; x < c->rect.width; ++x) {
            if (OUT_OF_RANGE)
                continue;
            if (BLUE_MATCH && !bool_blue) {
                bool_blue = 1;
                h->bool_display = 0;
            }
            if ((GREEN_MATCH) || (RED_MATCH))
                return (1);
        }
    }
    if (!bool_blue)
        h->bool_display = 1;
    return (0);
}

int hitbox_effect(game_t *ga, int n_x, int n_y)
{
    ga->hit.player.pos.x += n_x;
    ga->hit.player.pos.y += n_y;
    if (hitbox_verification(&ga->player.character, &ga->hit, ga)) {
        ga->hit.player.pos.x -= n_x;
        ga->hit.player.pos.y -= n_y;
        return (1);
    }
    return (0);
}