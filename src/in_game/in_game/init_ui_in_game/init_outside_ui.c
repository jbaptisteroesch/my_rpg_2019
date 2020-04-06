/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** init outside
*/

#include "../../../../include/rpg.h"

int init_ui_outside(game_t *game)
{
    if (!(game->game_scenes[OUTSIDE_MAP].ui_scene = malloc(sizeof(elem_t))))
        return (1);
    game->game_scenes[OUTSIDE_MAP].ui_scene[MAP] = create_element(
        game->game_scenes[OUTSIDE_MAP].ui_scene[MAP], "media/game/outside.png",
                                                                -48, -48);
    return (0);
}