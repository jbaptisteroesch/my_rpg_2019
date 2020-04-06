/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game
*/

#include "../../../include/rpg.h"

int init_in_game(game_t *game)
{
    if (init_in_game_scene(game))
        return (1);
    if (init_hitbox(game))
        return (1);
    if (create_character(game))
        return (1);
    if (create_utils_in_game(game))
        return (1);
    sfClock_restart(game->clock);
    return (0);
}

int in_game(game_t *game)
{
    if (init_in_game(game))
        change_state_cause_of_error(game);
    while (game->game_state[GAME] == 1) {
        sfRenderWindow_clear(WINDOW, sfBlack);
        events_in_game(game);
        draw_in_game(game);
        is_player_walking(game);
        while(game->game_state[PAUSE_MENU] == 1)
            pause_menu(game);
        sfClock_restart(game->clock);
        sfRenderWindow_display(game->window->window);
    }
    //destroy_in_game(game);
    return (0);
}