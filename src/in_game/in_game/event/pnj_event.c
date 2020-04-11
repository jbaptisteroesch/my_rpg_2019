/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** pnj_event
*/

#include "rpg.h"

char *rpg_dialog(game_t *game, int i, char *curr_dialog)
{
    int j = 0;
    int temp = i;

    j = my_strlen(game->game_scenes[game->player.is_on_scene].dialog);
    if (curr_dialog == NULL) {
        if (!(curr_dialog = malloc(sizeof(char) *
            (my_strlen(game->game_scenes[game->player.is_on_scene].dialog +
            1)))))
        return (NULL);
    }
    curr_dialog[i] = game->game_scenes[game->player.is_on_scene].dialog[i];
    curr_dialog[temp + 1] = '\0';
    if (i == j - 1)
        return (curr_dialog);
    ++i;
    return (curr_dialog);
}

int set_pnj_dialog(game_t *game, char *text)
{
    sfText_setString(game->game_scenes[game->player.is_on_scene].texts.string,
        text);
    return (0);
}

int clock_text_box(game_t *game, float seconds)
{
    game->time = sfClock_getElapsedTime(game->clock);
    seconds += game->time.microseconds / 1000000;
    if (seconds >= 0.1) {
        seconds -= 1;
        return (1);
    }
    return (0);
}

int rpg_event(game_t *game)
{
    static int i;
    static float seconds;
    static char *curr_dialog = NULL;

    // if (game->hit.pnj == 0) {
    //     i = 0;
    //     seconds = 0;
    //     if (curr_dialog != NULL)
    //         free(curr_dialog);
    //     curr_dialog = NULL;
    // }
    if (clock_text_box(game, seconds)) {
        if ((curr_dialog = rpg_dialog(game, i, curr_dialog)) == NULL)
            return (change_state_cause_of_error(game));
        set_pnj_dialog(game, curr_dialog);
        printf("text : %s\n", curr_dialog);
    }
    return (0);
}