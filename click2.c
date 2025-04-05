/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myhunter-teddy.bertrand
** File description:
** click2.c
*/
#include "./my.h"

int clickspriteduck(window_base_t win, sprites_t *sp, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*) win.window);

        if (mouse.x >= sfSprite_getPosition(sp->duck.sprite).x &&
        mouse.x <= sfSprite_getPosition(sp->duck.sprite).x + 220)
            if (mouse.y >= sfSprite_getPosition(sp->duck.sprite).y &&
            mouse.y <= sfSprite_getPosition(sp->duck.sprite).y + 220) {
                clickduck(event, sp);
            }
}

int clickspriteduck2(window_base_t win, sprites_t *sp, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*) win.window);

        if (mouse.x >= sfSprite_getPosition(sp->duck2.sprite).x &&
        mouse.x <= sfSprite_getPosition(sp->duck2.sprite).x + 220)
            if (mouse.y >= sfSprite_getPosition(sp->duck2.sprite).y &&
            mouse.y <= sfSprite_getPosition(sp->duck2.sprite).y + 220) {
                clickduck2(event, sp);
            }
}

void destroy(sprites_t *sp, window_base_t *win)
{
    sfMusic_destroy(sp->duck.death);
    sfMusic_destroy(sp->back.music);
    sfText_destroy(sp->score.score);
    sfText_destroy(sp->score.scoretxt);
    sfFont_destroy(sp->score.font);
    sfSprite_destroy(sp->duck.sprite);
    sfTexture_destroy(sp->duck.texture);
    sfRenderWindow_destroy(win->window);
}
