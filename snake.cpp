#include <ncurses.h>
#include <string>
#include "map.h"
using namespace std;

WINDOW *win;
int i;

void snake_move(WINDOW *win, int i)
{
    mvwprintw(win, 10 + 1, i + 1, "H");
    mvwprintw(win, 10 + 1, 35 + 1, "B");
    mvwprintw(win, 10 + 1, 38 + 1, "B");
}