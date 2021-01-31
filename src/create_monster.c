/*
** EPITECH PROJECT, 2021
** create_monster.c
** File description:
** create_monster.c
*/

#include "my.h"
#include "struct.h"
#include "game.h"

sfSprite *create_monster(int x_spawn, int y_spawn)
{
    sfTexture *t_sm;
    sfSprite *s_sm;

    t_sm = sfTexture_createFromFile("press/image/sprites/zombie.png", NULL);
    s_sm = sfSprite_create();
    sfSprite_setTexture(s_sm, t_sm, sfTrue);
    sfSprite_setPosition(s_sm, (sfVector2f){x_spawn, y_spawn});
    sfSprite_setTextureRect(s_sm, (sfIntRect){0, 0, 32, 48});
    return (s_sm);
}
