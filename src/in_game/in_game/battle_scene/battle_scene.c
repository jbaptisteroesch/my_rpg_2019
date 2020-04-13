/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** battle_scene
*/

#include "rpg.h"

int init_battle_scene(game_t *game)
{
    return (0);
}

int battle_scene(game_t *game)
{
    if (init_battle_scene(game))
        return (change_state_cause_of_error(game));
    sfClock_restart(game->clock);
    while (game->player.is_in_fight == true) {
        sfRenderWindow_clear(WINDOW, sfBlack);
        events_battle_scene(game);
        draw_battle_scene(game);
        sfClock_restart(game->clock);
        sfRenderWindow_display(game->window->window);
    }
    destroy_battle_scene(game);
    return (0);
}