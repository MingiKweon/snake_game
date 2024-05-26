#include <ncurses.h>
#include "Map.hpp"

// using namespace std;

Map::Map()
{
    map;
}
int (*Map::getMap(int st))[42] {
    return map[st];
}
