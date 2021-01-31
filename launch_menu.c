/*
** EPITECH PROJECT, 2021
** launch_menu.c
** File description:
** launch_menu.c
*/

#include "my.h"
#include "struct.h"
#include "game.h"

void event_quit(sfRenderWindow* window, sfEvent event, game *ga)
{
    sfVector2f c = sfSprite_getPosition(ga->sprite_exit);
    sfVector2f d = {c.x + 670, c.y + 185};
    sfVector2i mouse;
    sfIntRect rect = {0, 0, 670, 185};

    mouse.x = sfMouse_getPositionRenderWindow(window).x;
    mouse.y = sfMouse_getPositionRenderWindow(window).y;
    if ((event.type == sfEvtClosed || mouse.x >= c.x) &&
        ((mouse.y >= c.y) && mouse.x <= d.x && mouse.y <= d.y)) {
        rect.left += 670;
        sfSprite_setTextureRect(ga->sprite_exit, rect);
        sfRenderWindow_drawSprite(window, ga->sprite_exit, NULL);
        if (event.type == sfEvtMouseButtonPressed
            || event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    } if (mouse.x <= c.x || mouse.y <= c.y || mouse.x >= d.x
          || mouse.y >= d.y) {
        rect.left = 0;
        sfSprite_setTextureRect(ga->sprite_exit, rect);
        sfRenderWindow_drawSprite(window, ga->sprite_exit, NULL);
    }
}

void event_play(sfRenderWindow* window, sfEvent event, game *ga)
{
    sfVector2f c = sfSprite_getPosition(ga->sprite_play);
    sfVector2f d = {c.x + 670, c.y + 185};
    sfVector2i mouse;
    sfIntRect rect = {0, 0, 670, 185};
    float x = 660;
    float y = -3695;
    
    mouse.x = sfMouse_getPositionRenderWindow(window).x;
    mouse.y = sfMouse_getPositionRenderWindow(window).y;
    if ((event.type == sfEvtClosed || mouse.x >= c.x) &&
        ((mouse.y >= c.y) && mouse.x <= d.x && mouse.y <= d.y)) {
        rect.left += 670;
        sfSprite_setTextureRect(ga->sprite_play, rect);
        sfRenderWindow_drawSprite(window, ga->sprite_play, NULL);
        if (event.type == sfEvtMouseButtonPressed
            || event.type == sfEvtClosed) {
            sfMusic_stop(ga->menu_music);
            hub(window, ga, x, y);
        }
    } if (mouse.x <= c.x || mouse.y <= c.y || mouse.x >= d.x
      || mouse.y >= d.y) {
        rect.left = 0;
        sfSprite_setTextureRect(ga->sprite_play, rect);
        sfRenderWindow_drawSprite(window, ga->sprite_play, NULL);
    }
}

void button_loop(sfRenderWindow* window, game *ga)
{
    sfVector2f pos1 = {190, 520};
    sfVector2f pos2 = {1065, 520};
 
    sfRenderWindow_drawSprite(window, ga->sprite_exit, NULL);
    sfRenderWindow_drawSprite(window, ga->sprite_play, NULL);
    sfSprite_setPosition(ga->sprite_play, pos1);
    sfSprite_setPosition(ga->sprite_exit, pos2);
}

sfMusic *menu_music(void)
{
    sfMusic *music;

    music = sfMusic_createFromFile("music/menu.ogg");
    if (!music)
        return (NULL);
    sfMusic_play(music);
    return (music);
}

sfSprite *quit_button(void)
{
    sfTexture* quit_texture;
    sfSprite* quit;
    sfIntRect rect = {0, 0, 670, 185};

    quit_texture = sfTexture_createFromFile("image/sprites/exit.png", NULL);
    if (!quit_texture)
        return (NULL);
    quit = sfSprite_create();
    sfSprite_setTexture(quit, quit_texture, sfTrue);
    sfSprite_setTextureRect(quit, rect);
    return (quit);
} 

sfSprite *play_button(void)
{
    sfTexture* play_texture;
    sfSprite* play;
    sfIntRect rect = {0, 0, 670, 185};

    play_texture = sfTexture_createFromFile("image/sprites/play.png", NULL);
    if (!play_texture)
        return (NULL);
    play = sfSprite_create();
    sfSprite_setTexture(play, play_texture, sfTrue);
    sfSprite_setTextureRect(play, rect);
    return (play);
}

sfSprite *menu_background(void)
{
    sfTexture* texture;
    sfSprite* menu_background;

    texture = sfTexture_createFromFile("image/background/menu_back.jpg", NULL);
    if (!texture)
        return (NULL);
    menu_background = sfSprite_create();
    sfSprite_setTexture(menu_background, texture, sfTrue);
    return (menu_background);
}

void menu_init(game *ga)
{
    ga->spriteback = menu_background();
    ga->sprite_play = play_button();
    ga->sprite_exit = quit_button();
    ga->menu_music = menu_music();
}

void launch_menu(sfRenderWindow *window)
{
    game *ga = malloc(sizeof(*ga));
    sfEvent ev;
    
    menu_init(ga);
    while (sfRenderWindow_isOpen(window)){
        display_window(window, ga, ga->menu_music);
        button_loop(window, ga);
        while (sfRenderWindow_pollEvent(window, &ev)) {
            if (ev.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeySpace))
                sfRenderWindow_close(window);
            event_play(window, ev, ga);
            event_quit(window, ev, ga);
        }
    }
    destroy_menu(window, ga);
}
