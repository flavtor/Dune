/*
** EPITECH PROJECT, 2021
** grotte
** File description:
** grotte
*/

#include "my.h"
#include "struct.h"
#include "game.h"

sfSprite *create_sprite_grotte(void)
{
    sfTexture *textback;
    sfSprite *spriteback;

    textback = sfTexture_createFromFile("press/image/map/donjon.jpg", NULL);
    if (!textback)
        return (NULL);
    spriteback = sfSprite_create();
    sfSprite_setTexture(spriteback, textback, sfTrue);
    return (spriteback);
}

void init_grotte_1(game *ga)
{
    ga->music_grotte_1 = sfMusic_createFromFile("other/music/donjon.ogg");
    ga->spriteback = create_sprite_grotte();
    ga->s_jotaro = create_player(ga);
    ga->c_ta = create_clock();
    ga->s_monster1 = create_monster(14, 63);
    ga->c_monster1 = create_clock();
    ga->s_monster2 = create_monster(423, 153);
    ga->c_monster2 = create_clock();
    ga->s_monster3 = create_monster(713, 732);
    ga->c_monster3 = create_clock();
    ga->s_monster4 = create_monster(1213, 72);
    ga->c_monster4 = create_clock();
    ga->s_monster5 = create_monster(1425, 851);
    ga->c_monster5 = create_clock();
    ga->s_monster6 = create_monster(1503, 396);
    ga->c_monster6 = create_clock();
    ga->xrect = 0;
    ga->di23 = create_dialog(ga, "press/image/dialogs/dialog19.png");
    sfMusic_play(ga->music_grotte_1);
}

void init_grotte_2(game *ga)
{
    ga->music_grotte_2 = sfMusic_createFromFile("other/music/donjon.ogg");
    ga->spriteback = create_sprite_grotte();
    ga->s_jotaro = create_player(ga);
    ga->c_ta = create_clock();
    ga->s_monster1 = create_monster(14, 63);
    ga->c_monster1 = create_clock();
    ga->s_monster2 = create_monster(423, 153);
    ga->c_monster2 = create_clock();
    ga->s_monster3 = create_monster(713, 732);
    ga->c_monster3 = create_clock();
    ga->s_monster4 = create_monster(1213, 72);
    ga->c_monster4 = create_clock();
    ga->s_monster5 = create_monster(1425, 851);
    ga->c_monster5 = create_clock();
    ga->s_monster6 = create_monster(1503, 396);
    ga->c_monster6 = create_clock();
    ga->xrect = 0;
    ga->di24 = create_dialog(ga, "press/image/dialogs/dialog20.png");
    sfMusic_play(ga->music_grotte_2);
}

void init_grotte_3(game *ga)
{
    ga->music_grotte_3 = sfMusic_createFromFile("other/music/donjon.ogg");
    ga->spriteback = create_sprite_grotte();
    ga->s_jotaro = create_player(ga);
    ga->c_ta = create_clock();
    ga->s_monster1 = create_monster(14, 63);
    ga->c_monster1 = create_clock();
    ga->s_monster2 = create_monster(423, 153);
    ga->c_monster2 = create_clock();
    ga->s_monster3 = create_monster(713, 732);
    ga->c_monster3 = create_clock();
    ga->s_monster4 = create_monster(1213, 72);
    ga->c_monster4 = create_clock();
    ga->s_monster5 = create_monster(1425, 851);
    ga->c_monster5 = create_clock();
    ga->s_monster6 = create_monster(1503, 396);
    ga->c_monster6 = create_clock();
    ga->xrect = 0;
    ga->di25 = create_dialog(ga, "press/image/dialogs/dialog23.png");
    sfMusic_play(ga->music_grotte_3);
} 

void move_jotaro_up_down(game *ga)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) && ga->pos1.y > 0) {
        if (ga->jo_rect.top != 126)
            ga->jo_rect.top = 126;
        ga->jo_rect.left += 30;
        if (ga->jo_rect.left >= 90)
            ga->jo_rect.left = 0;
        ga->pos1.y -= 5;
        sfSprite_setTextureRect(ga->s_jotaro, ga->jo_rect);
        sfSprite_setPosition(ga->s_jotaro, ga->pos1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && ga->pos1.y < 1000) {
        if (ga->jo_rect.top != 0)
            ga->jo_rect.top = 0;
        ga->jo_rect.left += 30;
        if (ga->jo_rect.left >= 90)
            ga->jo_rect.left = 0;
        ga->pos1.y += 5;
        sfSprite_setTextureRect(ga->s_jotaro, ga->jo_rect);
        sfSprite_setPosition(ga->s_jotaro, ga->pos1);
    }
}

void move_jotaro_left_right(game *ga)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && ga->pos1.x > 0) {
        if (ga->jo_rect.top != 42)
            ga->jo_rect.top = 42;
        ga->jo_rect.left += 30;
        if (ga->jo_rect.left >= 90)
            ga->jo_rect.left = 0;
        ga->pos1.x -= 5;
        sfSprite_setTextureRect(ga->s_jotaro, ga->jo_rect);
        sfSprite_setPosition(ga->s_jotaro, ga->pos1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && ga->pos1.x < 1890) {
        if (ga->jo_rect.top != 84)
            ga->jo_rect.top = 84;
        ga->jo_rect.left += 30;
        if (ga->jo_rect.left >= 90)
            ga->jo_rect.left = 0;
        ga->pos1.x += 5;
        sfSprite_setTextureRect(ga->s_jotaro, ga->jo_rect);
        sfSprite_setPosition(ga->s_jotaro, ga->pos1);
    }
}

int obstacle_grotte(game *ga, sfVector2f a, sfVector2f b)
{
    int i = 0;

    ga->pos1.x > a.x && !(ga->pos1.x > b.x) &&
        (ga->pos1.y > a.y && ga->pos1.y < b.y) ?
        (ga->pos1.x = b.x + 5) : i++;
    ga->pos1.x < b.x && !(ga->pos1.x < a.x) &&
        (ga->pos1.y > a.y && ga->pos1.y < b.y) ?
        (ga->pos1.x = a.x - 5) : i++;
    ga->pos1.y > a.y && !(ga->pos1.y > b.y) &&
        (ga->pos1.x > a.x && ga->pos1.x < b.x) ?
        (ga->pos1.y = b.y + 5) : i++;
    ga->pos1.y < b.y && !(ga->pos1.y < a.y) &&
        (ga->pos1.x > a.x && ga->pos1.x < b.x) ?
        (ga->pos1.y = a.y - 5) : i++;
    if (i == 4)
        return (1);
    return (0);
}

void move_jotaro(game *ga)
{
    sfVector2f a = {750, 130};
    sfVector2f b = {845, 185};

    if (obstacle_grotte(ga, a, b) == 1) {
        move_jotaro_up_down(ga);
        move_jotaro_left_right(ga);
    }
}

void exit_(sfRenderWindow *window, game *ga, sfMusic *m, int x, int y)
{
    if (ga->pos1.x < 950 && ga->pos1.x > 750 && ga->pos1.y == 1000) {
        sfMusic_stop(m);
        hub(window, ga, x, y);
    }
        
}

void grotte_1(sfRenderWindow *window, game *ga)
{
    sfEvent ev;
    
    init_grotte_1(ga);
    while (sfRenderWindow_isOpen(window)) {
        display_window(window, ga, ga->music_grotte_1);
        sfRenderWindow_drawSprite(window, ga->s_jotaro, NULL);
        sfRenderWindow_drawSprite(window, ga->life, NULL);
        sfRenderWindow_drawSprite(window, ga->s_jotaro, NULL);
        sfRenderWindow_drawSprite(window, ga->life, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster1, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster2, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster3, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster4, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster5, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster6, NULL);
        move_all_monster(ga);
        move_jotaro(ga);
        life_gestion(window, ga, ga->music_grotte_1);
        monster_damages(ga, ga->s_monster1);
        monster_damages(ga, ga->s_monster2);
        monster_damages(ga, ga->s_monster3);
        monster_damages(ga, ga->s_monster4);
        monster_damages(ga, ga->s_monster5);
        monster_damages(ga, ga->s_monster6); 
        exit_(window, ga, ga->music_grotte_1, 455, -2365);
        if (ga->pos1.x >= 760 && ga->pos1.x <= 840
            && ga->pos1.y >= 190 && ga->pos1.y <= 210)
            sfRenderWindow_drawSprite(window, ga->di23, NULL);
        while (sfRenderWindow_pollEvent(window, &ev)) {
            if (ev.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeySpace))
                sfRenderWindow_close(window);
        }
    }
    sfMusic_destroy(ga->music_grotte_1);
    sfRenderWindow_close(window);
}

void grotte_2(sfRenderWindow *window, game *ga)
{
    sfEvent ev;
    
    init_grotte_2(ga);
    while (sfRenderWindow_isOpen(window)) {
        display_window(window, ga, ga->music_grotte_2);
        sfRenderWindow_drawSprite(window, ga->s_jotaro, NULL);
        sfRenderWindow_drawSprite(window, ga->life, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster1, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster2, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster3, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster4, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster5, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster6, NULL);
        move_all_monster(ga);
        move_jotaro(ga);
        life_gestion(window, ga, ga->music_grotte_2);
        monster_damages(ga, ga->s_monster1);
        monster_damages(ga, ga->s_monster2);
        monster_damages(ga, ga->s_monster3);
        monster_damages(ga, ga->s_monster4);
        monster_damages(ga, ga->s_monster5);
        monster_damages(ga, ga->s_monster6);
        exit_(window, ga, ga->music_grotte_2, -4275, -4670);
        if (ga->pos1.x >= 760 && ga->pos1.x <= 840
            && ga->pos1.y >= 190 && ga->pos1.y <= 210)
            sfRenderWindow_drawSprite(window, ga->di24, NULL);
        while (sfRenderWindow_pollEvent(window, &ev)) {
            if (ev.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeySpace))
                sfRenderWindow_close(window);
        }
    }
    sfMusic_destroy(ga->music_grotte_2);
    sfRenderWindow_close(window);
}

void grotte_3(sfRenderWindow *window, game *ga)
{
    sfEvent ev;
    
    init_grotte_3(ga);
    while (sfRenderWindow_isOpen(window)) {
        display_window(window, ga, ga->music_grotte_3);
        sfRenderWindow_drawSprite(window, ga->s_jotaro, NULL);
        sfRenderWindow_drawSprite(window, ga->life, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster1, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster2, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster3, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster4, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster5, NULL);
        sfRenderWindow_drawSprite(window, ga->s_monster6, NULL);
        move_all_monster(ga);
        move_jotaro(ga);
        life_gestion(window, ga, ga->music_grotte_3);
        monster_damages(ga, ga->s_monster1);
        monster_damages(ga, ga->s_monster2);
        monster_damages(ga, ga->s_monster3);
        monster_damages(ga, ga->s_monster4);
        monster_damages(ga, ga->s_monster5);
        monster_damages(ga, ga->s_monster6);
        exit_(window, ga, ga->music_grotte_3, -3985, -1310);
        if (ga->pos1.x >= 760 && ga->pos1.x <= 840
            && ga->pos1.y >= 190 && ga->pos1.y <= 210)
            sfRenderWindow_drawSprite(window, ga->di25, NULL);
        while (sfRenderWindow_pollEvent(window, &ev)) {
            if (ev.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeySpace))
                sfRenderWindow_close(window);
        }
    }
    sfMusic_destroy(ga->music_grotte_3);
    sfRenderWindow_close(window);
}
