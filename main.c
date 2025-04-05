/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myhunter-teddy.bertrand
** File description:
** main.c
*/
#include "./my.h"

int help(void)
{
    int fd = open("./h.txt", O_RDONLY);
    char buffer[BUFSIZ + 1];
    int reader = read(fd, buffer, BUFSIZ + 1);

    if (fd == -1) {
    printf("C'est pas bon");
    return (84);
    }
    for (int i = 0; buffer[i] != '\0'; i++)
    write(1, &buffer[i], 1);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc > 1 && argv[1][0] == '-' &&
    argv[1][1] == 'h' && argv[1][2] == '\0')
    help();
    else
    menu();
    return (0);
}
