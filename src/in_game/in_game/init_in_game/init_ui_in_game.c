/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game
*/

#include "../../../../include/my.h"

int init_in_game_scene(game_t *game)
{
    if (!(game->game_scenes = malloc(sizeof(scene_t) * 1)))
        return (1);
    if (init_ui_scene_0_in_game(game))
        return (1);
    return (0);
}

int init_ui_scene_0_in_game(game_t *game)
{
    if (!(game->game_scenes[0].ui_scene = malloc(sizeof(elem_t) * 1)))
        return (1);
    // TODO POUR Flo : Insérer le nom de la map ici !! 
    game->game_scenes[0].ui_scene[MAP] = create_element(
        game->game_scenes[0].ui_scene[MAP], "media/background/map_rpg.png",
                                                                0, 0);
    return (0);
}