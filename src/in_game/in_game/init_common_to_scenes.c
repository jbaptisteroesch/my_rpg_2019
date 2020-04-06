/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game
*/

#include "../../../include/rpg.h"

int init_common_to_scenes(game_t *game)
{
    if (!(game->common_to_scenes = malloc(sizeof(elem_t) * 1)))
        return (1);
    game->common_to_scenes[TEXT_BOX] = create_element(
        game->common_to_scenes[TEXT_BOX], "media/text_box.png", 300, 815);
    return (0);
}