/*
** EPITECH PROJECT, 2020
** my_strlowcase.c
** File description:
** strlawcase
*/

char *my_strlowcase(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] >= 'A' && str[a] <= 'Z')
            str[a] = str[a] + 32;
    }
    return (str);
}
