#include "graphics.hpp"
#include "push_button.hpp"

using namespace genv;

PushButton::PushButton(int x, int y, int sx, int sy, std::string text, std::function<void()> f)
    : Widget(x,y,sx,sy), _text(text), _f(f)
{
    _pushed=false;
}

void PushButton::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    if(_selected){
        gout << move_to(_x, _y) << color(255,100,100) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    }
    if (_pushed) {
        gout << move_to(_x, _y) << color(255,100,100) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(180,200,250) << box(_size_x-4, _size_y-4);
    }
    gout << move_to(_x+_size_x/2-gout.twidth(_text)/2,_y+_size_y/2+gout.cdescent()) << color(255,255,255) << text(_text);
}

void PushButton::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _pushed = !_pushed;
    }
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y)) {
        _selected = true;
    }
    else{
        _selected=false;
    }
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _f();
    }
}
bool PushButton::is_pushed()
{
    return _pushed;
}
