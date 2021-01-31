/*
** EPITECH PROJECT, 2021
** ggj
** File description:
** ggj
*/

#include "my.h"
#include "struct.h"
#include "game.h"

sfClock *create_clock(void)
{
    sfClock *c_clock;

    c_clock = sfClock_create();
    return (c_clock);
}

sfSprite *life(sfSprite *life, game *ga)
{
    sfTexture *texture;

    ga->rect_l.left = 0;
    ga->rect_l.top = 0;
    ga->rect_l.width = 547;
    ga->rect_l.height = 84;
    texture = sfTexture_createFromFile("press/image/life.png", NULL);
    if (!texture)
        return (NULL);
    life = sfSprite_create();
    sfSprite_setTexture(life, texture, sfTrue);
    sfSprite_setTextureRect(life, ga->rect_l);
    return (life);
} 

sfSprite *hub_background(void)
{
    sfTexture* texture;
    sfSprite* menu_background;

    texture = sfTexture_createFromFile("press/image/map/Image.jpg", NULL);
    if (!texture)
        return (NULL);
    menu_background = sfSprite_create();
    sfSprite_setTexture(menu_background, texture, sfTrue);
    return (menu_background);
}

sfMusic *hub_music(void)
{
    sfMusic *music;

    music = sfMusic_createFromFile("other/music/map.ogg");
    if (!music)
        return (NULL);
    sfMusic_play(music);
    return (music);
}

void hub_init(game *ga)
{
    ga->spriteback = hub_background();
    ga->s_jotaro = create_player(ga);
    ga->c_ta = create_clock();
    ga->xrect = 0;
    ga->vie = 5;
    ga->life = life(ga->life, ga);
}

void init_dialogs(sfRenderWindow *w, game *ga)
{
    ga->di1 = create_dialog(ga, "press/image/dialogs/dialog1.png");
    ga->di2 = create_dialog(ga, "press/image/dialogs/dialog2.png");
    ga->di3 = create_dialog(ga, "press/image/dialogs/dialog7.png");
    ga->di4 = create_dialog(ga, "press/image/dialogs/dialog3.png");
    ga->di5 = create_dialog(ga, "press/image/dialogs/dialog5.png");
    ga->di6 = create_dialog(ga, "press/image/dialogs/dialog6.png");
    ga->di7 = create_dialog(ga, "press/image/dialogs/dialog21.png");
    ga->di8 = create_dialog(ga, "press/image/dialogs/dialog8.png");
    ga->di9 = create_dialog(ga, "press/image/dialogs/dialog9.png");
    ga->di10 = create_dialog(ga, "press/image/dialogs/dialog10.png");
    ga->di11 = create_dialog(ga, "press/image/dialogs/dialog11.png");
    ga->di12 = create_dialog(ga, "press/image/dialogs/dialog12.png");
    ga->di13 = create_dialog(ga, "press/image/dialogs/dialog13.png");
    ga->di14 = create_dialog(ga, "press/image/dialogs/dialog14.png");
    ga->di15 = create_dialog(ga, "press/image/dialogs/dialog15.png");
    ga->di16 = create_dialog(ga, "press/image/dialogs/dialog16.png");
    ga->di17 = create_dialog(ga, "press/image/dialogs/dialog17.png");
    ga->di18 = create_dialog(ga, "press/image/dialogs/dialog18.png");
    ga->di19 = create_dialog(ga, "press/image/dialogs/dialog18.png");
    ga->di20 = create_dialog(ga, "press/image/dialogs/dialog18.png");
    ga->di21 = create_dialog(ga, "press/image/dialogs/dialog4.png");
    ga->di22 = create_dialog(ga, "press/image/dialogs/dialog22.png");
}

void dialogs(sfRenderWindow *w, game *ga)
{
    if (ga->pos.x == 660 && ga->pos.y == -3695)
        sfRenderWindow_drawSprite(w, ga->di1, NULL);
    if (ga->pos.x >= 150 && ga->pos.x <= 190
        && ga->pos.y >= -4120 && ga->pos.y <= -4070)
        sfRenderWindow_drawSprite(w, ga->di2, NULL);
    if (ga->pos.x >= -3650 && ga->pos.x <= -3600
        && ga->pos.y >= -3985 && ga->pos.y <= -3925)
        sfRenderWindow_drawSprite(w, ga->di3, NULL);
    if (ga->pos.x >= -3425 && ga->pos.x <= -3375
        && ga->pos.y >= -4545 && ga->pos.y <= -4485)
        sfRenderWindow_drawSprite(w, ga->di4, NULL);
    if (ga->pos.x >= -3940 && ga->pos.x <= -3880
        && ga->pos.y >= -4530 && ga->pos.y <= -4480)
        sfRenderWindow_drawSprite(w, ga->di5, NULL);
    if (ga->pos.x >= -4385 && ga->pos.x <= -4335
        && ga->pos.y >= -4245 && ga->pos.y <= -4185)
        sfRenderWindow_drawSprite(w, ga->di6, NULL);
    if (ga->pos.x >= -4475 && ga->pos.x <= -4435
        && ga->pos.y >= -3990 && ga->pos.y <= -3940)
        sfRenderWindow_drawSprite(w, ga->di7, NULL);
    if (ga->pos.x >= -2100 && ga->pos.x <= -2050
        && ga->pos.y >= -2360 && ga->pos.y <= -2310)
        sfRenderWindow_drawSprite(w, ga->di8, NULL);
    if (ga->pos.x >= -1815 && ga->pos.x <= -1765
        && ga->pos.y >= -2345 && ga->pos.y <= -2285)
        sfRenderWindow_drawSprite(w, ga->di9, NULL);
    if (ga->pos.x >= -1080 && ga->pos.x <= -1030
        && ga->pos.y >= -2465 && ga->pos.y <= -2415)
        sfRenderWindow_drawSprite(w, ga->di10, NULL);
    if (ga->pos.x >= -1825 && ga->pos.x <= -1770
        && ga->pos.y >= -1380 && ga->pos.y <= -1330)
        sfRenderWindow_drawSprite(w, ga->di11, NULL);
    if (ga->pos.x >= -2100 && ga->pos.x <= -2050
        && ga->pos.y >= -1380 && ga->pos.y <= -1330)
        sfRenderWindow_drawSprite(w, ga->di12, NULL);
    if (ga->pos.x >= -605 && ga->pos.x <= -555
        && ga->pos.y >= -820 && ga->pos.y <= -770)
        sfRenderWindow_drawSprite(w, ga->di13, NULL);
    if (ga->pos.x >= -490 && ga->pos.x <= -440
        && ga->pos.y >= -335 && ga->pos.y <= -285)
        sfRenderWindow_drawSprite(w, ga->di14, NULL);
    if (ga->pos.x >= -475 && ga->pos.x <= -425
        && ga->pos.y >= 55 && ga->pos.y <= 155)
        sfRenderWindow_drawSprite(w, ga->di15, NULL);
    if (ga->pos.x >= 350 && ga->pos.x <= 400
        && ga->pos.y >= 25 && ga->pos.y <= 85)
        sfRenderWindow_drawSprite(w, ga->di16, NULL);
    if (ga->pos.x >= 600 && ga->pos.x <= 650
        && ga->pos.y >= -745 && ga->pos.y <= -695)
        sfRenderWindow_drawSprite(w, ga->di17, NULL);
    if (ga->pos.x >= 360 && ga->pos.x <= 410
        && ga->pos.y >= -2385 && ga->pos.y <= -2325)
        sfRenderWindow_drawSprite(w, ga->di18, NULL);
    if (ga->pos.x >= -4305 && ga->pos.x <= -4255
        && ga->pos.y >= -4700 && ga->pos.y <= -4650)
        sfRenderWindow_drawSprite(w, ga->di19, NULL);
    if (ga->pos.x >= -3980 && ga->pos.x <= -3930
        && ga->pos.y >= -1340 && ga->pos.y <= -1290)
        sfRenderWindow_drawSprite(w, ga->di20, NULL);
    if (ga->pos.x >= -3930 && ga->pos.x <= -3880
        && ga->pos.y >= -4195 && ga->pos.y <= -4145)
        sfRenderWindow_drawSprite(w, ga->di21, NULL);
    if (ga->pos.x >= -3215 && ga->pos.x <= -3155
        && ga->pos.y >= -130 && ga->pos.y <= -80)
        sfRenderWindow_drawSprite(w, ga->di22, NULL);
}

void grotte(sfRenderWindow *w, game *ga, sfMusic *music)
{
    if (ga->pos.x < 405 && ga->pos.x > 375 && ga->pos.y < -2315 && ga->pos.y > -2345) {
        sfMusic_stop(music);
        grotte_1(w, ga);
    }
    if (ga->pos.x < -4225 && ga->pos.x > -4265 && ga->pos.y < -4620 && ga->pos.y > -4650) {
        sfMusic_stop(music);
        grotte_2(w, ga);
    }
    if (ga->pos.x < -3935 && ga->pos.x > -3975 && ga->pos.y < -1260 && ga->pos.y > -1305) {
        sfMusic_stop(music);
        grotte_3(w, ga);
    }
}

void map_finale(sfRenderWindow *w, game *ga, sfMusic *music)
{
    if (sfKeyboard_isKeyPressed(sfKeyH) && ga->pos.x < 40 && ga->pos.x > -25 && ga->pos.y < -805 && ga->pos.y > -845) { 
        sfMusic_stop(music);
        finale(w, ga);
    }
}

void life_gestion(sfRenderWindow *window, game *ga, sfMusic *m)
{
    sfSprite_setPosition(ga->life, (sfVector2f){1350, 0});
    if (ga->vie == 4)
        ga->rect_l.top = 104;
    if (ga->vie == 3)
        ga->rect_l.top = 211;
    if (ga->vie == 2)
        ga->rect_l.top = 318;
    if (ga->vie == 1)
        ga->rect_l.top = 425;
    if (ga->vie == 0) {
        sfMusic_stop(m);
        game_over(window);
    }
    sfSprite_setTextureRect(ga->life, ga->rect_l);
}

void scene_1(sfRenderWindow *w, game *ga, sfMusic *m)
{
    if (ga->pos.x < -4200 && ga->pos.x > -4245 && ga->pos.y == -4215) {
        sfMusic_stop(m);
        scene_f(w, ga);
    }
}

void hub(sfRenderWindow *w, game *ga, float x, float y)
{
    sfEvent ev;
    sfMusic *music = hub_music();
    
    hub_init(ga);
    init_dialogs(w, ga);
    ga->pos.x = x;
    ga->pos.y = y;
    sfSprite_setPosition(ga->spriteback, ga->pos);
    while (sfRenderWindow_isOpen(w)) {
        display_window(w, ga, music);
        sfRenderWindow_drawSprite(w, ga->s_jotaro, NULL);
        sfRenderWindow_drawSprite(w, ga->life, NULL);
        dialogs(w, ga);
        move_player(ga);
        grotte(w, ga, music);
        life_gestion(w, ga, music);
        scene_1(w, ga, music);
        map_finale(w, ga, music);
        while (sfRenderWindow_pollEvent(w, &ev))
            if (ev.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeySpace))
                sfRenderWindow_close(w);
    }
    sfMusic_destroy(music);
    sfRenderWindow_close(w); 
}
