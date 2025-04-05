/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myhunter-teddy.bertrand
** File description:
** my_put_nbr_to_string.c
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int getlen(int nb)
{
    int i = 0;

    for (; nb > 10; i++)
        nb = nb / 10;
    return (i);
}

char *my_put_string(int nb, int len, char *str, int i)
{
    if (nb == 10) {
    str[0] = '1';
    str[1] = '0';
    str[2] = '\0';
    return (str);
    }
    if (nb < 10 && nb >= 0) {
        str[len - i] = nb + 48;
        str[len + 1] = '\0';
        return (str);
    }
    if (nb < 0) {
        return (0);
    }
    my_put_string(nb / 10, len, str, i + 1);
    my_put_string(nb - ((nb / 10)) * 10, len, str, i);
    str[len + 1] = '\0';
    return (str);
}

// int main(void)
// {
//     int len = getlen(100);
//     char *str = malloc(sizeof(char) * 10);
//     printf("%s", my_put_string(100, len, str, 0));
// }
