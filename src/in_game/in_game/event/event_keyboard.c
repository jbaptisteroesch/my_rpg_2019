/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_event
*/

#include "rpg.h"

int event_keyboard(game_t *game)
{
    void (*event[])(game_t *) = {move_left, move_right, move_up, move_down};
    sfKeyCode key[] = {sfKeyLeft, sfKeyRight, sfKeyUp, sfKeyDown};

    if (game->window->event.type != sfEvtKeyPressed) {
        game->player.is_walking = 0;
        return (0);
    }
    game->player.is_walking = 1;
    for (int ic = 0; ic < 4; ++ic) {
        if (sfKeyboard_isKeyPressed(key[ic]))
            (*event[ic])(game);
    }
    return (0);
}

void move_rect_player(game_t *ga)
{
    static int reverse = 1;

    if (reverse == 0)
        ga->player.character.rect.left -= 47;
    else if (reverse == 1)
        ga->player.character.rect.left += 47;
    sfSprite_setTextureRect(ga->player.character.sprite,
    ga->player.character.rect);
    if (ga->player.character.rect.left > 94) {
        reverse = 0;
        ga->player.character.rect.left -= 94;
    }
    else if (ga->player.character.rect.left < 0) {
        ga->player.character.rect.left = 47;
        reverse = 1;
    }
    sfSprite_setTextureRect(ga->player.character.sprite,
    ga->player.character.rect);
    return;
}