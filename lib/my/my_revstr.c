/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse a str
*/

static int my_strlen(char const *str)
{
    int a = 0;

    for (int b = 0; str[b] != '\0'; b++)
        a = a + 1;
    return (a);
}

char *my_revstr(char *str)
{
    int a = 0;
    int b = my_strlen(str) - 1;
    char c;

    while (a < b) {
        c = str[a];
        str[a] = str[b];
        str[b] = c;
        a++;
        b--;
    }
    return (str);
}
