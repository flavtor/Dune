/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** hunter
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>


#ifndef STRUCT_JEU_H
#define STRUCT_JEU_H

typedef struct game game;
struct game
{
    sfSprite *spriteback;
    sfSprite *sprite_play;
    sfSprite *sprite_exit;
    sfSprite *life;
    sfSprite *di1;
    sfSprite *di2;
    sfSprite *di3;
    sfSprite *di4;
    sfSprite *di5;
    sfSprite *di6;
    sfSprite *di7;
    sfSprite *di8;
    sfSprite *di9;
    sfSprite *di10;
    sfSprite *di11;
    sfSprite *di12;
    sfSprite *di13;
    sfSprite *di14;
    sfSprite *di15;
    sfSprite *di16;
    sfSprite *di17;
    sfSprite *di18;
    sfSprite *di19;
    sfSprite *di20;
    sfSprite *di21;
    sfSprite *di22;
    sfSprite *di23;
    sfSprite *di24;
    sfSprite *di25;
    sfSprite *di26;
    sfSprite *s_jotaro;
    sfMusic *menu_music;
    sfMusic *finale_1;
    sfMusic *finale_2;
    sfMusic *music_grotte_1;
    sfMusic *music_grotte_2;
    sfMusic *music_grotte_3;
    sfMusic *scene_1;
    sfMusic *scene_2;
    sfMusic *lame;
    sfMusic *meurtre;
    sfIntRect jo_rect;
    sfIntRect rect_l;
    sfVector2f pos;
    sfVector2f pos1;
    sfVector2f pos2;
    int xrect;
    float vie;
    sfClock *c_ta;
    sfVector2f di_pos;
    sfSprite *s_monster1;
    sfClock *c_monster1;
    sfSprite *s_monster2;
    sfClock *c_monster2;
    sfSprite *s_monster3;
    sfClock *c_monster3;
    sfSprite *s_monster4;
    sfClock *c_monster4;
    sfSprite *s_monster5;
    sfClock *c_monster5;
    sfSprite *s_monster6;
    sfClock *c_monster6;
    sfSprite *s_hero;
};

#endif
