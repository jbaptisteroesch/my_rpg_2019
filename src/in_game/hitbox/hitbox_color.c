/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hitbox_color
*/

#include "rpg.h"

int init_color(hitbox_t *hit)
{
    hit->ic_c = 7;
    hit->color = malloc(sizeof(sfColor) * hit->ic_c);

    if (!hit->color) return (1);
    hit->color[OUTSIDE] = (sfColor){203, 203, 203, 255};
    hit->color[TAVERN] = (sfColor){213, 213, 213, 255};
    hit->color[SELLER] = (sfColor){223, 223, 223, 255};
    hit->color[CAVE] = (sfColor){243, 243, 243, 255};
    hit->color[DUNGEON] = (sfColor){253, 253, 253, 255};
    hit->color[LOW_BLUE] = (sfColor){42, 200, 254, 255};
    hit->color[PNJ] = (sfColor){198, 199, 200, 255};
    return (0);
}