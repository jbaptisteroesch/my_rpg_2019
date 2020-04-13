/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_event
*/

#include "rpg.h"

int dungeon_events(game_t *game)
{
    return (0);
}

void move_down_dungeon(game_t *ga)
{
    sfVector2f map = sfSprite_getPos(
                        ga->game_scenes[DUNGEON_MAP].ui_scene[MAP].sprite);
    sfVector2f player = sfSprite_getPos(ga->player.character.sprite);
    sfVector2f move = {0, -6};

    ga->player.character.rect.top = -1;
    sfSprite_setTextureRect(ga->player.character.sprite,
    ga->player.character.rect);
    sfSprite_setTextureRect(ga->player.pl_not_op.sprite,
    ga->player.character.rect);
    if (map.y > -849 && player.y > 540) {
        if (hitbox_effect(ga, 0, 6)) return;
        sfSprite_move(ga->game_scenes[DUNGEON_MAP].ui_scene[MAP].sprite, move);
    } else
        move_character(ga, 0, 6);
    return;
}

void move_up_dungeon(game_t *ga)
{
    sfVector2f map = sfSprite_getPos(
                    ga->game_scenes[DUNGEON_MAP].ui_scene[MAP].sprite);
    sfVector2f player = sfSprite_getPos(ga->player.character.sprite);
    sfVector2f move = {0, 6};

    ga->player.character.rect.top = 147;
    sfSprite_setTextureRect(ga->player.character.sprite,
    ga->player.character.rect);
    sfSprite_setTextureRect(ga->player.pl_not_op.sprite,
    ga->player.character.rect);
    if (map.y < -53 && player.y < 540) {
        if (hitbox_effect(ga, 0, -6)) return;
        sfSprite_move(ga->game_scenes[DUNGEON_MAP].ui_scene[MAP].sprite, move);
    } else
        move_character(ga, 0, -6);
    return;
}