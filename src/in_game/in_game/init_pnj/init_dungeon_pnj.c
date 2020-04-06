/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** dungeon pnj
*/

#include "../../../../include/rpg.h"

int init_dungeon_pnj(game_t *game)
{
    if (!(game->game_scenes[DUNGEON_MAP].pnj = malloc(sizeof(elem_t) * 2)))
        return (1);
    game->game_scenes[DUNGEON_MAP].pnj[PNJ_F] = create_element(
        game->game_scenes[DUNGEON_MAP].pnj[PNJ_F],
                "media/pnj/dungeon_pnj.png", 1520, 671);
    game->game_scenes[DUNGEON_MAP].pnj[PNJ_S] = create_element(
        game->game_scenes[DUNGEON_MAP].pnj[PNJ_S],
                "media/pnj/w_dungeon.png", 800, 500);
    return (0);
}