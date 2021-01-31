/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** return root
*/

int my_compute_square_root(int nb)
{
    int a = 0;

    if (nb < 0 || nb == 0) {
        return (0);
    } while (a * a != nb) {
        a = a + 1;
        if (a > nb)
            return (0);
    }
    return (a);
}
