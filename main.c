#include <unistd.h>
#include <ncurses.h>

#include "loadbar.h"

#define VMAX 100

int main() {
    Loadbar *lb1;
    Loadbar *lb2;

    initscr();
    cbreak();
    noecho();
    curs_set(0);

    refresh();
    lb1 = lb_init("Frames Loaded", 20, 10, 50, VMAX);
    lb2 = lb_init("Buffers Completed", 25, 10, 30, 5);
    refresh();

    for (int j = 0; j < 5; j++) {
        lb_render(lb2, j);
        for (int i = 0; i <= VMAX ; i++) {
            lb_render(lb1, i);

            // refresh needed for printw, not window
            printw("%d", i);
            refresh();
            /* sleep(1); */
            usleep(10000*5);
        }
    }
    lb_render(lb2, 5);


    getch();
    endwin();

    return 0;

}
