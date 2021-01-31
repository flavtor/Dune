/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copy str
*/

char *my_strcpy(char *dest, char const * src)
{
    int a;

    for (a = 0; (src[a]) != '\0'; a++) {
        dest[a] = src[a];
    }
    dest[a] = '\0';
    return (dest);
}
