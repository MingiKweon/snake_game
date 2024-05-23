#include "SnakeGame.hpp"
#include <ctime>

SnakeGame::SnakeGame(int height, int width) : board(height, width), item(nullptr), gameOver(false)
{
    initialize(); // 보드 객체를 만들어준다.
}

SnakeGame::~SnakeGame()
{
    delete item;
}

void SnakeGame::initialize()
{
    
    item = nullptr;
    board.initialize();
    gameOver = false;
    srand(time(NULL));
    snake.setDirection(down);

    SnakePiece next(5, 5); // 나중에 시작할 좌표를 줘야함
    board.add(next);
    snake.addPiece(next);

    next = snake.nextHead();
    board.add(next);
    snake.addPiece(next);

    snake.setDirection(right);

    next = snake.nextHead();
    
    board.add(next);
    snake.addPiece(next);
}

void SnakeGame::input()
{
    int input = board.getInput();
    if (input != ERR)
    {
    switch (input)
    {
    case KEY_UP:
        snake.setDirection(up);
        break;
    case KEY_DOWN:
        snake.setDirection(down);
        break;
    case KEY_LEFT:
        snake.setDirection(left);
        break;
    case KEY_RIGHT:
        snake.setDirection(right);
        break;
    }
    }
    
}

void SnakeGame::updateState()
{
    if (item == nullptr)
    {
        int y, x;
        board.getEmptyCoordinates(y, x);
        item = new Item(y, x);
        board.add(*item);
    }

    SnakePiece next = snake.nextHead();
    if (next.getX() != item->getX() || next.getY() != item->getY())
    {
        int emptyRow = snake.tail().getY();
        int emptyCol = snake.tail().getX();
        board.add(Empty(emptyRow, emptyCol));
        snake.removePiece();
    }
    else
    {
        delete item;
        item = nullptr;
    }
    // 벽에 박았을 경우에 대한 처리
    

    // 머리와 몸통이 겹치는 경우
    if (next.getX() == snake.getPiece().getX() && next.getY() == snake.getPiece().getY())
    {
        gameOver = true;
        isOver();
    }

    snake.addPiece(next);
    board.add(next);
}

void SnakeGame::redraw()
{
    board.refresh();
}

bool SnakeGame::isOver()
{
    return gameOver;
}