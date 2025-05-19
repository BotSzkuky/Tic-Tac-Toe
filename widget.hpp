#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"

class Widget {
protected:
    int _x, _y, _size_x, _size_y;

public:
    Widget(int x, int y, int sx, int sy)
        : _x(x), _y(y), _size_x(sx), _size_y(sy) {}

    virtual void draw() const = 0;
    virtual void handle(genv::event ev) = 0;

    bool is_selected(int mouse_x, int mouse_y) const {
        return mouse_x > _x && mouse_x < _x + _size_x &&
               mouse_y > _y && mouse_y < _y + _size_y;
    }
};

#endif
