/*
** EPITECH PROJECT, 2021
** final_fight
** File description:
** final_fight
*/

#include "my.h"
#include "struct.h"
#include "game.h"

void move_hero_left_right(game *ga)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && ga->pos2.x > 0) {
        if (ga->jo_rect.top != 42)
            ga->jo_rect.top = 42;
        ga->jo_rect.left += 30;
        if (ga->jo_rect.left >= 90)
            ga->jo_rect.left = 0;
        ga->pos2.x -= 5;
        sfSprite_setTextureRect(ga->s_hero, ga->jo_rect);
        sfSprite_setPosition(ga->s_hero, ga->pos2);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && ga->pos2.x < 1890) {
        if (ga->jo_rect.top != 84)
            ga->jo_rect.top = 84;
        ga->jo_rect.left += 30;
        if (ga->jo_rect.left >= 90)
            ga->jo_rect.left = 0;
        ga->pos2.x += 5;
        sfSprite_setTextureRect(ga->s_hero, ga->jo_rect);
        sfSprite_setPosition(ga->s_hero, ga->pos2);
    }
}

void move_hero_up_down(game *ga)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) && ga->pos2.y > 0) {
        if (ga->jo_rect.top != 126)
            ga->jo_rect.top = 126;
        ga->jo_rect.left += 30;
        if (ga->jo_rect.left >= 90)
            ga->jo_rect.left = 0;
        ga->pos2.y -= 5;
        sfSprite_setTextureRect(ga->s_hero, ga->jo_rect);
        sfSprite_setPosition(ga->s_hero, ga->pos2);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && ga->pos2.y < 1000) {
        if (ga->jo_rect.top != 0)
            ga->jo_rect.top = 0;
        ga->jo_rect.left += 30;
        if (ga->jo_rect.left >= 90)
            ga->jo_rect.left = 0;
        ga->pos2.y += 5;
        sfSprite_setTextureRect(ga->s_hero, ga->jo_rect);
        sfSprite_setPosition(ga->s_hero, ga->pos2);
    }
}

sfSprite *create_hero(game *ga)
{
    sfTexture *texture;
    sfSprite *sprite;
    char *filepath = "image/jotaro_s/hero.png";

    ga->jo_rect.left = 0;
    ga->jo_rect.top = 0;
    ga->jo_rect.width = 31;
    ga->jo_rect.height = 42;
    texture = sfTexture_createFromFile(filepath, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    ga->pos2.x = 960;
    ga->pos2.y = 540;
    sfSprite_setPosition(sprite, ga->pos1);
    sfSprite_setTextureRect(sprite, ga->jo_rect);
    return (sprite);
}

sfSprite *create_final_2(void)
{
    sfTexture *textback;
    sfSprite *spriteback;

    textback = sfTexture_createFromFile("image/fight.jpg", NULL);
    if (!textback)
        return (NULL);
    spriteback = sfSprite_create();
    sfSprite_setTexture(spriteback, textback, sfTrue);
    return (spriteback);
}

void init_final_fight(game *ga)
{
    ga->finale_2 = sfMusic_createFromFile("music/finale_2.ogg");
    ga->spriteback = create_final_2();
    ga->s_jotaro = create_player(ga);
    ga->s_hero = create_hero(ga);
    ga->c_ta = create_clock();
    sfMusic_play(ga->finale_2);
} 

void move_hero(game *ga)
{
    sfVector2f a = {750, 130};
    sfVector2f b = {845, 185};

    if (obstacle_grotte(ga, a, b) == 1) {
        move_hero_up_down(ga);
        move_hero_left_right(ga);
    }
}

void final_fight(sfRenderWindow *window, game *ga)
{
    sfEvent ev;

    init_final_fight(ga);
    while (sfRenderWindow_isOpen(window)) {
        display_window(window, ga, ga->finale_2);
        sfRenderWindow_drawSprite(window, ga->s_jotaro, NULL);
        sfRenderWindow_drawSprite(window, ga->s_hero, NULL);
        move_jotaro_zomb(ga, 5, 15);
        move_hero(ga);
        //move_player(ga);
        // exit_(window, ga, ga->final_2);
        while (sfRenderWindow_pollEvent(window, &ev)) {
            if (ev.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeySpace))
                sfRenderWindow_close(window);
        }
    }
    sfMusic_destroy(ga->finale_2);
    sfRenderWindow_close(window);
}
