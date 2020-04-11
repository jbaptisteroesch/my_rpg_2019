/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** dungeon pnj
*/

#include "rpg.h"

int init_dungeon_pnj(game_t *game)
{
    game->game_scenes[DUNGEON_MAP].dialog =
        read_file("media/pnj/dungeon_dialog");
    if (game->game_scenes[DUNGEON_MAP].dialog == NULL)
        return (1);
    return (0);
}