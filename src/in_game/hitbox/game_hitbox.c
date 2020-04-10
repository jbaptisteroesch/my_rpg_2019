/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_hitbox
*/

#include "rpg.h"

int init_box(hitbox_t *hit, box_t *obj, sfVector2i pos, char *path)
{
    if (!obj) return (1);
    obj->m = sfImage_createFromFile(path);
    if (!obj->m) return (1);
    obj->pos = pos;
    obj->dim = sfImage_getSize(obj->m);
    obj->box = my_malloc_udb(obj->dim.y, obj->dim.x);
    if (!obj->box) return (1);
    hitbox_read_image(hit, obj);
    return (0);
}

int init_hitbox(game_t *ga)
{
    ga->hit.transparent = 0;
    ga->hit.pnj = 0;
    if (init_color(&ga->hit))
        return (1);
    if (init_box(&ga->hit, &ga->hit.map, (sfVector2i){0, 0},
    "media/Collisions/outside_collision.png"))
        return (1);
    return (0);
}

void destroy_hitbox(game_t *ga)
{
    my_free_typoo((void **)ga->hit.map.box);
    my_free_typoo((void **)ga->hit.player.box);
}