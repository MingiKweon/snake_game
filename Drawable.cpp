#include <ncurses.h>
#include "Drawable.hpp"

Drawable::Drawable()
    {
        y = 0;
        x = 0;
        icon = ' ';
    }
Drawable::Drawable(int y, int x, chtype ch)
    {
        this->y = y;
        this->x = x;
        this->icon = ch;
    }
int Drawable::getX()
    {
        return x;
    }
int Drawable::getY()
    {
        return y;
    }
void Drawable::setX(int x)
{
    this->x = x;
}
void Drawable::setY(int y)
{
    this->y = y;
}
void Drawable::setIcon(chtype ch)
    {
        icon = ch;
    }
chtype Drawable::getIcon()
    {
        return icon;
    }
