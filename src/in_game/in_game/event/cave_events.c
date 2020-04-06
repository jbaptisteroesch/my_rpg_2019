/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_event
*/

#include "../../../../include/rpg.h"

int cave_events(game_t *game)
{
    return (0);
}

void move_down_cave(game_t *ga)
{
    sfVector2f map = sfSprite_getPos(
                        ga->game_scenes[CAVE_MAP].ui_scene[MAP].sprite);
    sfVector2f player = sfSprite_getPos(ga->player.character.sprite);
    sfVector2f move = {0, -6};
    ga->player.character.rect.top = 0;
    sfSprite_setTextureRect(ga->player.character.sprite,
    ga->player.character.rect);
    if (map.y > -120 && player.y > 540) {
        if (hitbox_effect(ga, 0, 6)) return;
        sfSprite_move(ga->game_scenes[CAVE_MAP].ui_scene[MAP].sprite, move);
    } else
        move_character(ga, 0, 6);
    return;
}

void move_up_cave(game_t *ga)
{
    sfVector2f map = sfSprite_getPos(
                    ga->game_scenes[CAVE_MAP].ui_scene[MAP].sprite);
    sfVector2f player = sfSprite_getPos(ga->player.character.sprite);
    sfVector2f move = {0, 6};

    ga->player.character.rect.top = 147;
    sfSprite_setTextureRect(ga->player.character.sprite,
    ga->player.character.rect);
    if (map.y < -50 && player.y < 540) {
        if (hitbox_effect(ga, 0, -6)) return;
        sfSprite_move(ga->game_scenes[CAVE_MAP].ui_scene[MAP].sprite, move);
    } else
        move_character(ga, 0, -6);
    return;
}