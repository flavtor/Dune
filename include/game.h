/*
** EPITECH PROJECT, 2021
** game.h
** File description:
** game.h
*/

#include "my.h"
#include "struct.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdio.h>

#ifndef GAME_
#define GAME_

#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

//MENU

void menu_init(game *ga);
void launch_menu(sfRenderWindow *window);
sfSprite *menu_background(void);
sfSprite *play_button(void);
sfMusic *menu_music(void);
void button_loop(sfRenderWindow* window, game *ga);
void event_play(sfRenderWindow* window, sfEvent event, game *ga);
void event_quit(sfRenderWindow* window, sfEvent event, game *ga);
void display_window(sfRenderWindow *window, game *ga, sfMusic *music);
void destroy_menu(sfRenderWindow* window, game *ga);

//HUB

void hub(sfRenderWindow *w, game *ga, float x, float y);
sfSprite *create_dialog(game *ga, char *path);
sfClock *create_clock(void);
void life_gestion(sfRenderWindow *window, game *ga, sfMusic *m);
void scene_f(sfRenderWindow *window, game *ga);
void finale(sfRenderWindow *window, game *ga);
void scene_r(sfRenderWindow *window, game *ga);
void final_fight(sfRenderWindow *window, game *ga);

//MOVE

void move_player_up_down(game *ga);
void move_player_left_right(game *ga);
void move_player(game *ga);
sfSprite *create_player(game *ga);
sfSprite *create_monster(int x_spawn, int y_spawn);
int next_nb_direction(int nb_direction);
void move_direction(sfSprite *s_monster, int nb_direction, int speed);
void move_all_monster(game *ga);
void move_monster1(game *ga, int speed, int max_time);
void move_monster2(game *ga, int speed, int max_time);
void move_monster3(game *ga, int speed, int max_time);
void move_monster4(game *ga, int speed, int max_time);
void move_monster5(game *ga, int speed, int max_time);
void move_monster6(game *ga, int speed, int max_time);
int verif_max_size(sfSprite *s_monster, int nb_direction);
void move_top(sfSprite *sprite, int speed);
void move_bottom(sfSprite *sprite, int speed);
void move_left(sfSprite *sprite, int speed);
void move_right(sfSprite *sprite, int speed);
void move_all_monster2(game *ga);
void move_monster1_2(game *ga, int speed, int max_time);
void move_monster2_2(game *ga, int speed, int max_time);
void move_monster3_2(game *ga, int speed, int max_time);
void move_monster4_2(game *ga, int speed, int max_time);
void move_monster5_2(game *ga, int speed, int max_time);
void move_monster6_2(game *ga, int speed, int max_time);
int verif_max_size_2(sfSprite *s_monster, int nb_direction);
void move_jotaro_zomb(game *ga, int speed, int max_time);
int verif_max_size_3(sfSprite *s_monster, int nb_direction);

//GROTTE

void grotte_1(sfRenderWindow *window, game *ga);
void init_grotte_1(game *ga);
void grotte_2(sfRenderWindow *window, game *ga);
void grotte_3(sfRenderWindow *window, game *ga);
void move_jotaro_left_right(game *ga);
void move_jotaro_up_down(game *ga);
int obstacle_grotte(game *ga, sfVector2f a, sfVector2f b);
void win(sfRenderWindow *win, game *ga);

//GAME_OVER

int monster_damages(game *ga, sfSprite *sp);
void game_over(sfRenderWindow *win);

#endif
