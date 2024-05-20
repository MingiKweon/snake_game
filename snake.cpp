#include <ncurses.h>
#include <string>
#include "map.h"
using namespace std;

WINDOW *win;

void snake_move(WINDOW *win, int **snake_locaiton())
{
    int **snake = snake_locaiton();
    static int i = 32, j = 10;

    snake[0][0] = i;
    snake[0][1] = j;

    if (i > 2 and i < 62 and j > 0 and j < 20)
    {
        mvwprintw(win, snake[0][1] + 1, snake[0][0] + 1, "H");
        // mvwprintw(win, j + 1, i + 4, "B");
        // mvwprintw(win, j + 1, i + 7, "B");
    }
    nodelay(win, TRUE);

    static bool left = true;
    static bool right = false;
    static bool up = false;
    static bool down = false;

    int key = getch();
    // int key = KEY_UP;
    if (key != ERR)
    {
        switch (key)
        {
        case KEY_UP:
            j -= 1;
            up = true;
            down = false;
            right = false;
            left = false;
            break;
        case KEY_DOWN:
            j += 1;
            up = false;
            down = true;
            right = false;
            left = false;
            break;
        case KEY_RIGHT:
            i += 3;
            up = false;
            down = false;
            right = true;
            left = false;
            break;
        case KEY_LEFT:
            i -= 3;
            up = false;
            down = false;
            right = false;
            left = true;
            break;
        }
    }
    else
    {
        if (up)
            j -= 1;
        else if (down)
            j += 1;
        else if (right)
            i += 3;
        else if (left)
            i -= 3;
    }
}