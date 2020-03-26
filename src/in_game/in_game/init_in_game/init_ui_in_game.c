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
    //? TEST AVEC CHARA
    game->character = create_element(game->character, "media/chara.png", 500, 500);
    sfVector2f scale;
    scale.x = 0.2;
    scale.y = 0.2;
    sfSprite_setScale(game->character.sprite, scale);
    // ?
    game->game_scenes[0].ui_scene[MAP] = create_element(
        game->game_scenes[0].ui_scene[MAP], "media/background/map_rpg.png",
                                                                0, 0);
    return (0);
}