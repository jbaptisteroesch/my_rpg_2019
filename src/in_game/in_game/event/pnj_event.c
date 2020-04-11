/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** pnj_event
*/

#include "rpg.h"

char *rpg_dialog(game_t *game, char *curr_dialog)
{
    int j = 0;
    int i = game->game_scenes[game->player.is_on_scene].pos_in_dial;

    j = my_strlen(game->game_scenes[game->player.is_on_scene].dialog);
    if (curr_dialog == NULL) {
        if (!(curr_dialog = malloc(sizeof(char) *
            (my_strlen(game->game_scenes[game->player.is_on_scene].dialog +
            1)))))
            return (NULL);
    }
    curr_dialog[i] = game->game_scenes[game->player.is_on_scene].dialog[i];
    curr_dialog[i + 1] = '\0';
    if (i == j - 1)
        return (curr_dialog);
    ++game->game_scenes[game->player.is_on_scene].pos_in_dial;
    return (curr_dialog);
}

int set_pnj_dialog(game_t *game, char *text)
{
    sfText_setString(game->game_scenes[game->player.is_on_scene].texts.string,
        text);
    return (0);
}

int pnj_event(game_t *game)
{
    static double time;
    static char *curr_dialog = NULL;
    game->time = sfClock_getElapsedTime(game->clock);

    time = time + game->time.microseconds / 1000000.0;
    if (game->hit.pnj == 0) {
        time = 0;
        if (curr_dialog != NULL)
            free(curr_dialog);
        curr_dialog = NULL;
    }
    if (time >= 0.1 && game->hit.pnj == 1) {
        if ((curr_dialog = rpg_dialog(game, curr_dialog)) == NULL)
            return (change_state_cause_of_error(game));
        set_pnj_dialog(game, curr_dialog);
        time -= 0.1;
    }
    return (0);
}