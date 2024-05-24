#include "SnakeGame.hpp"
#include <ctime>

SnakeGame::SnakeGame(int height, int width) : board(height, width), item(nullptr), gameOver(false)
{
    initialize(); // 보드 객체를 만들어준다.
}

SnakeGame::~SnakeGame()
{
    //delete item;
    delete itemPoison;
}

void SnakeGame::initialize()
{
    itemPoison = nullptr;
    item = nullptr;
    gameOver = false;
    board.initialize();
    
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
    time_t curTime = time(nullptr); // 현재 시간
    // 아이템 생성
    if (item == nullptr)
    {
        int y, x;
        board.getEmptyCoordinates(y, x);
        item = new Item(y, x);
        board.add(*item);
    }
    
    // 독 아이템 생성
    if (itemPoison == nullptr)
    {
        int y, x;
        board.getEmptyCoordinates(y, x);
        itemPoison = new ItemPoison(y, x);
        board.add(*itemPoison);
    }

    SnakePiece next = snake.nextHead();
    // 아이템이 아닌 곳을 다니는 경우
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
    // 독을 먹은 경우
    if (next.getX() == itemPoison->getX() && next.getY() == itemPoison->getY())
    {
        
        int emptyRow = snake.tail().getY();
        int emptyCol = snake.tail().getX();
        board.add(Empty(emptyRow, emptyCol));
        snake.removePiece();
        delete itemPoison;
        itemPoison = nullptr;
    }

    // 헤드가 몸에 박았을 경우에 대한 처리
    // 헤드를 제외한 덱이 0이되는 경우가 발생할 수 있음 , 몸길이가 3미만 게임오버
    std::deque<SnakePiece> pieces = snake.getPiece(); // 헤드를 제외한 덱을 복사해서 구현

    if (pieces.size() < 1) 
    {
        gameOver = true;
        snake.addPiece(next);
        board.add(next);

    }

    for (auto& piece : pieces) {
        if (next.getX() == piece.getX() && next.getY() == piece.getY()) 
        {
            gameOver = true;
            //return;
        }
    }
    // 헤드가 벽에 박았을 경우 >> 벽 구현이 필요함

    // 5초마다 아이템이 생겼다 사라짐
    if (item != nullptr && difftime(curTime, item->saveTime) >= 5.0) // difftime의 반환형은 double이다
    {
        int itemRow = item->getY();
        int itemCol = item->getX();
        board.add(Empty(itemRow, itemCol));
        delete item;
        item = nullptr;
    }
    // 위와 동일 독 아이템
    if (itemPoison != nullptr && difftime(curTime, itemPoison->saveTime) >= 5.0) // difftime의 반환형은 double이다
    {
        int itemPoisonRow = itemPoison->getY();
        int itemPoisonCol = itemPoison->getX();
        board.add(Empty(itemPoisonRow, itemPoisonCol));
        delete itemPoison;
        itemPoison = nullptr;
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