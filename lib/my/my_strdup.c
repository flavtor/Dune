/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** allocates memory and copies the string
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *src)
{
    int len = my_strlen(src) + 1;
    char *a = malloc(sizeof(char) * (len));

    if (a == NULL)
        return (NULL);
    a = my_strcpy(a, src);
    a[len - 1] = '\0';
    return (a);
}
