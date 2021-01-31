/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** number of character
*/

int my_strlen(char const *str)
{
    int a = 0;

    for (int b = 0; str[b] != '\0'; b++)
        a = a + 1;
    return (a);
}
