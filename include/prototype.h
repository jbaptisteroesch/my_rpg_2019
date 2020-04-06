/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** prototype
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include "struct.h"

/*************\
*   GENERAL   *
\*************/

int (*select_game_state[5])(game_t *game);
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
int create_music(game_t *game);

/***************\
*   MAIN MENU   *
\***************/

int init_main_menu(game_t *game);
int init_ui_main_menu(game_t *game);
int init_button_main_menu(game_t *game);
void draw_main_menu(game_t *game);
int events_main_menu(game_t *game);
void destroy_main_menu_elements(game_t *game);

/***************\
* SETTINGS MENU *
\***************/

int init_settings_menu(game_t *game);
int init_ui_settings_menu(game_t *game);
int init_button_settings_menu(game_t *game);
int draw_settings_menu(game_t *game);
int events_settings_menu(game_t *game);
int is_on_quit_button_settings(game_t *game);
int is_on_confirm_button_settings(game_t *game);
int is_on_off_music(game_t *game);
void destroy_settings_menu(game_t *game);

/*************\
*   PREGAME   *
\*************/

int pregame(game_t *game);
int init_ui_pregame(game_t *game);
int init_button_pregame(game_t *game);
int events_pregame(game_t *game);
void draw_pregame(game_t *game);
void destroy_pregame(game_t *game);

/****************\
*   PAUSE MENU   *
\****************/

int pause_menu(game_t *game);
int init_ui_pause_menu(game_t *game);
int init_button_pause_menu(game_t *game);
int events_pause_menu(game_t *game);
void draw_pause_menu(game_t *game);
void destroy_pause_menu(game_t *game);

/**********\
*   GAME   *
\**********/

void *init_in_game(game_t *game);
int init_in_game_scene(game_t *game);
int create_character(game_t *game);
int create_utils_in_game(game_t *game);
int in_game(game_t *game);
void draw_in_game(game_t *game);
void destroy_in_game(game_t *game);
void select_skin(game_t *game);


/****************\
*   DRAW SCENE   *
\****************/

void (*select_draw_in_game[5])(game_t *game);
void draw_outside(game_t *game);
void draw_tavern(game_t *game);
void draw_seller(game_t *game);
void draw_cave(game_t *game);
void draw_dungeon(game_t *game);

/**********\
*   INIT   *
\**********/

int init_common_to_scenes(game_t *game);
int init_ui_outside(game_t *game);
int init_ui_tavern(game_t *game);
int init_ui_seller(game_t *game);
int init_ui_cave(game_t *game);
int init_ui_dungeon(game_t *game);
int init_outside_pnj(game_t *game);
int init_tavern_pnj(game_t *game);
int init_seller_pnj(game_t *game);
int init_cave_pnj(game_t *game);
int init_dungeon_pnj(game_t *game);

/***********\
*   EVENT   *
\***********/

int (*select_events_in_game[5])(game_t *game);
int events_in_game(game_t *game);
int event_keyboard(game_t *game);
int outside_events(game_t *game);
int tavern_events(game_t *game);
int seller_events(game_t *game);
int cave_events(game_t *game);
int dungeon_events(game_t *game);

/**************\
*   MOVEMENT   *
\**************/

void move_character(game_t *game, int x, int y);
void move_left(game_t *ga);
void move_right(game_t *ga);
void move_up(game_t *ga);
void move_down(game_t *ga);
void move_rect_player(game_t *ga);
void is_player_walking(game_t *game);
void move_up_cave(game_t *ga);
void move_down_cave(game_t *ga);
void move_up_dungeon(game_t *ga);
void move_down_dungeon(game_t *ga);

/***************\
*  FRAMEBUFFER  *
\***************/

int init_framebuffer(game_t *ga, int height, int width);
void put_pixel(fbf_t *buffer, int x, int y, sfColor color);
void restore_framebuffer(fbf_t *buffer);
void framebuffer_display(fbf_t *buffer, sfRenderWindow *w);
void framebuffer_destroy(fbf_t *buffer);


/**************\
*    HITBOX    *
\**************/

int init_hitbox(game_t *ga);
int init_box(box_t *obj, int x, int y, char *path);
void destroy_hitbox(game_t *ga);
int hitbox_player(game_t *ga, int direction);
int hitbox_effect(game_t *ga, int n_x, int n_y);
int hitbox_select_skin(game_t *ga);

#endif /* !PROTOTYPE_H_ */