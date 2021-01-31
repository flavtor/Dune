/*
** EPITECH PROJECT, 2021
** move
** File description:
** move
*/

#include "my.h"
#include "struct.h"
#include "game.h"

int obstacle_gestion(game *ga, sfVector2f a, sfVector2f b)
{
    int i = 0;

    ga->pos.x < a.x && !(ga->pos.x < b.x) &&
        (ga->pos.y < a.y && ga->pos.y > b.y) ?
        (ga->pos.x = b.x - 5) : i++;
    ga->pos.x > b.x && !(ga->pos.x > a.x) &&
        (ga->pos.y < a.y && ga->pos.y > b.y) ?
        (ga->pos.x = a.x + 5) : i++;
    ga->pos.y < a.y && !(ga->pos.y < b.y) &&
        (ga->pos.x < a.x && ga->pos.x > b.x) ?
        (ga->pos.y = b.y - 5) : i++;
    ga->pos.y > b.y && !(ga->pos.y > a.y) &&
        (ga->pos.x < a.x && ga->pos.x > b.x) ?
        (ga->pos.y = a.y + 5) : i++;
    if (i == 4)
        return (1);
    return (0);
}

int obstacle(game *ga)
{
    sfVector2f a = {370, -3550};
    sfVector2f b = {-5, -3915};
    sfVector2f c = {845, -1750};
    sfVector2f d = {-1785,-1950};
    sfVector2f e = {-2065, -1760};
    sfVector2f f = {-4500, -1935};
    sfVector2f g = {-1765, -1395};
    sfVector2f h = {-1815, -2280};
    sfVector2f i = {-2050, -1395};
    sfVector2f j = {-2100, -2280};
    sfVector2f k = {-160, -235};
    sfVector2f l = {-380, -415};
    sfVector2f m = {80, -650};
    sfVector2f n = {-65, -800};
    sfVector2f o = {-3135,-4185};
    sfVector2f p = {-3440, -4500};
    sfVector2f q = {-4030, -3945};
    sfVector2f r = {-4440, -4210};
    sfVector2f s = {-3035, 325};
    sfVector2f t = {-3335, 10};
    sfVector2f u = {175, 430};
    sfVector2f v = {-35, 85};
    sfVector2f w = {-335, 380};
    sfVector2f x = {-700, 105};
    sfVector2f z = {755, 410};
    sfVector2f a1 = {545, 75};

    if (obstacle_gestion(ga, a, b) == 1 && obstacle_gestion(ga, c, d) == 1 && obstacle_gestion(ga, e, f) == 1
        && (obstacle_gestion(ga, g, h) == 1) && (obstacle_gestion(ga, i, j) == 1) && (obstacle_gestion(ga, k, l) == 1)
        && (obstacle_gestion(ga, m, n) == 1) && (obstacle_gestion(ga, o, p) == 1) && (obstacle_gestion(ga, q, r) == 1)
        && (obstacle_gestion(ga, s, t) == 1) && (obstacle_gestion(ga, u, v) == 1) && (obstacle_gestion(ga, w, x) == 1)
        && (obstacle_gestion(ga, z, a1) == 1))
        return (1);
    return (0);
}

void move_player_up_down(game *ga)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (ga->jo_rect.top != 126)
            ga->jo_rect.top = 126;
        ga->jo_rect.left += 30;
        if (ga->jo_rect.left >= 90)
            ga->jo_rect.left = 0;
        sfSprite_setTextureRect(ga->s_jotaro, ga->jo_rect);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (ga->jo_rect.top != 0)
            ga->jo_rect.top = 0;
        ga->jo_rect.left += 30;
        if (ga->jo_rect.left >= 90)
            ga->jo_rect.left = 0;
        sfSprite_setTextureRect(ga->s_jotaro, ga->jo_rect);
    }
}

void move_player_left_right(game *ga)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (ga->jo_rect.top != 42)
            ga->jo_rect.top = 42;
        ga->jo_rect.left += 30;
        if (ga->jo_rect.left >= 90)
            ga->jo_rect.left = 0;
        sfSprite_setTextureRect(ga->s_jotaro, ga->jo_rect);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (ga->jo_rect.top != 84)
            ga->jo_rect.top = 84;
        ga->jo_rect.left += 30;
        if (ga->jo_rect.left >= 90)
            ga->jo_rect.left = 0;
        sfSprite_setTextureRect(ga->s_jotaro, ga->jo_rect);
    }
}

void move_maps(game *ga)
{

    if (sfKeyboard_isKeyPressed(sfKeyUp) && ga->pos.y < 450) {
        ga->pos.y += 5;
        sfSprite_setPosition(ga->spriteback, ga->pos);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && ga->pos.y > -4855) {
        ga->pos.y -= 5;
        sfSprite_setPosition(ga->spriteback, ga->pos);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && ga->pos.x < 845) {
        ga->pos.x += 5;
        sfSprite_setPosition(ga->spriteback, ga->pos);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && ga->pos.x > -4480) { 
        ga->pos.x -= 5;
        sfSprite_setPosition(ga->spriteback, ga->pos);
        }
}

void move_player(game *ga)
{
    if (obstacle(ga) == 1) {
        move_player_up_down(ga);
        move_player_left_right(ga);
        move_maps(ga);
    }
}
