/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** outside pnj
*/

#include "rpg.h"

int init_outside_pnj(game_t *game)
{
    if (!(game->game_scenes[OUTSIDE_MAP].pnj = malloc(sizeof(elem_t) * 2)))
        return (1);
    game->game_scenes[OUTSIDE_MAP].pnj[PNJ_F] = create_element(
        game->game_scenes[OUTSIDE_MAP].pnj[PNJ_F],
                "media/pnj/outside_pnj.png", 1520, 671);
    game->game_scenes[OUTSIDE_MAP].pnj[PNJ_S] = create_element(
        game->game_scenes[OUTSIDE_MAP].pnj[PNJ_S],
                "media/pnj/w_outside.png", 800, 500);
    game->game_scenes[OUTSIDE_MAP].dialog =
        read_file("media/pnj/outside_dialog");
    return (0);
}