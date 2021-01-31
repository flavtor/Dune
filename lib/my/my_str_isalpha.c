/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** str isalpha
*/

int my_str_isalpha(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' &&  str[i] <= 'z')
            i = i + 1;
        else
            return (0);
    }
    return (1);
}
