/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_move
*/

#include "../../../../include/rpg.h"

void move_character(game_t *game, int x, int y)
{
    sfVector2f offset = {x, y};

    if (hitbox_effect(game, x, y))
        return;
    sfSprite_move(game->player.character.sprite, offset);
    return;
}

void move_left(game_t *ga)
{
    sfVector2f map = sfSprite_getPos(
                ga->game_scenes[OUTSIDE_MAP].ui_scene[MAP].sprite);
    sfVector2f player = sfSprite_getPos(ga->player.character.sprite);
    sfVector2f move = {6, 0};

    ga->player.character.rect.top = 48;
    sfSprite_setTextureRect(ga->player.character.sprite,
    ga->player.character.rect);
    if (map.x < -50 && player.x < 960) {
        if (hitbox_effect(ga, -6, 0)) return;
        sfSprite_move(ga->game_scenes[OUTSIDE_MAP].ui_scene[MAP].sprite, move);
    } else
        move_character(ga, -6, 0);
    return;
}

void move_right(game_t *ga)
{
    sfVector2f map = sfSprite_getPos(
                    ga->game_scenes[OUTSIDE_MAP].ui_scene[MAP].sprite);
    sfVector2f player = sfSprite_getPos(ga->player.character.sprite);
    sfVector2f move = {-6, 0};

    ga->player.character.rect.top = 96;
    sfSprite_setTextureRect(ga->player.character.sprite,
    ga->player.character.rect);
    if (map.x > -430 && player.x > 960) {
        if (hitbox_effect(ga, 6, 0)) return;
        sfSprite_move(ga->game_scenes[OUTSIDE_MAP].ui_scene[MAP].sprite, move);
    } else
        move_character(ga, 6, 0);
    return;
}

void move_up(game_t *ga)
{
    sfVector2f map = sfSprite_getPos(
                    ga->game_scenes[OUTSIDE_MAP].ui_scene[MAP].sprite);
    sfVector2f player = sfSprite_getPos(ga->player.character.sprite);
    sfVector2f move = {0, 6};

    if (ga->player.is_on_scene == DUNGEON_MAP)
        return (move_up_dungeon(ga));
    else if (ga->player.is_on_scene == CAVE_MAP)
        return (move_up_cave(ga));
    else if (ga->player.is_on_scene != OUTSIDE_MAP)
        return (move_character(ga, 0, -6));
    ga->player.character.rect.top = 147;
    sfSprite_setTextureRect(ga->player.character.sprite,
    ga->player.character.rect);
    if (map.y < -50 && player.y < 540) {
        if (hitbox_effect(ga, 0, -6)) return;
        sfSprite_move(ga->game_scenes[OUTSIDE_MAP].ui_scene[MAP].sprite, move);
    } else
        move_character(ga, 0, -6);
    return;
}

void move_down(game_t *ga)
{
    if (ga->player.is_on_scene == DUNGEON_MAP)
        return (move_down_dungeon(ga));
    else if (ga->player.is_on_scene == CAVE_MAP)
        return (move_down_cave(ga));
    else if (ga->player.is_on_scene != OUTSIDE_MAP)
        return (move_character(ga, 0, 6));
    sfVector2f map = sfSprite_getPos(
                        ga->game_scenes[OUTSIDE_MAP].ui_scene[MAP].sprite);
    sfVector2f player = sfSprite_getPos(ga->player.character.sprite);
    sfVector2f move = {0, -6};

    ga->player.character.rect.top = -1;
    sfSprite_setTextureRect(ga->player.character.sprite,
    ga->player.character.rect);
    if (map.y > -1050 && player.y > 540) {
        if (hitbox_effect(ga, 0, 6)) return;
        sfSprite_move(ga->game_scenes[OUTSIDE_MAP].ui_scene[MAP].sprite, move);
    } else
        move_character(ga, 0, 6);
    return;
}