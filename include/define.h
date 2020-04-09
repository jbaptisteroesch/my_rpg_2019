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

#define BLUE_MATCH h->player.box[y + c->rect.top][x + c->rect.left] & 4\
    && h->map.box[p.y + y][p.x + x] & 4

#define GREEN_MATCH h->player.box[y + c->rect.top][x + c->rect.left] & 2\
    && h->map.box[p.y + y][p.x + x] & 2

#define RED_MATCH h->player.box[y + c->rect.top][x + c->rect.left] & 1 \
    && h->map.box[p.y + y][p.x + x] & 1

#define OUT_OF_RANGE p.y + y < 0 || p.y + y >= h->map.dim.y || p.x + x < 0||\
    p.x + x >= h->map.dim.x || y + c->rect.top >= h->player.dim.y ||\
    x + c->rect.left >= h->player.dim.x

#endif /* !DEFINE_H_ */