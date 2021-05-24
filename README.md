# ncurses-loadbar
A loading bar widget for the ncurses library in C.

Build the test with `make` or add the source files to your project.

You can use the widget simply by doing something like:
```C
Loadbar *mylb;
// init a loadbar with width 100 and max value 10
mylb = lb_init("my loadbar", 1, 1, 100, 10);
// render a half filled bar
lb_render(mylb, 50);
```
