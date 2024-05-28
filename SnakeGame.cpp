#include "SnakeGame.hpp"
#include <ctime>
#include <string>

SnakeGame::SnakeGame(int height, int width) : board(height, width), item(nullptr), gameOver(false)
{
    initialize(); // 보드 객체를 만들어준다.
}

SnakeGame::~SnakeGame()
{
    delete item;
    delete itemPoison;
    delete gateA;
    delete gateB;
}

void SnakeGame::initialize()
{
    board.drawMap();
    gateA = nullptr;
    gateB = nullptr;
    itemPoison = nullptr;
    item = nullptr;
    gameOver = false;
    board.initialize();
    
    srand(time(NULL));
    snake.setDirection(left);

    SnakePiece next(10, 35); // 나중에 시작할 좌표를 줘야함
    board.add(next);
    snake.addPiece(next);

    next = snake.nextHead();
    board.add(next);
    snake.addPiece(next);

    //snake.setDirection(right);

    next = snake.nextHead();
    next.setIcon('*');
    board.add(next);
    snake.addPiece(next);
}
// 꾹 누르게 되면 값은 변화하지 않는게 맞는데 단 input의 빠르게 많이 반복하여
// update를 빠르고 많이 불러오게 되는 문제로 인해 뱀이 계속해서 움직임
void SnakeGame::input()
{
    int input = board.getInput();
    if (input != ERR)
    {
    switch (input)
    {
    case KEY_UP: // 반대방향 눌리지 않아야함, 같은 방향을 누를 수 없어야함
        if (snake.getDirection() != down) snake.setDirection(up);
        break;
    case KEY_DOWN:
        if (snake.getDirection() != up) snake.setDirection(down);

        break;
    case KEY_LEFT:
        if (snake.getDirection() != right) snake.setDirection(left);
        break;
    case KEY_RIGHT:
        if (snake.getDirection() != left) snake.setDirection(right);
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
    // 게이트 생성
    if (gateA == nullptr && gateB == nullptr)
    {
        int y, x;
        board.getWallCoordinates(y, x);
        gateA = new Gate(y, x);
        board.getWallCoordinates(y, x);
        gateB = new Gate(y, x);
        board.add(*gateA);
        board.add(*gateB);
    }
    SnakePiece next = snake.nextHead();
    // 아이템이 아닌 곳을 다니는 경우
    if (next.getX() != item->getX() || next.getY() != item->getY())
    {
        int emptyRow = snake.tail().getY();
        int emptyCol = snake.tail().getX();
        next.setIcon('*');
        board.add(Empty(emptyRow, emptyCol));
        snake.removePiece();
    }
    else
    {
        next.setIcon('*');
        score += 100; // 점수
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
    // 게이트 통과 구현 방향조절 해줘야함 -> 미구현, tail이 통과한 후엔 두 게이트를 nullptr로 만들고 벽을 다시 x로 해야함
    if (mvwinch(board.getBoardWin(), next.getY(), next.getX()) == 'O') 
    {
        // A -> B로
        if (next.getX() == gateA->getX() && next.getY() == gateA->getY())
        {
            next.setX(gateB->getX());
            next.setY(gateB->getY());
            board.add(next);
        }// B -> A로
        else if (next.getX() == gateB->getX() && next.getY() == gateB->getY())
        {
            next.setX(gateA->getX());
            next.setY(gateA->getY());
            board.add(next);
        }
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
        }
    }
    // 헤드가 벽에 박았을 경우
    if (mvwinch(board.getBoardWin(), next.getY(), next.getX()) == 'X') 
    {
        next.setIcon('X');
        gameOver = true;
    }
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
    if (snake.getPiece().size() > 1) 
    {
        SnakePiece body = snake.getPiece().back();
        body.setIcon('#');
        board.add(body);
    }
}
// 게이트가 나가는 곳이 가능한 곳인지 판별한다
bool SnakeGame::isVaildGate(SnakePiece& next)
{
    
    return true;   
}
void SnakeGame::redraw()
{
    if (gameOver)
    {
        int height, width;
        getmaxyx(board.getBoardWin(), height, width);
        std::string gameOverMsg = "Game Over";
        // c_str 을 재할당 하는 방식으로 사용 불가능
        // char *gameOverMsg = gameOverMsg.c_str;
        mvwprintw(board.getBoardWin(), height / 2, (width - gameOverMsg.size()) / 2, "%s", gameOverMsg.c_str());
    }
    board.refresh();
}

bool SnakeGame::isOver()
{
    return gameOver;
}