#include <ncurses.h>
#include "map.h"

WINDOW *win;

void snake_move(WINDOW *win)
{
    mvwprintw(win, 10 + 1, 32 + 1, "H");
    mvwprintw(win, 10 + 1, 35 + 1, "B");
    mvwprintw(win, 10 + 1, 38 + 1, "B");
}