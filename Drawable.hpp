#include <ncurses.h>
#ifndef __DRAWABLE__
#define __DRAWABLE__
class Drawable
{
public:
    Drawable();
    Drawable(int y, int x, chtype ch);
    int getX();
    int getY();
    chtype getIcon();
    void setIcon(chtype ch);
protected:
    int y, x;
    chtype icon;
};

#endif