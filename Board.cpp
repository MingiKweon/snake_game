#include "Board.hpp"


Board::Board(int height, int width)
    {
        int xMax, yMax;
        getmaxyx(stdscr, yMax, xMax);
        
        board = newwin(100, 100, (yMax/2)-(height/2), (xMax/2)-(width/2));
        initialize();
    }
Board::~Board()
{
    NULL;
}
void Board::initialize()
    {
        clear();
        refresh();
    }
void Board::addBorder()
    {
        box(board, 0, 0);
    }
 void Board::clear()
    {
        wclear(board);
        addBorder();
    }
void Board::refresh()
    {
        wrefresh(board);
    }
char Board::getInput()
    {
        return wgetch(board);
    }
void Board::addAt(int y, int x, char ch)
    {
        mvwaddch(board, y, x, ch);
    }
WINDOW* Board::getWindow()
    {
        return board;
    }
