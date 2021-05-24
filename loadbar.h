#include <ncurses.h>

typedef struct {
    WINDOW *win;
    int width;
    int v_max;
    char *name;
} Loadbar;

Loadbar *lb_init(char *name, int starty, int startx, int width, int v_max);
void lb_destroy(Loadbar *lb);
void lb_render(Loadbar *lb, int value);
void lb_set_char_at(Loadbar *lb, int value, char *c);
