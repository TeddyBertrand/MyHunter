/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myhunter-teddy.bertrand
** File description:
** init_all.c
*/
#include "./my.h"

int init_all3(clockbackground_t *clock, sprites_t *sp)
{
    sp->duck2.rect.left = 0;
    sp->back.rect.left = 0;
    sp->duck.yrand = (rand() % 901) + 100;
    sp->duck2.yrand = (rand() % 701) + 200;
    sp->duck.gameover = 0;
    sp->duck.result = 0;
    sp->duck.vitesse = 6;
    sp->back.music = sfMusic_createFromFile("./images/piano.mp3");
    if (!sp->back.music || !sp->menu.son || !sp->duck.death)
        return (84);
}

int init_all2(clockbackground_t *clock, sprites_t *sp)
{
    sp->duck2.texture = sfTexture_createFromFile("./images/smahshibou", NULL);
    sp->duck2.sprite = sfSprite_create();
    sp->menu.texture = sfTexture_createFromFile("./images/menu.png", NULL);
    sp->menu.texture2 = sfTexture_createFromFile("./images/menu2.png", NULL);
    sp->hearts.texture = sfTexture_createFromFile("./images/hearts.png", NULL);
    sp->hearts.sprite = sfSprite_create();
    sp->score.font = sfFont_createFromFile("./font/doom.ttf");
    sp->score.score = sfText_create();
    sp->score.str = malloc(sizeof(char) * 10);
    sp->score.scoretxt = sfText_create();
    clock->clock = sfClock_create();
    sp->menu.sprite = sfSprite_create();
    sp->menu.scale = (sfVector2f){4, 4};
    sp->back.scale = (sfVector2f){1, 1.1};
    sp->menu.son = sfMusic_createFromFile("./images/shotgun.mp3");
    sp->back.soundbutton = sfMusic_createFromFile("./images/reload.mp3");
    sp->duck.death = sfMusic_createFromFile("./images/oooof.mp3");
    sp->duck.rect.left = 0;
    init_all3(clock, sp);
    return (0);
}

void init_all(window_base_t *win, sprites_t *sp, clockbackground_t *clock)
{
    win->mode = (sfVideoMode){1920, 1200, 32};
    sp->menu.ismenu = 0;
    sp->titre.texture = sfTexture_createFromFile("./images/titre.png", NULL);
    sp->titre.sprite = sfSprite_create();
    sp->back.texture = sfTexture_createFromFile("./images/smahs5.jpg", NULL);
    sp->back.texture2 = sfTexture_createFromFile("./images/menugif", NULL);
    sp->back.sprite = sfSprite_create();
    sp->duck.texture = sfTexture_createFromFile("./images/smahshibou", NULL);
    sp->duck.sprite = sfSprite_create();
    init_all2(clock, sp);
}
