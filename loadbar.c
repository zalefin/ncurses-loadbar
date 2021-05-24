#include <stdlib.h>

#include "loadbar.h"


Loadbar *lb_init(char *name, int starty, int startx, int width, int v_max) {
    Loadbar *lb;

    lb = malloc(sizeof(Loadbar));

    lb->win = newwin(3, width + 2, starty, startx);
    lb->width = width;
    lb->v_max = v_max;
    lb->name = name;

    box(lb->win, 0, 0);
    wmove(lb->win, 0, 1);
    wprintw(lb->win, name);
    wrefresh(lb->win);

    return lb;
}

void lb_destroy(Loadbar *lb) {
    free(lb);
}

void lb_render(Loadbar *lb, int value) {
    float V;
    float v;
    float L;
    float l;

    V = (float)lb->v_max;
    v = (float)value;
    L = (float)lb->width;
    l = (v / V) * L;

    wmove(lb->win, 1, 1);
    for (int i = 0; i < lb->width; i++) {
        wprintw(lb->win, " ");
    }

    wmove(lb->win, 1, 1);
    for (int i = 0; i < l; i++) {
        wprintw(lb->win, "#");
    }

    /* wprintw(lb->win, (value == lb->v_max) ? "#" : ">"); */

    wrefresh(lb->win);

}

void lb_set_char_at(Loadbar *lb, int value, char *c) {
    float V;
    float v;
    float L;
    float l;

    V = (float)lb->v_max;
    v = (float)value;
    L = (float)lb->width;
    l = (v / V) * L;

    wmove(lb->win, 1, l+1);
    wprintw(lb->win, c);
    wrefresh(lb->win);
}
