/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** copy n charaters
*/

char *my_strncpy(char *dest , char const *src , int n)
{
    int a;

    for (a = 0; (src[a]) != '\0' && a < n; a++) {
        dest[a] = src[a];
    }
    return (dest);
}
