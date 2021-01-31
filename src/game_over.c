
/*
** EPITECH PROJECT, 2021
** game_over.c
** File description:
** game_over
*/

#include "my.h"
#include "struct.h"
#include "game.h"

static void o_event(sfRenderWindow *win, sfEvent ev, sfMusic *m)
{
    sfVector2f yes_rgt = {854, 720};
    sfVector2f yes_lft = {893, 752};
    sfVector2f no_rgt = {982, 720};
    sfVector2f no_lft = {1021, 752};
    sfVector2i mouse;

    mouse.x = sfMouse_getPositionRenderWindow(win).x;
    mouse.y = sfMouse_getPositionRenderWindow(win).y;
    if (mouse.x >= yes_rgt.x && mouse.y >= yes_rgt.y
        && mouse.x <= yes_lft.x && mouse.y <= yes_lft.y) {
        if (ev.type == sfEvtMouseButtonPressed) {
            sfMusic_stop(m);
            launch_menu(win);
        }
    } if (mouse.x >= no_rgt.x && mouse.y >= no_rgt.y
          && mouse.x <= no_lft.x && mouse.y <= no_lft.y) {
        if (ev.type == sfEvtMouseButtonPressed) {
            sfRenderWindow_close(win);
        }
    }
} 

sfSprite *display_over(void)
{
    sfTexture *texture;
    sfSprite *g_over;

    texture = sfTexture_createFromFile("press/image/over.png", NULL);
    if (!texture)
        return (NULL);
    g_over = sfSprite_create();
    sfSprite_setTexture(g_over, texture, sfTrue);
    return (g_over);
}

sfMusic *over_music(void)
{
    sfMusic *music;

    music = sfMusic_createFromFile("other/music/over.ogg");
    if (!music)
        return (NULL);
    sfMusic_play(music);
    return (music);
}

void game_over(sfRenderWindow *win)
{
    sfSprite *over = display_over();
    sfMusic *o_music = over_music();
    sfEvent ev;

    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_display(win);
        sfRenderWindow_drawSprite(win, over, NULL);
        while (sfRenderWindow_pollEvent(win, &ev)) {
            if (ev.type == sfEvtClosed)
                sfRenderWindow_close(win);
            o_event(win, ev, o_music);
        }
    }
    sfMusic_destroy(o_music);
    sfSprite_destroy(over);
    sfRenderWindow_close(win);
}
