/*
** EPITECH PROJECT, 2020
** move_sprite.c
** File description:
** move_sprite
*/

#include "my.h"
#include "game.h"
#include "struct.h"

void move_top(sfSprite *sprite, int speed)
{
    sfSprite_setPosition(sprite, (sfVector2f) {
            sfSprite_getPosition(sprite).x,
                sfSprite_getPosition(sprite).y - speed});
}

void move_bottom(sfSprite *sprite, int speed)
{
    sfSprite_setPosition(sprite, (sfVector2f) {
            sfSprite_getPosition(sprite).x,
                sfSprite_getPosition(sprite).y + speed});
}

void move_right(sfSprite *sprite, int speed)
{
    sfSprite_setPosition(sprite, (sfVector2f) {
            sfSprite_getPosition(sprite).x + speed,
                sfSprite_getPosition(sprite).y});
}

void move_left(sfSprite *sprite, int speed)
{
    sfSprite_setPosition(sprite, (sfVector2f) {
            sfSprite_getPosition(sprite).x - speed,
                sfSprite_getPosition(sprite).y});
}
