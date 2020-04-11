/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** cave pnj
*/

#include "rpg.h"

int init_cave_pnj(game_t *game)
{
    if (!(game->game_scenes[CAVE_MAP].pnj = malloc(sizeof(elem_t) * 2)))
        return (1);
    game->game_scenes[CAVE_MAP].pnj[PNJ_F] = create_element(
        game->game_scenes[CAVE_MAP].pnj[PNJ_F],
                "media/pnj/cave_pnj.png", 1520, 671);
    game->game_scenes[CAVE_MAP].pnj[PNJ_S] = create_element(
        game->game_scenes[CAVE_MAP].pnj[PNJ_S],
                "media/pnj/w_cave.png", 800, 500);
    game->game_scenes[CAVE_MAP].dialog = read_file("media/pnj/cave_dialog");
    return (0);
}