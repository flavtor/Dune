/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** create jotaro sprite
*/

#include "my.h"
#include "struct.h"
#include "game.h"

sfSprite *create_player(game *ga)
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
    ga->pos1.x = 960;
    ga->pos1.y = 540;
    sfSprite_setPosition(sprite, ga->pos1);
    sfSprite_setTextureRect(sprite, ga->jo_rect);
    return (sprite);
}
