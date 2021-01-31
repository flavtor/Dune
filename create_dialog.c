/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** dialog shop
*/

#include "my.h"
#include "struct.h"
#include "game.h"

sfSprite *create_dialog(game *ga, char *path)
{
    sfTexture *texture;
    sfSprite *sprite;
    char *filepath = path;

    texture = sfTexture_createFromFile(filepath, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    ga->di_pos.x = 725;
    ga->di_pos.y = 100;
    sfSprite_setPosition(sprite, ga->di_pos);
    return (sprite);
}
