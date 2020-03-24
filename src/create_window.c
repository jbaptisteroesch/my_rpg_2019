/*
** EPITECH PROJECT, 2020
** defender Project
** File description:
** create window
*/

#include "../include/my.h"

window_t *create_window(window_t *window, char *title)
{
    sfVideoMode mode = {1920, 1080, 32};
    window->video_mode = mode;
    window->texture = sfTexture_createFromFile(
                                    "png/background_img/BGMainMenu.png", NULL);
    window->sprite = sfSprite_create();
    window->window = sfRenderWindow_create(window->video_mode,
                                            title,
                                            sfFullscreen,
                                            NULL);
    sfRenderWindow_setFramerateLimit(window->window, 60);
    sfSprite_setTexture(window->sprite, window->texture, sfTrue);
    return (window);
}