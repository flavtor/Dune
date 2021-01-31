/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** find a prime sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb )
{
    int c = 0;
    int d = 0;

    for (int b = nb; c != 1; b++) {
        c = my_is_prime(b);
        d = b;
    }
    return (d);
}
