#include <ncurses.h>

void map(WINDOW *win)
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21 * 3; j += 3)
        {
            if (i == 0 or i == 20)
            {
                if (j == 0 or j == 20 * 3)
                {
                    mvwprintw(win, i + 1, j + 3, "2");
                    // printw("2  ");
                }
                else
                {
                    mvwprintw(win, i + 1, j + 3, "1");
                    // printw("1  ");
                }
            }
            else
            {
                if (j == 0 or j == 20 * 3)
                {
                    mvwprintw(win, i + 1, j + 3, "1");
                    // printw("1  ");
                }
                else if (i == 10 and j == 10 * 3)
                {
                    mvwprintw(win, i + 1, j + 3, "H");
                }
                else if (i == 10 and j == 11 * 3)
                {
                    mvwprintw(win, i + 1, j + 3, "B");
                }
                else if (i == 10 and j == 12 * 3)
                {
                    mvwprintw(win, i + 1, j + 3, "B");
                }
                else
                {
                    mvwprintw(win, i + 1, j + 3, "0");
                    // printw("0  ");
                }
            }
        }
    }
}

int main(void)
{
    initscr();
    // start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    box(stdscr, 0, 0);
    attron(COLOR_PAIR(1));
    wbkgd(stdscr, COLOR_PAIR(1));

    WINDOW *win = subwin(stdscr, 23, 67, 1, 2); // 세로, 가로, 좌표y, 좌표x
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    box(win, 0, 0);
    attron(COLOR_PAIR(2));
    wbkgd(win, COLOR_PAIR(2));
    map(win);

    // for (int i = 0; i < 5; i++)
    // {
    //     mvwprintw(win, i + 1, 1, "Hello"); // 세로, 가로
    // }
    refresh();

    getch();
    delwin(win);
    endwin();

    return 0;
}