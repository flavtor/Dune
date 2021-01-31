/*
** EPITECH PROJECT, 2021
** destroy.c
** File description:
** destroy.c
*/

#include "my.h"
#include "game.h"
#include "struct.h"

void destroy_menu(sfRenderWindow* window, game *ga)
{
    sfMusic_destroy(ga->menu_music);
    sfSprite_destroy(ga->sprite_play);
    sfSprite_destroy(ga->sprite_exit);
    sfRenderWindow_close(window);
}
