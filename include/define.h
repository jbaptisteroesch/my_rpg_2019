/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** define
*/

#ifndef DEFINE_H_
#define DEFINE_H_

/************************\
*   RECURRENT ELEMENTS   *
\************************/

#define WINDOW game->window->window

/************\
*   EVENTS   *
\************/

#define MOUSE_CLICK game->window->event.type == sfEvtMouseButtonPressed
#define MOUSE_RELEASED game->window->event.type == sfEvtMouseButtonReleased
#define GET_MOUSE_POS game->mouse_position = \
                        sfMouse_getPositionRenderWindow(game->window->window)

/*******************************\
*   REWRITE TOO LONG FUNCTION   *
\*******************************/

#define sfSprite_getPos sfSprite_getPosition
#define drawSprite sfRenderWindow_drawSprite

/************\
*    MOUSE   *
\************/

#define MOUSEX game->mouse_position.x
#define MOUSEY game->mouse_position.y

/************\
*   HITBOX   *
\************/

#define RED_MATCH (map & 128 && player & 128)

#define GREEN_MATCH (map & 64 && player & 64)

#define BLUE_MATCH (map & 32 && player & 32)

#define LOW_BLUE_MATCH (map == 1 && player & 128)

#define SCENE_MATCH map == i && player & 32

#define INTERACTION_MATCH map == 7 && player & 128

#define PLAYER_PIXEL h->player.box[y + c->rect.top][x + c->rect.left]
#define MAP_PIXEL h->map.box[p.y + y][p.x + x]

#define OUT_OF_RANGE p.y + y < 0 || p.y + y >= h->map.dim.y || p.x + x < 0||\
    p.x + x >= h->map.dim.x || y + c->rect.top >= h->player.dim.y ||\
    x + c->rect.left >= h->player.dim.x

#endif /* !DEFINE_H_ */