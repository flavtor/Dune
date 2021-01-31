/*
** EPITECH PROJECT, 2021
** display_window
** File description:
** display_window
*/

#include "my.h"
#include "struct.h"
#include "game.h"

void display_window(sfRenderWindow *window, game *ga, sfMusic *music)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, ga->spriteback, NULL);
    sfMusic_setLoop(music, sfTrue);
} 
