#ifndef __SNAKE__
#define __SNAKE__
#include <ncurses.h>
#include "Drawable.hpp"
#include <deque>


enum Direction
{
    up, down, left, right
};

class SnakePiece : public Drawable
{
public:
    SnakePiece();
    SnakePiece(int y, int x);
    void SnakeHead(int y, int x);
};

class Snake 
{
std::deque<SnakePiece> prev_pieces;
Direction cur_direction;
public:
    Snake();
    void addPiece(SnakePiece piece);
    void removePiece();
    std::deque<SnakePiece> getPiece(); // 뱀을 인덱스로 접근
    SnakePiece tail();
    SnakePiece head();
    Direction getDirection();
    void setDirection(Direction d);
    SnakePiece nextHead();
};

#endif