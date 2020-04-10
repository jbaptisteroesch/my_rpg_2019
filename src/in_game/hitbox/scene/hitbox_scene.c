/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hitbox_scene
*/

#include "rpg.h"

void (*exit_scene[])(game_t *ga) = {
    NULL,
    exit_scene_tavern,
    exit_scene_seller,
    exit_scene_cave,
    exit_scene_dungeon,
};

int scene_outside(game_t *ga)
{
    my_free_typoo((void **)ga->hit.map.box);
    (*exit_scene[ga->player.is_on_scene])(ga);
    ga->player.is_on_scene = 0;
    sfSprite_setPosition(ga->player.pl_not_op.sprite,
    ga->player.pl_not_op.set_position);
    sfSprite_setPosition(ga->player.character.sprite,
    ga->player.character.set_position);
    if (init_box(&ga->hit, &ga->hit.map, (sfVector2i){0, 0},
    "media/Collisions/outside_collision.png")) return (1);
    return (0);
}

int scene_tavern(game_t *ga)
{
    my_free_typoo((void **)ga->hit.map.box);
    ga->player.is_on_scene = 1;
    ga->hit.player.pos = (sfVector2i){350, 920};
    ga->player.character.set_position = (sfVector2f){847, 921};
    ga->player.pl_not_op.set_position = (sfVector2f){847, 921};
    sfSprite_setPosition(ga->player.pl_not_op.sprite,
    ga->player.pl_not_op.set_position);
    sfSprite_setPosition(ga->player.character.sprite,
    ga->player.character.set_position);
    if (init_box(&ga->hit, &ga->hit.map, (sfVector2i){0, 0},
    "media/Collisions/tavern_collision.png")) return (1);
    return (0);
}

int scene_seller(game_t *ga)
{
    my_free_typoo((void **)ga->hit.map.box);
    ga->player.is_on_scene = 2;
    ga->hit.player.pos = (sfVector2i){350, 920};
    ga->player.character.set_position = (sfVector2f){822, 920};
    ga->player.pl_not_op.set_position = (sfVector2f){822, 920};
    sfSprite_setPosition(ga->player.pl_not_op.sprite,
    ga->player.pl_not_op.set_position);
    sfSprite_setPosition(ga->player.character.sprite,
    ga->player.character.set_position);
    if (init_box(&ga->hit, &ga->hit.map, (sfVector2i){0, 0},
    "media/Collisions/seller_collision.png")) return (1);
    return (0);
}

int scene_cave(game_t *ga)
{
    my_free_typoo((void **)ga->hit.map.box);
    ga->player.is_on_scene = 3;
    ga->hit.player.pos = (sfVector2i){600, 1000};
    ga->player.character.set_position = (sfVector2f){1035, 910};
    ga->player.pl_not_op.set_position = (sfVector2f){1035, 910};
    sfSprite_setPosition(ga->player.pl_not_op.sprite,
    ga->player.pl_not_op.set_position);
    sfSprite_setPosition(ga->player.character.sprite,
    ga->player.character.set_position);
    if (init_box(&ga->hit, &ga->hit.map, (sfVector2i){0, 0},
    "media/Collisions/cave_collision.png")) return (1);
    return (0);
}

int scene_dungeon(game_t *ga)
{
    my_free_typoo((void **)ga->hit.map.box);
    ga->player.is_on_scene = 4;
    ga->hit.player.pos = (sfVector2i){650, 1800};
    ga->player.character.set_position = (sfVector2f){850, 975};
    ga->player.pl_not_op.set_position = (sfVector2f){850, 975};
    sfSprite_setPosition(ga->player.pl_not_op.sprite,
    ga->player.pl_not_op.set_position);
    sfSprite_setPosition(ga->player.character.sprite,
    ga->player.character.set_position);
    if (init_box(&ga->hit, &ga->hit.map, (sfVector2i){0, 0},
    "media/Collisions/dungeon_collision.png")) return (1);
    return (0);
}