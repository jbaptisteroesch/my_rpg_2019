/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game
*/

#include "../../../include/my.h"

int init_in_game(game_t *game)
{
    if (init_in_game_scene(game))
        return (1);
    return (0);
}

int in_game(game_t *game)
{
    if (init_in_game(game))
        change_state_cause_of_error(game);
    while (game->game_state[GAME] == 1) {
        draw_in_game(game);
        events_in_game(game);
        sfRenderWindow_display(game->window->window);
    }
    //destroy_in_game(game);
    return (0);
}