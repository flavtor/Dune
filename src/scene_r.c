/*
** EPITECH PROJECT, 2021
** scene_r
** File description:
** scene_r
*/

#include "my.h"
#include "struct.h"
#include "game.h"

sfSprite *create_scene_2(void)
{
    sfTexture *textback;
    sfSprite *spriteback;

    textback = sfTexture_createFromFile("press/image/scene_2.jpg", NULL);
    if (!textback)
        return (NULL);
    spriteback = sfSprite_create();
    sfSprite_setTexture(spriteback, textback, sfTrue);
    return (spriteback);
}

void init_scene_r(game *ga)
{
    ga->scene_2 = sfMusic_createFromFile("other/music/scene_2.ogg");
    ga->spriteback = create_scene_2();
    sfMusic_play(ga->scene_2);
}

static void exit_(sfRenderWindow *window, game *ga, sfMusic *m)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        sfMusic_stop(m);
        final_fight(window, ga);
    }
}

void scene_r(sfRenderWindow *window, game *ga)
{
    sfEvent ev;

    init_scene_r(ga);
    while (sfRenderWindow_isOpen(window)) {
        display_window(window, ga, ga->scene_2);
        exit_(window, ga, ga->scene_2);
        while (sfRenderWindow_pollEvent(window, &ev)) {
            if (ev.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeySpace))
                sfRenderWindow_close(window);
        }
    }
    sfMusic_destroy(ga->scene_2);
    sfRenderWindow_close(window);
}
