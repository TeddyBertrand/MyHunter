/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myhunter-teddy.bertrand
** File description:
** myhunter2.c
*/
#include "./my.h"

static int clicksprite(window_base_t win, sprites_t *sp, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*) win.window);

    if (sp->menu.ismenu == 0) {
    sfRenderWindow_drawSprite(win.window, sp->menu.sprite, NULL);
    sfRenderWindow_drawSprite(win.window, sp->titre.sprite, NULL);
    }
        if (mouse.x >= sfSprite_getPosition(sp->menu.sprite).x &&
        mouse.x <= sfSprite_getPosition(sp->menu.sprite).x + 350)
            if (mouse.y >= sfSprite_getPosition(sp->menu.sprite).y + 150 &&
            mouse.y <= sfSprite_getPosition(sp->menu.sprite).y + 300) {
                clickmenu(event, sp);
            }
}

static void move_rectangle_back(sprites_t *sp, int offset, int max_value)
{
    sp->back.rect.top = 0;
    sp->back.rect.left += offset;
    sp->back.rect.width = 1920;
    sp->back.rect.height = 1200;
    if (sp->back.rect.left >= max_value)
        sp->back.rect.left = 0;
}

static void move_rectangle_duck(sprites_t *sp, int offset, int max_value)
{
    sp->duck.rect.top = 0;
    sp->duck.rect.left += offset;
    sp->duck.rect.width = 220;
    sp->duck.rect.height = 220;
    if (sp->duck.rect.left >= max_value)
        sp->duck.rect.left = 0;
}

static void move_rectangle_duck2(sprites_t *sp, int offset, int max_value)
{
    sp->duck2.rect.top = 0;
    sp->duck2.rect.left += offset;
    sp->duck2.rect.width = 220;
    sp->duck2.rect.height = 220;
    if (sp->duck2.rect.left >= max_value)
        sp->duck2.rect.left = 0;
}

void set_all2(sprites_t *sp)
{
    sfSprite_setTexture(sp->duck.sprite, sp->duck.texture, sfTrue);
    sfSprite_setTexture(sp->hearts.sprite, sp->hearts.texture, sfTrue);
    sfSprite_setTextureRect(sp->duck2.sprite, sp->duck2.rect);
    sfSprite_setTextureRect(sp->duck.sprite, sp->duck.rect);
    sfText_setFont(sp->score.score, sp->score.font);
    sfText_setFont(sp->score.scoretxt, sp->score.font);
    sfText_setColor(sp->score.score, sfRed);
    sfText_setColor(sp->score.scoretxt, sfRed);
    sfText_setCharacterSize(sp->score.score, 200);
    sfText_setCharacterSize(sp->score.scoretxt, 200);
    sfText_setPosition(sp->score.score, (sfVector2f) {1650, 0});
    sfText_setPosition(sp->score.scoretxt, (sfVector2f) {1220, 0});
}

void set_all(sprites_t *sp)
{
    sfMusic_setLoop(sp->back.music, sfTrue);
    sfMusic_play(sp->back.music);
    sfSprite_setPosition(sp->menu.sprite, (sfVector2f) {800, 700});
    sfSprite_setPosition(sp->titre.sprite, (sfVector2f) {340, 300});
    sfSprite_setScale(sp->menu.sprite, sp->menu.scale);
    sfSprite_setScale(sp->back.sprite, sp->back.scale);
    sfSprite_setTexture(sp->menu.sprite, sp->menu.texture, sfTrue);
    sfSprite_setTexture(sp->titre.sprite, sp->titre.texture, sfTrue);
    sfSprite_setTexture(sp->duck2.sprite, sp->duck2.texture, sfTrue);
    sfSprite_setTexture(sp->back.sprite, sp->back.texture, sfTrue);
    set_all2(sp);
}

void theclock(clockbackground_t *clock, sprites_t *sp, window_base_t *win)
{
    if (sfTime_asSeconds(clock->time) > 0.2f && sp->menu.ismenu == 1) {
                move_rectangle_back(sp, 1920, 13440);
                sfSprite_setTextureRect(sp->back.sprite, sp->back.rect);
                move_rectangle_duck(sp, 220, 1100);
                sfRenderWindow_drawSprite(win->window, sp->duck.sprite, NULL);
                sfSprite_setTextureRect(sp->duck.sprite, sp->duck.rect);
                move_rectangle_duck2(sp, 220, 1100);
                sfSprite_setTextureRect(sp->duck2.sprite, sp->duck2.rect);
                sfClock_restart(clock->clock);
            }
}

void menuandposition(window_base_t *win, sprites_t *sp, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(win->window, event)) {
            if (event->type == sfEvtClosed)
                sfRenderWindow_close(win->window);
    }
    isstartclicked(win, sp, event);
    death(sp);
    if (sp->duck.gameover > 2)
        sfRenderWindow_close(win->window);
    clicksprite(*win, sp, *event);
    sfRenderWindow_display(win->window);
    sfRenderWindow_clear(win->window, sfBlack);
    sfRenderWindow_drawSprite(win->window, sp->back.sprite, NULL);
}

int menu(void)
{
    window_base_t window_base;
    sprites_t sp;
    clockbackground_t clock;
    sfEvent event;

    init_all(&window_base, &sp, &clock);
    set_all(&sp);
    window_base.window = sfRenderWindow_create(window_base.mode,
    "mon chasseur", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window_base.window, 60);
    while (sfRenderWindow_isOpen(window_base.window)) {
            clock.time = sfClock_getElapsedTime(clock.clock);
            theclock(&clock, &sp, &window_base);
            sp.score.len = getlen(sp.duck.result);
            sfText_setString(sp.score.scoretxt, "Score : ");
            sfText_setString(sp.score.score, my_put_string(sp.duck.result,
            sp.score.len, sp.score.str, 0));
            menuandposition(&window_base, &sp, &event);
    }
    destroy(&sp, &window_base);
}
