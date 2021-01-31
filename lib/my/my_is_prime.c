/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** prime
*/

int my_is_prime(int nb)
{
    int a = 2;

    if (nb < 2) {
        return (0);
    } else {
        while (a < nb) {
            if (nb % a == 0)
                return (0);
            a++;
        }
    }
    return (1);
}
