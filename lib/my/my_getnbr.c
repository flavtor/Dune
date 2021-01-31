/*
** EPITECH PROJECT, 2019
** my_get_nbr
** File description:
** get a nbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    long c = 0;
    int signe = 0;
    int modsigne = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            signe = signe + 1;
        i++;
    } while (str[i] >= '0' && str[i] <= '9') {
            c = c * 10 + (str[i] - 48);
            i++;
    }
    modsigne = signe % 2;
    if (modsigne == 1)
        c = c * -1;
    if (c / 10 < -2147483648 || c / 10  > 2147483647)
        return (0);
    return (c);
}
