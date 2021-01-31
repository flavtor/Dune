/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** find a str in a str
*/

char *my_strstr(char *str, char const *to_find)
{
    if (str[0] != '\0') {
        for (int a = 0; to_find[a] != '\0'; a++) {
            if (to_find[a] != str[a])
                return (my_strstr(str + 1, to_find));
        }
        return (str);
    } else
        return (0);
}
