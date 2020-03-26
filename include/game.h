/*
** EPITECH PROJECT, 2020
** rpg project
** File description:
** game struct
*/

#include "my.h"

#ifndef GAME_H_
#define GAME_H_

typedef struct scene_s
{
    elem_t *ui_scene;
    button_t *buttons;
    string_t *texts;
    elem_t *pnj;
    ennemy_t *ennemys;
    sfSoundBuffer **sbuffer;
    sfSound **sounds;
} scene_t;

typedef struct player_s
{
    int experience;
    int level;
    int gold;
    elem_t *inventory;
} player_t;

typedef struct game_s
{
    window_t *window;
    menu_t *menu;
    scene_t *game_scenes;
    player_t player;
    clock_t *clock;
    sfTime time;
    sfMusic *music;
    sfVector2i mouse_position;
    bool game_is_up;
    int *game_state;
    //? JUSTE POSER ICI POUR LE TEST
    elem_t character;
} game_t;

#endif /* !GAME_H_ */
