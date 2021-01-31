/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** function that splits a string into words
*/

#include <stdlib.h>

static int my_isalphanum(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

static int my_wordlen(char const *str)
{
    int len = 0;

    if (my_isalphanum(str[0]) != 0)
        len++;
    for (int b = 0; str[b] != '\0'; b++) {
        if (my_isalphanum(str[b]) == 0 && my_isalphanum(str[b + 1]) == 1)
            len++;
    }
    return (len);
}

static int len_words(char const *str)
{
    int len = 0;

    for (int b = 0; str[b] != '\0'; b++) {
        if (my_isalphanum(str[b]) != 0)
            len++;
    }
    return (len);
}

char **my_str_to_word_array(char const *str)
{
    int words = my_wordlen(str);
    char **array = malloc(sizeof(char *) * words + 1);
    int a = 0;
    int b = 0;
    int c = 0;

    if (array == NULL)
        return (NULL);
    for (; a <= words - 1 ; a++, c = 0) {
        for (; my_isalphanum(str[b]) == 0; b++);
        array[a] = malloc(sizeof(char) * (len_words(str) + 1));
            if (array[a] == NULL)
            return (NULL);
        for (; my_isalphanum(str[b]) == 1; c++, b++ )
            array[a][c] = str[b];
        array[a][c] = '\0';
    }
    array[a] == NULL;
    return (array);
}
