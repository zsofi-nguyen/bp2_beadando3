#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy) : _x(x), _y(y), _size_x(sx), _size_y(sy)
{
    _selected=false;
}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

void Widget::draw_frame(int framewidth, int R, int G, int B)
{
    gout << move_to(_x+framewidth, _y+framewidth) << color(R,G,B) << box(_size_x-framewidth*2, _size_y-framewidth*2);
}
