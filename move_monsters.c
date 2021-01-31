/*
** EPITECH PROJECT, 2021
** move_monsters.c
** File description:
** move_monsters.c
*/

#include "my.h"
#include "struct.h"
#include "game.h"

int monster_damages(game *ga, sfSprite *sp)
{
    sfVector2f jo_b = {ga->pos1.x + 35, ga->pos1.y + 35};
    sfVector2f c = sfSprite_getPosition(sp);
    sfVector2f d = {c.x + 55, c.y + 60};

    if (((((ga->pos1.x <= c.x && c.x <= jo_b.x &&
            ga->pos1.y <= c.y && c.y <= jo_b.y))))
        || (ga->pos1.x <= d.x && d.x <= jo_b.x
            && ga->pos1.y <= d.y && d.y <= jo_b.y))
        ga->vie -= 0.25;
}

void move_all_monster(game *ga)
{
    move_monster1(ga, 2, 20);
    move_monster2(ga, 2, 19);
    move_monster3(ga, 2, 18);
    move_monster4(ga, 2, 17);
    move_monster5(ga, 2, 16);
    move_monster6(ga, 2, 15);
}

void move_all_monster2(game *ga)
{
    move_monster1_2(ga, 2, 20);
    move_monster2_2(ga, 2, 19);
    move_monster3_2(ga, 2, 18);
    move_monster4_2(ga, 2, 17);
    move_monster5_2(ga, 2, 16);
    move_monster6_2(ga, 2, 15);
}

void move_direction(sfSprite *s_monster, int nb_direction, int speed)
{
    switch (nb_direction) {
    case BOTTOM:
        move_bottom(s_monster, speed);
        break;
    case LEFT:
        move_left(s_monster, speed);
        break;
    case RIGHT:
        move_right(s_monster, speed);
        break;
    case TOP:
        move_top(s_monster, speed);
        break;
    default :
        break;
    }
}

int next_nb_direction(int nb_direction)
{
    int old_direction = nb_direction;

    nb_direction = rand() % 4;
    if (nb_direction == old_direction
        || (old_direction == TOP && nb_direction == BOTTOM)
        || (old_direction == BOTTOM && nb_direction == TOP)
        || (old_direction == LEFT && nb_direction == RIGHT)
        || (old_direction == RIGHT && nb_direction == LEFT)) {
        if (nb_direction == TOP || nb_direction == BOTTOM) {
            nb_direction = rand() % 2;
            nb_direction = (nb_direction == 1) ? LEFT : RIGHT;
        } else {
            nb_direction = rand() % 2;
            nb_direction = (nb_direction == 1) ? TOP : BOTTOM;
        }
    }
    return (nb_direction);
}

void move_monster1(game *ga, int speed, int max_time)
{
    static int nb_direction = 0;
    static int nb_time = 0;
    static int change_direction = 0;
    static int xrect = 0;

    sfSprite_setTextureRect(ga->s_monster1,
        (sfIntRect){xrect, nb_direction * 48, 32, 48});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(ga->c_monster1)) > 0.1) {
        sfClock_restart(ga->c_monster1);
        nb_time++;
        xrect += 32;
        xrect = (xrect > 96) ? 0 : xrect;
    }
    if (nb_time >= change_direction) {
        nb_direction = next_nb_direction(nb_direction);
        nb_time = 0;
        change_direction = rand() % max_time;
    }
    move_direction(ga->s_monster1, nb_direction, speed);
    nb_direction = verif_max_size(ga->s_monster1, nb_direction);
}

void move_monster2(game *ga, int speed, int max_time)
{
    static int nb_direction = 0;
    static int nb_time = 0;
    static int change_direction = 0;
    static int xrect = 0;

    sfSprite_setTextureRect(ga->s_monster2,
        (sfIntRect){xrect, nb_direction * 48, 32, 48});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(ga->c_monster2)) > 0.1) {
        sfClock_restart(ga->c_monster2);
        nb_time++;
        xrect += 32;
        xrect = (xrect > 96) ? 0 : xrect;
    }
    if (nb_time >= change_direction) {
        nb_direction = next_nb_direction(nb_direction);
        nb_time = 0;
        change_direction = rand() % max_time;
    }
    move_direction(ga->s_monster2, nb_direction, speed);
    nb_direction = verif_max_size(ga->s_monster2, nb_direction);
}

void move_monster3(game *ga, int speed, int max_time)
{
    static int nb_direction = 0;
    static int nb_time = 0;
    static int change_direction = 0;
    static int xrect = 0;

    sfSprite_setTextureRect(ga->s_monster3,
        (sfIntRect){xrect, nb_direction * 48, 32, 48});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(ga->c_monster3)) > 0.1) {
        sfClock_restart(ga->c_monster3);
        nb_time++;
        xrect += 32;
        xrect = (xrect > 96) ? 0 : xrect;
    }
    if (nb_time >= change_direction) {
        nb_direction = next_nb_direction(nb_direction);
        nb_time = 0;
        change_direction = rand() % max_time;
    }
    move_direction(ga->s_monster3, nb_direction, speed);
    nb_direction = verif_max_size(ga->s_monster3, nb_direction);
}

void move_monster4(game *ga, int speed, int max_time)
{
    static int nb_direction = 0;
    static int nb_time = 0;
    static int change_direction = 0;
    static int xrect = 0;

    sfSprite_setTextureRect(ga->s_monster4,
        (sfIntRect){xrect, nb_direction * 48, 32, 48});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(ga->c_monster4)) > 0.1) {
        sfClock_restart(ga->c_monster4);
        nb_time++;
        xrect += 32;
        xrect = (xrect > 96) ? 0 : xrect;
    }
    if (nb_time >= change_direction) {
        nb_direction = next_nb_direction(nb_direction);
        nb_time = 0;
        change_direction = rand() % max_time;
    }
    move_direction(ga->s_monster4, nb_direction, speed);
    nb_direction = verif_max_size(ga->s_monster4, nb_direction);
}

void move_monster5(game *ga, int speed, int max_time)
{
    static int nb_direction = 0;
    static int nb_time = 0;
    static int change_direction = 0;
    static int xrect = 0;

    sfSprite_setTextureRect(ga->s_monster5,
        (sfIntRect){xrect, nb_direction * 48, 32, 48});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(ga->c_monster5)) > 0.1) {
        sfClock_restart(ga->c_monster5);
        nb_time++;
        xrect += 32;
        xrect = (xrect > 96) ? 0 : xrect;
    }
    if (nb_time >= change_direction) {
        nb_direction = next_nb_direction(nb_direction);
        nb_time = 0;
        change_direction = rand() % max_time;
    }
    move_direction(ga->s_monster5, nb_direction, speed);
    nb_direction = verif_max_size(ga->s_monster5, nb_direction);
}

void move_monster6(game *ga, int speed, int max_time)
{
    static int nb_direction = 0;
    static int nb_time = 0;
    static int change_direction = 0;
    static int xrect = 0;

    sfSprite_setTextureRect(ga->s_monster6,
        (sfIntRect){xrect, nb_direction * 48, 32, 48});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(ga->c_monster6)) > 0.1) {
        sfClock_restart(ga->c_monster6);
        nb_time++;
        xrect += 32;
        xrect = (xrect > 96) ? 0 : xrect;
    }
    if (nb_time >= change_direction) {
        nb_direction = next_nb_direction(nb_direction);
        nb_time = 0;
        change_direction = rand() % max_time;
    }
    move_direction(ga->s_monster6, nb_direction, speed);
    nb_direction = verif_max_size(ga->s_monster6, nb_direction);
}

void move_monster1_2(game *ga, int speed, int max_time)
{
    static int nb_direction = 0;
    static int nb_time = 0;
    static int change_direction = 0;
    static int xrect = 0;

    sfSprite_setTextureRect(ga->s_monster1,
        (sfIntRect){xrect, nb_direction * 48, 32, 48});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(ga->c_monster1)) > 0.1) {
        sfClock_restart(ga->c_monster1);
        nb_time++;
        xrect += 32;
        xrect = (xrect > 96) ? 0 : xrect;
    }
    if (nb_time >= change_direction) {
        nb_direction = next_nb_direction(nb_direction);
        nb_time = 0;
        change_direction = rand() % max_time;
    }
    move_direction(ga->s_monster1, nb_direction, speed);
    nb_direction = verif_max_size_2(ga->s_monster1, nb_direction);
}

void move_monster2_2(game *ga, int speed, int max_time)
{
    static int nb_direction = 0;
    static int nb_time = 0;
    static int change_direction = 0;
    static int xrect = 0;

    sfSprite_setTextureRect(ga->s_monster2,
        (sfIntRect){xrect, nb_direction * 48, 32, 48});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(ga->c_monster2)) > 0.1) {
        sfClock_restart(ga->c_monster2);
        nb_time++;
        xrect += 32;
        xrect = (xrect > 96) ? 0 : xrect;
    }
    if (nb_time >= change_direction) {
        nb_direction = next_nb_direction(nb_direction);
        nb_time = 0;
        change_direction = rand() % max_time;
    }
    move_direction(ga->s_monster2, nb_direction, speed);
    nb_direction = verif_max_size_2(ga->s_monster2, nb_direction);
}

void move_monster3_2(game *ga, int speed, int max_time)
{
    static int nb_direction = 0;
    static int nb_time = 0;
    static int change_direction = 0;
    static int xrect = 0;

    sfSprite_setTextureRect(ga->s_monster3,
        (sfIntRect){xrect, nb_direction * 48, 32, 48});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(ga->c_monster3)) > 0.1) {
        sfClock_restart(ga->c_monster3);
        nb_time++;
        xrect += 32;
        xrect = (xrect > 96) ? 0 : xrect;
    }
    if (nb_time >= change_direction) {
        nb_direction = next_nb_direction(nb_direction);
        nb_time = 0;
        change_direction = rand() % max_time;
    }
    move_direction(ga->s_monster3, nb_direction, speed);
    nb_direction = verif_max_size_2(ga->s_monster3, nb_direction);
}

void move_monster4_2(game *ga, int speed, int max_time)
{
    static int nb_direction = 0;
    static int nb_time = 0;
    static int change_direction = 0;
    static int xrect = 0;

    sfSprite_setTextureRect(ga->s_monster4,
        (sfIntRect){xrect, nb_direction * 48, 32, 48});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(ga->c_monster4)) > 0.1) {
        sfClock_restart(ga->c_monster4);
        nb_time++;
        xrect += 32;
        xrect = (xrect > 96) ? 0 : xrect;
    }
    if (nb_time >= change_direction) {
        nb_direction = next_nb_direction(nb_direction);
        nb_time = 0;
        change_direction = rand() % max_time;
    }
    move_direction(ga->s_monster4, nb_direction, speed);
    nb_direction = verif_max_size_2(ga->s_monster4, nb_direction);
}

void move_monster5_2(game *ga, int speed, int max_time)
{
    static int nb_direction = 0;
    static int nb_time = 0;
    static int change_direction = 0;
    static int xrect = 0;

    sfSprite_setTextureRect(ga->s_monster5,
        (sfIntRect){xrect, nb_direction * 48, 32, 48});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(ga->c_monster5)) > 0.1) {
        sfClock_restart(ga->c_monster5);
        nb_time++;
        xrect += 32;
        xrect = (xrect > 96) ? 0 : xrect;
    }
    if (nb_time >= change_direction) {
        nb_direction = next_nb_direction(nb_direction);
        nb_time = 0;
        change_direction = rand() % max_time;
    }
    move_direction(ga->s_monster5, nb_direction, speed);
    nb_direction = verif_max_size_2(ga->s_monster5, nb_direction);
}

void move_monster6_2(game *ga, int speed, int max_time)
{
    static int nb_direction = 0;
    static int nb_time = 0;
    static int change_direction = 0;
    static int xrect = 0;

    sfSprite_setTextureRect(ga->s_monster6,
        (sfIntRect){xrect, nb_direction * 48, 32, 48});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(ga->c_monster6)) > 0.1) {
        sfClock_restart(ga->c_monster6);
        nb_time++;
        xrect += 32;
        xrect = (xrect > 96) ? 0 : xrect;
    }
    if (nb_time >= change_direction) {
        nb_direction = next_nb_direction(nb_direction);
        nb_time = 0;
        change_direction = rand() % max_time;
    }
    move_direction(ga->s_monster6, nb_direction, speed);
    nb_direction = verif_max_size_2(ga->s_monster6, nb_direction);
}

void move_jotaro_zomb(game *ga, int speed, int max_time)
{
    static int nb_direction = 0;
    static int nb_time = 0;
    static int change_direction = 0;
    static int xrect = 0;

    sfSprite_setTextureRect(ga->s_jotaro,
        (sfIntRect){xrect, nb_direction * 42, 31, 42});
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(ga->c_ta)) > 0.1) {
        sfClock_restart(ga->c_ta);
        nb_time++;
        xrect += 31;
        xrect = (xrect > 84) ? 0 : xrect;
    }
    if (nb_time >= change_direction) {
        nb_direction = next_nb_direction(nb_direction);
        nb_time = 0;
        change_direction = rand() % max_time;
    }
    move_direction(ga->s_jotaro, nb_direction, speed);
    nb_direction = verif_max_size_3(ga->s_jotaro, nb_direction);
}
