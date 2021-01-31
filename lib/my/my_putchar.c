/*
** EPITECH PROJECT, 2019
** un write
** File description:
** putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
