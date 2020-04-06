/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_hitbox
*/

#include "rpg.h"

static void hitbox_read_image(box_t *obj)
{
    sfColor c;

    for (int y = 0; y < obj->dim.y; ++y) {
        for (int x = 0; x < obj->dim.x; ++x) {
            c = sfImage_getPixel(obj->m, x, y);
            obj->box[y][x] = 0;
            if (c.r == 255)
                obj->box[y][x] |= 1;
            if (c.g == 255)
                obj->box[y][x] |= 2;
            if (c.b == 255)
                obj->box[y][x] |= 4;
        }
    }
    sfImage_destroy(obj->m);
}

int init_box(box_t *obj, int x, int y, char *path)
{
    if (!obj) return (1);
    obj->m = sfImage_createFromFile(path);
    if (!obj->m) return (1);
    obj->pos.x = x;
    obj->pos.y = y;
    obj->dim = sfImage_getSize(obj->m);
    obj->box = my_malloc_udb(obj->dim.y, obj->dim.x);
    if (!obj->box) return (1);
    hitbox_read_image(obj);
    return (0);
}

int init_hitbox(game_t *ga)
{
    ga->hit.bool_display = 1;
    if (init_box(&ga->hit.map, 0, 0, "media/Collisions/outside_collision.png"))
        return (1);
    if (hitbox_select_skin(ga))
        return (1);
    return (0);
}

void destroy_hitbox(game_t *ga)
{
    my_free_typoo((void **)ga->hit.map.box);
    my_free_typoo((void **)ga->hit.player.box);
}