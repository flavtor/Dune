/*
** EPITECH PROJECT, 2021
** winner
** File description:
** winner
*/


#include "my.h"
#include "struct.h"
#include "game.h"

sfMusic *win_music(void)
{
    sfMusic *music;

    music = sfMusic_createFromFile("other/music/win.ogg");
    if (!music)
        return (NULL);
    sfMusic_play(music);
    return (music);
}

sfSprite *display_win(void)
{
    sfTexture *texture;
    sfSprite *w_over;

    texture = sfTexture_createFromFile("press/image/background/win.png", NULL);
    if (!texture)
        return (NULL);
    w_over = sfSprite_create();
    sfSprite_setTexture(w_over, texture, sfTrue);
    return (w_over);
}

void win(sfRenderWindow *win, game *ga)
{
    sfSprite *winn = display_win();
    sfMusic *w_music = win_music();
    sfEvent ev;

    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_display(win);
        sfRenderWindow_drawSprite(win, winn, NULL);
        while (sfRenderWindow_pollEvent(win, &ev)) {
            if (ev.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeySpace))
                sfRenderWindow_close(win);
        }
    }
    sfMusic_destroy(w_music);
    sfSprite_destroy(winn);
    sfRenderWindow_close(win);
}

