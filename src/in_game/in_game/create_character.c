/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** create character
*/

#include "rpg.h"

int create_character(game_t *game)
{
    select_skin(game);
    game->player.character.rect.height = 50;
    game->player.character.rect.left = 0;
    game->player.character.rect.top = 0;
    game->player.character.rect.width = 44;
    sfSprite_setTextureRect(game->player.character.sprite,
                                                game->player.character.rect);
    game->player.experience = 0;
    game->player.gold = 0;
    game->player.level = 0;
    game->player.is_on_scene = 0;
    // TODO inventory
    return (0);
}

void select_skin(game_t *game)
{
    switch (game->player.type) {
        case BLOND_BOY:
            game->player.character = create_element(game->player.character,
                            "media/player/walking_blond_boy.png", 820, 480);
            break;
        case BROWN_BOY:
            game->player.character = create_element(game->player.character,
                            "media/player/walking_brown_boy.png", 820, 480);
            break;
        case BLOND_GIRL:
            game->player.character = create_element(game->player.character,
                            "media/player/walking_blond_girl.png", 820, 480);
            break;
        case BROWN_GIRL:
            game->player.character = create_element(game->player.character,
                            "media/player/walking_brown_girl.png", 820, 480);
            break;
    }
    return;
}