/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hitbox_read_image
*/

#include "rpg.h"

static int color_compare(sfColor o, sfColor t)
{
    if (o.r == t.r && o.g == t.g && o.b == t.b)
        return (1);
    return (0);
}

static void pixel_read(hitbox_t *hit, box_t *obj, int y, int x)
{
    sfColor c = sfImage_getPixel(obj->m, x, y);

    obj->box[y][x] = 0;
    if (c.r == 255)
        obj->box[y][x] |= 128;
    if (c.g == 255)
        obj->box[y][x] |= 64;
    if (c.b == 255)
        obj->box[y][x] |= 32;
    for (u_int8_t i = 0; i < hit->ic_c; ++i)
        if (color_compare(c, hit->color[i]))
            obj->box[y][x] = i + 1;
}

void hitbox_read_image(hitbox_t *hit, box_t *obj)
{
    for (int y = 0; y < obj->dim.y; ++y) {
        for (int x = 0; x < obj->dim.x; ++x) {
            pixel_read(hit, obj, y, x);
        }
    }
    sfImage_destroy(obj->m);
}