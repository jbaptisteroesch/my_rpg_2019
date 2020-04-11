/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** events main menu
*/

#include "rpg.h"

int (*select_events_in_game[5])(game_t *game) = {
    outside_events,
    tavern_events,
    seller_events,
    cave_events,
    dungeon_events,
};

int events_in_game(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window->window,
        &(game->window->event))) {
        if (game->window->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window->window);
            game->game_state[GAME] = 0;
            game->game_is_up = 0;
        }
        if (game->window->event.type == sfEvtKeyReleased &&
            game->window->event.key.code == sfKeyEscape)
            game->game_state[PAUSE_MENU] = 1;
        GET_MOUSE_POS;
        inventory_events(game);
        rpg_event(game);
        event_keyboard(game);
        is_player_walking(game);
    }
    return (1);
}