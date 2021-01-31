/*
** EPITECH PROJECT, 2020
** verif_max_size.c
** File description:
** verif_max_size
*/

#include "my.h"
#include "game.h"
#include "struct.h"

int verif_max_size(sfSprite *s_monster, int nb_direction)
{
    if (sfSprite_getPosition(s_monster).y >= 985)
        nb_direction = TOP;
    if (sfSprite_getPosition(s_monster).y <= 0)
        nb_direction = BOTTOM;
    if (sfSprite_getPosition(s_monster).x >= 1600)
        nb_direction = LEFT;
    if (sfSprite_getPosition(s_monster).x <= 0)
        nb_direction = RIGHT;
    return (nb_direction);
}

int verif_max_size_2(sfSprite *s_monster, int nb_direction)
{
    if (sfSprite_getPosition(s_monster).y >= 745)
        nb_direction = TOP;
    if (sfSprite_getPosition(s_monster).y <= 235)
        nb_direction = BOTTOM;
    if (sfSprite_getPosition(s_monster).x >= 1445)
        nb_direction = LEFT;
    if (sfSprite_getPosition(s_monster).x <= 470)
        nb_direction = RIGHT;
    return (nb_direction);
}

int verif_max_size_3(sfSprite *s_monster, int nb_direction)
{
    if (sfSprite_getPosition(s_monster).y >= 745)
        nb_direction = TOP;
    if (sfSprite_getPosition(s_monster).y <= 235)
        nb_direction = BOTTOM;
    if (sfSprite_getPosition(s_monster).x >= 1445)
        nb_direction = LEFT;
    if (sfSprite_getPosition(s_monster).x <= 470)
        nb_direction = RIGHT;
    return (nb_direction);
}