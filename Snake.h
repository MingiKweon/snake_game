#include <vector>
using namespace std;

class Snake
{
public:
    Snake();
    ~Snake();
    
    

private:
    vector<vector<int, int>> snakeHead;
    vector<vector<int, int>> snakeBody;
};
