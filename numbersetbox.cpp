#include "graphics.hpp"
#include "widgets.hpp"
#include "numbersetbox.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace genv;

NumberSetBox::NumberSetBox(int x, int y, int sx, int sy, int number, int minimum, int maximum)
    : Widget(x,y,sx,sy), _number(number), _min(minimum), _max(maximum)
{}

void NumberSetBox::draw(){
    //main numberbox
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

    //number
    std::stringstream ss;
    if(_min<=_number&&_number<=_max)
        ss << _number;
    else{ss<<"--";}
    gout << move_to(_x+_size_x/2-gout.twidth(ss.str())/2, _y+_size_y/2+gout.cdescent()) << color(255,255,255) << text(ss.str());
}

void NumberSetBox::handle(event ev){
    if(ev.type==ev_key){
        if(ev.keycode == key_up)
            modNumber(1);
        else if(ev.keycode == key_down)
            modNumber(-1);
        else if(ev.keycode == key_pgup)
            modNumber(10);
        else if(ev.keycode == key_pgdn)
            modNumber(-10);
        else if(ev.keycode==key_backspace)
            deleteDigit();
        else if(ev.keycode==key_enter)
            resetNumber();
        else if(48<=ev.keycode&&ev.keycode<=57)
            writeValue(ev.keycode);
    }
}

void NumberSetBox::modNumber(int increment)
{
    if(_number+increment>=_min&&_number+increment<=_max)
        _number+=increment;
}

void NumberSetBox::writeValue(int keycode)
{
        std::stringstream ss;
        char c=keycode;
        ss<<c;
        int input;
        ss>>input;

        int leendo=_number*10+input;
        if(_min<=leendo&&leendo<=_max)
            _number=_number*10+input;
}

void NumberSetBox::setValue(int number)
{
    _number=number;
}

void NumberSetBox::deleteDigit()
{
    setValue(0);
    /*std::stringstream ss;
    ss<<_number;
    std::string s=ss.str();
    s.pop_back();
    ss<<s;
    ss>>_number;
    */
}

void NumberSetBox::resetNumber()
{
    _number=0;
}

int NumberSetBox::get_value(){
    return _number;
}

/*//up button
    gout << move_to(_x+_size_x-_button_width, _y) << color(255,255,255) << box(_button_width, _size_y/2);
    gout << move_to(_x+_size_x-_button_width+1, _y+1) << color(200,200,200) << box(_button_width-2, _size_y/2-2);
    //down button
    gout << move_to(_x+_size_x-_button_width, _y+_size_y/2) << color(255,255,255) << box(_button_width, _size_y/2);
    gout << move_to(_x+_size_x-_button_width+1, _y+_size_y/2+1) << color(200,200,200) << box(_button_width-2, _size_y/2-2);
    //up arrow
    gout << move_to(_x+_size_x-_button_width/2-2, _y+_size_y/4+2) << color(0,0,0) << line_to(_x+_size_x-_button_width/2, _y+_size_y/4-2) << line_to(_x+_size_x-_button_width/2+2, _y+_size_y/4+2);
    //down arrow
    gout << move_to(_x+_size_x-_button_width/2-2, _y+_size_y*3/4-2) << color(0,0,0) << line_to(_x+_size_x-_button_width/2, _y+_size_y*3/4+2) << line_to(_x+_size_x-_button_width/2+2, _y+_size_y*3/4-2);
    */
