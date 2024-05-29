#include "Snake.hpp"

SnakePiece::SnakePiece()
    {
        this->x = 0;
        this->y = 0;
        this->icon = '#';
    }
SnakePiece::SnakePiece(int y, int x)
    {
        this->x = x;
        this->y = y;
        this->icon = '#';
    }
Snake::Snake()
    {
        curDirection = down;
    }
void Snake::addPiece(SnakePiece piece)
    {
        piece.setIcon('#');
        prevPieces.push_back(piece);
    }
void Snake::removePiece()
    {
        prevPieces.pop_front();
    }
// 헤드를 제외한 덱이 0인 경우에 문제가 발생함
std::deque<SnakePiece> Snake::getPiece() // 머리를 제외한 배열을 복사해서 반환
{
    std::deque<SnakePiece> copyPieces(prevPieces.begin(), prevPieces.end() - 1);
    return copyPieces;
}
SnakePiece Snake::tail()
    {
        return prevPieces.front();
    }
SnakePiece Snake::head()
    {
        return prevPieces.back();
    }
Direction Snake::getDirection()
    {
        return curDirection;
    }
void Snake::setDirection(Direction d)
    {
        curDirection = d;
    }
void Snake::setDirection(int i)
{
    curDirection = (Direction)i;
}
SnakePiece Snake::nextHead()
    {
        int row = head().getY();
        int col = head().getX();
        switch(curDirection)
        {
            case down:
                row++;
                break;
            case up:
                row--;
                break;
            case left:
                col--;
                break;
            case right:
                col++;
                break;
        }
        return SnakePiece(row, col);
    }