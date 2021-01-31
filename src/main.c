/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"
#include "struct.h"
#include "game.h"

static int modif_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
        if ((s1[i] - s2[i] == 0) && (s1[i] == '=' || s2[i] == '='))
            return (0);
        i++;
    }
    return (s1[i] - s2[i]);
}

static int verif_env(char **env)
{
    for (int c = 0; env[c] != NULL; c++)
        if (modif_strcmp(env[c], "DISPLAY=") == 0)
            return (0);
    return (0);
}

int main(int ac, char **av, char **env)
{
    sfVideoMode mode = {1920, 1080, 60};
    sfRenderWindow *w;

    if (ac != 1 || av[0] == NULL)
        return (84);
    if (verif_env(env) == -1)
        return (84);
    w = sfRenderWindow_create(mode, "SFML Window", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w, 60);
    if (!w)
        return (84);
    launch_menu(w);
    return (0);
}
