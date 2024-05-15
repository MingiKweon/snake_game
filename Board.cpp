// #include "Board.hpp"
// #include <ncurses.h>

// Board::Board(int height, int width)
//     {
//         int xMax, yMax;
//         getmaxyx(stdscr, yMax, xMax);
        
//         board_win = newwin(height, width, (yMax/2)-(height/2), (xMax/2)-(width/2));
//         initialize();
//     }
// Board::~Board()
// {
    
// }
    
//     void initialize()
//     {
//         clear();
//         refresh();
//     }
//     void addBorder()
//     {
//         box(board_win, 0, 0);
//     }
//     void clear()
//     {
//         wclear(board_win);
//         addBorder();
//     }
//     void refresh()
//     {
//         wrefresh(board_win);
//     }
//     char getInput()
//     {
//         return wgetch(board_win);
//     }
//     void addAt(int y, int x, char ch)
//     {
//         mvwaddch(board_win, y, x, ch);
//     }