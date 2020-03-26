/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** events main menu
*/

#include "../../../include/my.h"

int events_keyboard_next(game_t *game, int moved, int pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        moved = move_map(game, UP);
        pos = UP;
    }
    else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        moved = move_map(game, DOWN);
        pos = DOWN;
    }
    if (moved == 0) {
        move_character_cond(game, pos);
    }
}

int events_keyboard(game_t *game)
{
    int moved = 0;
    int pos = 0;

    if (game->window->event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
            moved = move_map(game, RIGHT);
            pos = RIGHT;
            if (moved == 0)
                move_character_cond(game, pos);
        }
        else if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
            moved = move_map(game, LEFT);
            pos = LEFT;
            if (moved == 0)
                move_character_cond(game, pos);
        }
        else
            events_keyboard_next(game, moved, pos);
    }
    return (0);
}