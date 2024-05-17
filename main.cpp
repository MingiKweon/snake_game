#include <curses.h>

int main(int argc, char *argv[])
{
    int ch;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);

    while ((ch = getch()) != KEY_F(1))
    {
        clear();

        switch (ch)
        {
        case KEY_LEFT:
            printw("KEY LEFT");
            break;
        case KEY_RIGHT:
            printw("KEY RIGHT");
            break;
        case KEY_UP:
            printw("KEY UP");
            break;
        case KEY_DOWN:
            printw("KEY DOWN");
            break;
        }
    }

    endwin();
    return 0;
}