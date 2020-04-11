/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hitbox_player
*/

#include "rpg.h"

int (*scene[])(game_t *game) = {
    NULL,
    scene_outside,
    scene_tavern,
    scene_seller,
    scene_cave,
    scene_dungeon,
    hitbox_pnj
};

static int pixel_verification(game_t *ga, u_int8_t player, u_int8_t map)
{
    if (RED_MATCH || GREEN_MATCH)
        return (2);
    if (BLUE_MATCH || LOW_BLUE_MATCH)
        ga->hit.transparent = 1;
    for (u_int8_t i = 2; i < ga->hit.ic_c; ++i) {
        if (SCENE_MATCH) {
            if ((*scene[i - 1])(ga))
            return (1);
        }
    }
    if (INTERACTION_MATCH)
        (*scene[6])(ga);
    return (0);
}

static int hitbox_verification(game_t *ga, elem_t *c, hitbox_t *h)
{
    sfVector2i p = h->player.pos;
    bool collision = 0;
    int value = 0;
    // sfVector2f a = sfSprite_getPosition(ga->player.character.sprite);
    // printf("player pos x:%f y:%f\n", a.x, a.y);
    // printf("player pos hitbox x:%d y:%d\n\n", p.x, p.y);
    h->transparent = 0;
    h->pnj = 0;
    for (int y = 0; y < c->rect.height; ++y) {
        for (int x = 0; x < c->rect.width; ++x) {
            if (OUT_OF_RANGE)
                continue;
            value = pixel_verification(ga, PLAYER_PIXEL, MAP_PIXEL);
            if (value == 1) return (1);
            else if (value == 2) collision = 1;
        }
    }
    if (collision) return (1);
    return (0);
}

int hitbox_effect(game_t *ga, int n_x, int n_y)
{
    ga->hit.player.pos.x += n_x;
    ga->hit.player.pos.y += n_y;
    if (hitbox_verification(ga, &ga->player.character, &ga->hit)) {
        ga->hit.player.pos.x -= n_x;
        ga->hit.player.pos.y -= n_y;
        return (1);
    }
    return (0);
}