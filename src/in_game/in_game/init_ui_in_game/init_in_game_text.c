/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** init_in_game_text
*/

#include "rpg.h"

int init_in_game_text(game_t *game)
{
    sfVector2f position;

    position.x = 200;
    position.y = 800;

    for (int i = 0; i < 5; ++i) {
        game->game_scenes[i].texts.string = sfText_create();
        game->game_scenes[i].texts.font = sfFont_createFromFile(
            "media/font/DimboRegular.ttf");
        sfText_setFont(game->game_scenes[i].texts.string,
            game->game_scenes[i].texts.font);
        game->game_scenes[i].texts.color =
            sfColor_fromRGB(255, 255, 255);
        sfText_setColor(game->game_scenes[i].texts.string,
            game->game_scenes[i].texts.color);
        sfText_setCharacterSize(game->game_scenes[i].texts.string, 50);
        sfText_setPosition(game->game_scenes[i].texts.string, position);
    }
    return (0);
}