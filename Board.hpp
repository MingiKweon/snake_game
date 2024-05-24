#ifndef __BOARD__
#define __BOARD__
#include <ncurses.h>
#include "Drawable.hpp"
#include <cstdlib>


class Board
{
public:
    Board(); // 디폴트
    Board(int height, int width); // 생성자
    void initialize();
    void addBorder();
    void add(Drawable drawable);
    void clear();
    void refresh();
    int getInput();
    void addAt(int y, int x, char ch);
    void getEmptyCoordinates(int& y, int& x);
    void getWallCoordinates(int& y, int& x);
private:
    WINDOW* board_win;
    int height, width;
};

#endif