/*
** EPITECH PROJECT, 2021
** finale
** File description:
** finale
*/

#include "my.h"
#include "struct.h"
#include "game.h"

sfSprite *create_finale_1(void)
{
    sfTexture *textback;
    sfSprite *spriteback;

    textback = sfTexture_createFromFile("image/map/finale.jpg", NULL);
    if (!textback)
        return (NULL);
    spriteback = sfSprite_create();
    sfSprite_setTexture(spriteback, textback, sfTrue);
    return (spriteback);
}

sfSprite *create_player_2(game *ga)
{
    sfTexture *texture;
    sfSprite *sprite;
    char *filepath = "image/jotaro_s/jotaro.png";

    ga->jo_rect.left = 0;
    ga->jo_rect.top = 0;
    ga->jo_rect.width = 31;
    ga->jo_rect.height = 42;
    texture = sfTexture_createFromFile(filepath, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    ga->pos1.x = 930;
    ga->pos1.y = 960;
    sfSprite_setPosition(sprite, ga->pos1);
    sfSprite_setTextureRect(sprite, ga->jo_rect);
    return (sprite);
} 

void init_finale(game *ga)
{
    ga->finale_1 = sfMusic_createFromFile("music/finale_1.ogg");
    ga->di26 = create_dialog(ga, "image/dialogs/dialog26.png");
    ga->spriteback = create_finale_1();
    ga->s_jotaro = create_player_2(ga);
    ga->c_ta = create_clock();
    ga->s_monster1 = create_monster(490, 250);
    ga->c_monster1 = create_clock();
    ga->s_monster2 = create_monster(1000, 250);
    ga->c_monster2 = create_clock();
    ga->s_monster3 = create_monster(1420, 250);
    ga->c_monster3 = create_clock();
    ga->s_monster4 = create_monster(490, 720);
    ga->c_monster4 = create_clock();
    ga->s_monster5 = create_monster(1000, 720);
    ga->c_monster5 = create_clock();
    ga->s_monster6 = create_monster(1420, 720);
    ga->c_monster6 = create_clock();
    ga->xrect = 0;
    sfMusic_play(ga->finale_1); 
}

void move_jotaro_2(game *ga)
{
    sfVector2f a = {};
    sfVector2f b = {};

    if (obstacle_grotte(ga, a, b) == 1) {
        move_jotaro_up_down(ga);
        move_jotaro_left_right(ga);
    }
}

void scene_2(sfRenderWindow *w, game *ga, sfMusic *m)
{
    if (ga->pos1.x < 945 && ga->pos1.x > 895 && ga->pos1.y < 485 && ga->pos1.y > 415)
        sfRenderWindow_drawSprite(w, ga->di26, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && ga->pos1.x < 945 && ga->pos1.x > 895 && ga->pos1.y < 485 && ga->pos1.y > 415) {
        sfMusic_stop(m);
        scene_r(w, ga);
    }
}

void finale(sfRenderWindow *window, game *ga)
{
    sfEvent ev;
    
    init_finale(ga);
    while (sfRenderWindow_isOpen(window)) {
        display_window(window, ga, ga->finale_1);
        sfRenderWindow_drawSprite(window, ga->s_jotaro, NULL);
        sfRenderWindow_drawSprite(window, ga->life, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster1, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster2, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster3, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster4, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster5, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster6, NULL);
        move_all_monster2(ga);
        move_jotaro_2(ga);
        life_gestion(window, ga, ga->finale_1);
        monster_damages(ga, ga->s_monster1);
        monster_damages(ga, ga->s_monster2);
        monster_damages(ga, ga->s_monster3);
        monster_damages(ga, ga->s_monster4);
        monster_damages(ga, ga->s_monster5);
        monster_damages(ga, ga->s_monster6);
        scene_2(window, ga, ga->finale_1);
        printf("x = %f || y = %f\n", ga->pos1.x, ga->pos1.y);
        while (sfRenderWindow_pollEvent(window, &ev)) {
            if (ev.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeySpace))
                sfRenderWindow_close(window);
        }
    }
    sfSprite_destroy(ga->s_monster1);
    sfSprite_destroy(ga->s_monster2);
    sfSprite_destroy(ga->s_monster3);
    sfSprite_destroy(ga->s_monster4);
    sfSprite_destroy(ga->s_monster5);
    sfSprite_destroy(ga->s_monster6);
    sfClock_destroy(ga->c_monster1);
    sfClock_destroy(ga->c_monster2);
    sfClock_destroy(ga->c_monster3);
    sfClock_destroy(ga->c_monster4);
    sfClock_destroy(ga->c_monster5);
    sfClock_destroy(ga->c_monster6);
    sfMusic_destroy(ga->finale_1);
    sfRenderWindow_close(window);
}
