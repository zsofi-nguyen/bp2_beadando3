#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include <iostream>
#include <string>

class Widget {
protected:
    int _x, _y, _size_x, _size_y;
    bool _selected;
public:
    Widget(int x, int y, int sx, int sy);
    virtual void draw() = 0;
    void draw_frame(int framewidth, int R, int G, int B);
    virtual void handle(genv::event ev) = 0;
    bool is_selected(int mouse_x, int mouse_y);
    virtual ~Widget(){std::cout<<"widget deleted"<<std::endl;};
};

#endif // WIDGETS_HPP_INCLUDED
