/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** swap two intenger
*/

void my_swap(int *a, int *b)
{
    int c = 0;

    c = *a;
    *a = *b;
    *b = c;
}
