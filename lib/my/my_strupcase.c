/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** strupcase
*/

char *my_strupcase(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] >= 'a' && str[a] <= 'z')
            str[a] -= 32;
    }
    return (str);
}
