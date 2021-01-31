/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** sort int
*/

void my_swap(int *a, int *b);

void my_sort_int_array(int *array, int size)
{
    int a = 0;

    while (a != size) {
        if (a > 0 && array[a] < array[a - 1]) {
            my_swap(&array[a], &array[a - 1]);
            a -= 2;
        }
        a += 1;
    }
}
