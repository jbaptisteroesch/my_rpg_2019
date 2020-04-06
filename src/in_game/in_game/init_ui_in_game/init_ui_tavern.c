/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** init tavern
*/

#include "../../../../include/rpg.h"

int init_ui_tavern(game_t *game)
{
    if (!(game->game_scenes[TAVERN_MAP].ui_scene = malloc(sizeof(elem_t))))
        return (1);
    game->game_scenes[TAVERN_MAP].ui_scene[MAP] = create_element(
        game->game_scenes[TAVERN_MAP].ui_scene[MAP], "media/game/tavern.png",
                                                                545, 49);
                                    // !! NE PAS TOUCHER A CES COORDONNES
    return (0);
}