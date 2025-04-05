/*
** EPITECH PROJECT, 2024
** B-MUL-100-MPL-1-1-myhunter-teddy.bertrand
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <SFML/Audio.h>
    #include <fcntl.h>

int menu(void);
int getlen(int nb);
char *my_put_string(int nb, int len, char *str, int i);
typedef struct window_base {
    sfRenderWindow* window;
    sfVideoMode mode;
} window_base_t;

typedef struct duck {
    sfMusic *death;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfIntRect rect;
    float vitesse;
    int yrand;
    int gameover;
    int result;
} duck_t;

typedef struct duck2 {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
    sfIntRect rect;
    int yrand;
} duck2_t;

typedef struct hearts {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
} hearts_t;

typedef struct background {
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *texture2;
    sfVector2f scale;
    sfIntRect rect;
    sfMusic *music;
    sfMusic *soundbutton;
} background_t;

typedef struct clockbackground {
    sfClock *clock;
    sfTime time;
} clockbackground_t;

typedef struct menu {
    sfTexture *texture;
    sfTexture *texture2;
    sfSprite *sprite;
    sfVector2f scale;
    sfMusic *son;
    int ismenu;
} menu_t;

typedef struct score {
    sfText *score;
    sfFont *font;
    char *str;
    int len;
    sfText *scoretxt;
} score_t;

typedef struct titre {
    sfTexture *texture;
    sfSprite *sprite;
} titre_t;

typedef struct sprites {
    background_t back;
    menu_t menu;
    duck_t duck;
    duck2_t duck2;
    hearts_t hearts;
    score_t score;
    titre_t titre;
} sprites_t;
int clickspriteduck2(window_base_t win, sprites_t *sp, sfEvent event);
void init_all(window_base_t *win, sprites_t *sp, clockbackground_t *clock);
int clickspriteduck(window_base_t win, sprites_t *sp, sfEvent event);
int isstartclicked(window_base_t *win, sprites_t *sp, sfEvent *event);
int clickduck2(sfEvent event, sprites_t *sp);
void destroy(sprites_t *sp, window_base_t *win);
int clickduck(sfEvent event, sprites_t *sp);
int clickmenu(sfEvent event, sprites_t *sp);
int death(sprites_t *sp);

#endif
