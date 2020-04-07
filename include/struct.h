/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>

/************\
*   WINDOW   *
\************/

typedef struct s_window
{
    sfVector2f scale;
    sfEvent event;
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfTexture *texture;
    sfSprite *sprite;
    int pos;
} window_t;


/*************\
*   ELEMENT   *
\*************/

typedef struct elem_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f set_position;
    sfVector2f get_position;
    sfIntRect rect;
    bool is_display;
    bool gen_action;
} elem_t;

typedef struct ennemy_s
{
    elem_t *ennemy;
    struct ennemy_s *next;
} ennemy_t;


/************\
*     UI     *
\************/

typedef struct button_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    bool is_hover;
} button_t;

typedef struct string_s
{
    sfText *string;
    sfFont *font;
    sfColor color;
    sfVector2f place_string;
} string_t;


typedef struct rectangle_s
{
    sfRectangleShape *rect;
    sfVector2f rect_size;
    sfVector2f rect_position;
    sfColor color;
    bool is_hover;
} rectangle_t;

typedef struct menu_s
{
    elem_t *ui_scene;
    button_t *buttons;
    string_t *texts;
    rectangle_t *rectangle;
} menu_t;

/***********\
*   SCENE   *
\***********/

typedef struct scene_s
{
    elem_t *ui_scene;
    string_t *texts;
    elem_t *pnj;
    ennemy_t *ennemys;
    sfSoundBuffer **sbuffer;
    sfSound **sounds;
}scene_t;

/************\
*  SETTINGS  *
\************/

typedef struct settings_s
{
    bool is_music_on;
    int music_volume;
} settings_t;

/************\
*   PLAYER   *
\************/

typedef struct player_s
{
    int experience;
    int level;
    int gold;
    elem_t *inventory;
    elem_t character;
    elem_t pl_not_op;
    int is_walking;
    int type;
    int is_on_scene;
}player_t;


/***************\
*  FRAMEBUFFER  *
\***************/

typedef struct fbf_s
{
    sfVector2u size;
    sfSprite *sprite;
    sfTexture *texture;
    sfUint8 *pixels;
}fbf_t;


/************\
*   HITBOX   *
\************/

typedef struct box_s
{
    sfImage *m;
    sfVector2i pos;
    sfVector2u dim;
    unsigned char **box;
}box_t;

typedef struct hitbox_s
{
    box_t map;
    box_t player;
    int bool_display;
}hitbox_t;


/************\
*    GAME    *
\************/

typedef struct game_s
{
    window_t *window;
    fbf_t buffer;
    menu_t *menu;
    scene_t *game_scenes;
    elem_t *common_to_scenes;
    player_t player;
    settings_t settings;
    sfClock *clock;
    sfTime time;
    sfMusic *music;
    sfVector2i mouse_position;
    bool game_is_up;
    int *game_state;
    hitbox_t hit;
}game_t;

#endif /* !STRUCT_H_ */