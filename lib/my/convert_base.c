/*
** EPITECH PROJECT, 2020
** conver_base
** File description:
** convert base
*/

#include "my.h"
#include <stdlib.h>

char *convert_base(char *nbr, char *base_from, char *base_to)
{
    int   power = 1;
    int   i = my_strlen(nbr) - 1;
    int   total = 0;
    int   f_base = my_strlen(base_from);
    int   base = my_strlen(base_to);
    char  *result = malloc(sizeof(char) * 33);

    for (int nb = 0; i >= 0; i--, nb *= power, total += nb, power *= f_base) {
        if (nbr[i] <= '9'  && nbr[i] >= '0')
            nb = nbr[i] - '0';
        else
            nb = nbr[i] - 55;
    }
    for (int j = 0; total != 0; j++, total /= base) {
        if ((total % base) < 10)
            result[j] = (total % base) + 48;
        else
            result[j] = (total % base) + 55;
    }
    return (my_revstr(result));
}
