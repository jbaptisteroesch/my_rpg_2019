/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** events main menu
*/

#include "../../../include/my.h"

int move_character(game_t *game, int x, int y)
{
    sfVector2f position;
    position.x = x;
    position.y = y;

    sfSprite_move(game->character.sprite, position);
    return (0);
}

int move_character_cond(game_t *game, int pos)
{
    switch (pos)
    {
    case LEFT:
        move_character(game, -3, 0);
        break;
    case RIGHT:
        move_character(game, 3, 0);
        break;
    case UP:
        move_character(game, 0, -3);
        break;
    case DOWN:
        move_character(game, 0, 3);
        break;
    }
    return (0);
}

int move_map_next(game_t *game, int movement)
{
    sfVector2f movements;
    sfVector2f position =
    sfSprite_getPosition(game->game_scenes[0].ui_scene[MAP].sprite);
    sfVector2f chara = sfSprite_getPosition(game->character.sprite);

    if (movement == RIGHT && position.x < 2300 && chara.x > 300) {
        movements.x = -3;
        movements.y = 0;
        sfSprite_move(game->game_scenes[0].ui_scene[MAP].sprite, movements);
        return (1);
    }
    else if (movement == LEFT && position.x <= 0 && chara.x < 2300) {
        movements.x = 3;
        movements.y = 0;
        sfSprite_move(game->game_scenes[0].ui_scene[MAP].sprite, movements);
        return (1);
    }
    return (0);
}

int move_map(game_t *game, int movement)
{
    sfVector2f movements;
    sfVector2f position =
    sfSprite_getPosition(game->game_scenes[0].ui_scene[MAP].sprite);
    sfVector2f chara = sfSprite_getPosition(game->character.sprite);

    if (movement == UP && position.y < 0 && chara.y < 2000) {
        movements.x = 0;
        movements.y = 3;
        sfSprite_move(game->game_scenes[0].ui_scene[MAP].sprite, movements);
        return (1);
    }
    else if (movement == DOWN && position.y < 2300 && chara.y > 300) {
        movements.x = 0;
        movements.y = -3;
        sfSprite_move(game->game_scenes[0].ui_scene[MAP].sprite, movements);
        return (1);
    } else {
        return (move_map_next(game, movement));
    }
}