/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** just my_strncmp
*/

int my_strncmp(char *s1, char *s2, int n)
{
    int a = 0;

    for (; a < n && (s1[a] != '\0') && (s2[a] != '\0') ; a++) {
        if (s1[a] != s2[a])
            return (s1[a] - s2[a]);
    }
    return (s1[a] - s2[a]);
}
