/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** exit_scene
*/

#include "rpg.h"

void exit_scene_tavern(game_t *ga)
{
    ga->hit.player.pos = (sfVector2i){196, 216};
    ga->player.character.set_position = (sfVector2f){148, 162};
    ga->player.pl_not_op.set_position = (sfVector2f){148, 162};
}

void exit_scene_seller(game_t *ga)
{
    ga->hit.player.pos = (sfVector2i){1894, 504};
    ga->player.character.set_position = (sfVector2f){1462, 450};
    ga->player.pl_not_op.set_position = (sfVector2f){1462, 450};
}

void exit_scene_cave(game_t *ga)
{
    ga->hit.player.pos = (sfVector2i){484, 1854};
    ga->player.character.set_position = (sfVector2f){436, 798};
    ga->player.pl_not_op.set_position = (sfVector2f){436, 798};
}

void exit_scene_dungeon(game_t *ga)
{
    ga->hit.player.pos = (sfVector2i){1870, 1800};
    ga->player.character.set_position = (sfVector2f){1438, 750};
    ga->player.pl_not_op.set_position = (sfVector2f){1438, 750};
}
