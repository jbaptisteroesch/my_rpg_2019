/*
** EPITECH PROJECT, 2020
** my_rpg Project
** File description:
** functions list
*/

#include "my.h"
#include "game.h"

#ifndef RPG_H_
#define RPG_H_

// General functions

int (*select_game_state[4])(game_t *game);
window_t *create_window(window_t *window, char *title);
elem_t create_element(elem_t element, char *element_name,
                                                    float pos_x, float pos_y);
button_t create_button(button_t button, char *button_name,
                                                    float pos_x, float pos_y);
void usage(void);
int main_menu(game_t *game);
int settings_menu(game_t *game);
int in_game(game_t *game);
int pause_menu(game_t *game);
int change_state_cause_of_error(game_t *game);

// Main menu functions

int init_game_menu(game_t *game);
void draw_main_menu(game_t *game);
int events_main_menu(game_t *game);
void destroy_main_menu(game_t *game);
#endif /* !RPG_H_ */
