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
        cur_direction = down;
    }
void Snake::addPiece(SnakePiece piece)
    {
        piece.setIcon('#');
        prev_pieces.push_back(piece);
    }
void Snake::removePiece()
    {
        prev_pieces.pop_front();
    }
// 헤드를 제외한 덱이 0인 경우에 문제가 발생함
std::deque<SnakePiece> Snake::getPiece() // 머리를 제외한 배열을 복사해서 반환
{
    std::deque<SnakePiece> copyPieces(prev_pieces.begin(), prev_pieces.end() - 1);
    return copyPieces;
}
SnakePiece Snake::tail()
    {
        return prev_pieces.front();
    }
SnakePiece Snake::head()
    {
        return prev_pieces.back();
    }
Direction Snake::getDirection()
    {
        return cur_direction;
    }
void Snake::setDirection(Direction d)
    {
        cur_direction = d;
    }
SnakePiece Snake::nextHead()
    {
        int row = head().getY();
        int col = head().getX();
        switch(cur_direction)
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