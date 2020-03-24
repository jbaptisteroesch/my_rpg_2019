/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** main.c
*/

#include "../include/my.h"

int (*select_game_state[8])(game_t *game) = {
    main_menu,
    pregame,
    leaderboard_menu,
    settings_menu,
    quit_game,
    in_game,
    pause_menu,
    end_menu,
};

int launch_game(game_t *game)
{
    int check_tab = 0;

    while (game->menu.game_state[check_tab] != 1 &&
                                    game->menu.game_state[check_tab] != 2)
        ++check_tab;
    if (game->menu.game_state[check_tab] == 2) {
        game->menu.game_is_up = false;
        return (1);
    } else
        select_game_state[check_tab](game);
    return (1);
}

int init_game_state_tab(game_t *game)
{
    int init_tab = 0;

    if (!(game->menu.game_state = malloc(sizeof(int) * 10)))
        return (0);
    while (init_tab < 8) {
        game->menu.game_state[init_tab] = 0;
        ++init_tab;
    }
    game->menu.game_state[init_tab] = 2;
    game->menu.game_state[MAIN_MENU] = 1;
    return (1);
}

int disp_window(game_t *game)
{
    if (!(game->window = malloc(sizeof(window_t))))
        return (0);
    if (!(init_game_state_tab(game)))
        return (0);
    sfVector2f scale = {1, 1};
    game->window->pos = 1180;
    game->window->scale = scale;
    game->window = create_window(game->window, "my_defender");
    game->menu.game_is_up = true;
    create_music(game);
    while (game->menu.game_is_up) {
        if (!(launch_game(game)))
            return (0);
    }
    sfMusic_destroy(game->music);
    return (1);
}

int main(int ac, char **av)
{
    game_t *game;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        usage();
        return (0);
    }
    if (!(game = malloc(sizeof(game_t))))
        return (84);
    check_if_cheat(game, av);
    if (!(disp_window(game)))
        return (84);
    return (0);
}