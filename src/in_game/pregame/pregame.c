/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** pregame
*/

#include "rpg.h"

int init_pregame(game_t *game)
{
    if (init_ui_pregame(game))
        return (1);
    if (init_button_pregame(game))
        return (1);
    return (0);
}

int pregame(game_t *game)
{
    sfThread *thread;
    bool run_thread = true;
    void *ptr = &init_in_game;

    thread = sfThread_create(ptr, game);
    if (init_pregame(game))
        change_state_cause_of_error(game);
    while (game->game_state[PREGAME] == 1) {
        draw_pregame(game);
        events_pregame(game);
        if (run_thread == true) {
            sfThread_launch(thread);
            run_thread = false;
        }
        sfRenderWindow_display(game->window->window);
    }
    sfThread_destroy(thread);
    destroy_pregame(game);
    return (0);
}