/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myhunter-teddy.bertrand
** File description:
** click.c
*/
#include "./my.h"

int clickduck(sfEvent event, sprites_t *sp)
{
    if (event.type == sfEvtMouseButtonPressed) {
        sfSprite_setPosition(sp->duck.sprite,
        (sfVector2f) {-200, sp->duck.yrand});
        sfMusic_play(sp->menu.son);
        sp->duck.yrand = (rand() % 901) + 100;
        sp->duck.result += 1;
        sp->duck.vitesse += 0.06;
    }
}

int isstartclicked(window_base_t *win, sprites_t *sp, sfEvent *event)
{
    if (sp->menu.ismenu == 1) {
            sfRenderWindow_drawSprite(win->window, sp->duck.sprite, NULL);
            sfRenderWindow_drawSprite(win->window, sp->duck2.sprite, NULL);
            sfRenderWindow_drawSprite(win->window, sp->duck.sprite, NULL);
            sfRenderWindow_drawText(win->window, sp->score.score, NULL);
            sfRenderWindow_drawText(win->window, sp->score.scoretxt, NULL);
            clickspriteduck(*win, sp, *event);
            clickspriteduck2(*win, sp, *event);
            sfSprite_setPosition(sp->duck.sprite,
            (sfVector2f) {sfSprite_getPosition(sp->duck.sprite).x +
            sp->duck.vitesse, sp->duck.yrand});
            sfSprite_setPosition(sp->duck2.sprite,
            (sfVector2f) {sfSprite_getPosition(sp->duck2.sprite).x +
            sp->duck.vitesse, sp->duck2.yrand});
    }
}

int clickduck2(sfEvent event, sprites_t *sp)
{
    if (event.type == sfEvtMouseButtonPressed) {
        sfSprite_setPosition(sp->duck2.sprite,
        (sfVector2f) {-200, sp->duck2.yrand});
        sfMusic_play(sp->menu.son);
        sp->duck2.yrand = (rand() % 901) + 100;
        sp->duck.result += 1;
        sp->duck.vitesse += 0.06;
    }
}

int clickmenu(sfEvent event, sprites_t *sp)
{
    if (event.type == sfEvtMouseButtonPressed) {
        sfSprite_setTexture(sp->back.sprite, sp->back.texture2, sfTrue);
        sfMusic_play(sp->back.soundbutton);
        sp->menu.ismenu = 1;
    }
}

int death(sprites_t *sp)
{
    if (sfSprite_getPosition(sp->duck.sprite).x >= 1900) {
        sfMusic_play(sp->duck.death);
        sp->duck.yrand = (rand() % 901) + 100;
        sp->duck.gameover += 1;
        sfSprite_setPosition(sp->duck.sprite,
        (sfVector2f) {-200, sp->duck.yrand});
    }
}
