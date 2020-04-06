/*
** EPITECH PROJECT, 2019
** MUL_my_radar_2019
** File description:
** framebuffer
*/

#include "rpg.h"

int init_framebuffer(game_t *ga, int height, int width)
{
    ga->buffer.size = (sfVector2u){width, height};
    ga->buffer.pixels = malloc(sizeof(sfUint8) * (width * height) * 4);
    ga->buffer.sprite = sfSprite_create();
    ga->buffer.texture = sfTexture_create(width, height);
    if (!ga->buffer.pixels || !ga->buffer.sprite || !ga->buffer.texture)
        return (1);
    restore_framebuffer(&ga->buffer);
    return (0);
}

void put_pixel(fbf_t *buffer, int x, int y, sfColor color)
{
    int i = 4 * buffer->size.x * y + x * 4;

    if (x < buffer->size.x && x > 0 && y < buffer->size.y && y > 0) {
        buffer->pixels[i] = color.r;
        buffer->pixels[i + 1] = color.g;
        buffer->pixels[i + 2] = color.b;
        buffer->pixels[i + 3] = color.a;
    }
}

void restore_framebuffer(fbf_t *buffer)
{
    for (int e = 0; e < buffer->size.x * buffer->size.y * 4; e += 4) {
        buffer->pixels[e] = 0;
        buffer->pixels[e + 1] = 0;
        buffer->pixels[e + 2] = 0;
        buffer->pixels[e + 3] = 0;
    }
}

void framebuffer_display(fbf_t *buffer, sfRenderWindow *w)
{
    // restore_framebuffer(buffer);
    sfTexture_updateFromPixels(buffer->texture, buffer->pixels,
    buffer->size.x, buffer->size.y, 0, 0);
    sfSprite_setTexture(buffer->sprite, buffer->texture, sfFalse);
    sfRenderWindow_drawSprite(w, buffer->sprite, NULL);
}

void framebuffer_destroy(fbf_t *buffer)
{
    free(buffer->pixels);
    free(buffer);
}