/*
** EPITECH PROJECT, 2020
** concat_params
** File description:
** the command-line given arguments
*/

#include "my.h"
#include <stdlib.h>

static int my_paramlen(int ac, char **av)
{
    int i = 0;
    int len = 0;

    while (i != ac) {
        len += (my_strlen(av[i]) + 1);
        i += 1;
    }
    return (len);
}

char *concat_params(int ac, char **av)
{
    char *dest = malloc(sizeof(char) * (my_paramlen(ac, av) + 1));
    int a = 0;
    int b = 0;

    if (dest == NULL)
        return (NULL);
    for (int i = 0; i != ac; i++) {
        a = 0;
        while (av[i][a] != '\0') {
            dest[b] = av[i][a];
            a += 1;
            b += 1;
        }
        dest[b] = '\n';
        b += 1;
    }
    dest[b] = '\0';
    return (dest);
}
