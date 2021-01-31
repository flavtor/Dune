/*
** EPITECH PROJECT, 2021
** scene_f
** File description:
** scene_f
*/

#include "my.h"
#include "struct.h"
#include "game.h"

sfSprite *create_scene_1(void)
{
    sfTexture *textback;
    sfSprite *spriteback;

    textback = sfTexture_createFromFile("press/image/scene_1.jpg", NULL);
    if (!textback)
        return (NULL);
    spriteback = sfSprite_create();
    sfSprite_setTexture(spriteback, textback, sfTrue);
    return (spriteback);
}

void init_scene_f(game *ga)
{
     ga->scene_1 = sfMusic_createFromFile("other/music/scene_1.ogg");
     ga->meurtre = sfMusic_createFromFile("other/music/meurtre.ogg");
     ga->lame = sfMusic_createFromFile("other/music/lame.ogg");
     ga->spriteback = create_scene_1();
     sfMusic_play(ga->scene_1);
     sfMusic_play(ga->meurtre);
}

static void exit_(sfRenderWindow *window, game *ga, sfMusic *m)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        sfMusic_stop(m);
        hub(window, ga, -4225, -4265);
    }
}   

void scene_f(sfRenderWindow *window, game *ga)
{
     sfEvent ev;
     int a = 25;
     int b = 1;

     init_scene_f(ga);
     while (sfRenderWindow_isOpen(window)) {
         display_window(window, ga, ga->scene_1);
         if (b == 1) {
             b -= 1;
             sfMusic_play(ga->lame); 
         }
         if (a != 1) {
             a -=1;
             sfMusic_play(ga->meurtre);
         }
         
         exit_(window, ga, ga->scene_1);
         while (sfRenderWindow_pollEvent(window, &ev)) {
             if (ev.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeySpace))
                 sfRenderWindow_close(window);
         }
     }
     sfMusic_destroy(ga->lame);
     sfMusic_destroy(ga->meurtre);
     sfMusic_destroy(ga->scene_1);
     sfRenderWindow_close(window);
}
