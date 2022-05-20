#include <sstream>

#include "sudokubox.hpp"
using namespace genv;

SudokuBox::SudokuBox(int x, int y, int sx, int sy, int number, int maximum, int minimum)
    :NumberSetBox(x,y,sx,sy,0,0,9)
{
    _hibas=false;
}

void SudokuBox::draw(){
    //main numberbox
    if(!_selected)
        {draw_frame(0,200,200,200); draw_frame(2,0,0,0);}
    else
        {draw_frame(0,200,170,255); draw_frame(2,0,0,0);}

    //number
    std::stringstream ss;
    if(_min<=_number&&_number<=_max)
        ss << _number;
    else{ss<<"-";}
    gout << move_to(_x+_size_x/2-gout.twidth(ss.str())/2, _y+_size_y/2+gout.cdescent()) << color(255,255,255) << text(ss.str());
}

void SudokuBox::handle(event ev){
    if(ev.type==ev_key){
        if(ev.keycode==key_backspace)
            resetNumber();
        else if(ev.keycode==key_enter)
            resetNumber();
        else if(48<=ev.keycode&&ev.keycode<=57)
            writeValue(ev.keycode);
    if(ev.type==ev_mouse&&ev.button!=btn_left)
        _selected=false;
    }
}

void SudokuBox::writeValue(int keycode)
{
        std::stringstream ss;
        char c=keycode;
        ss<<c;
        int input;
        ss>>input;
        _number=input;
}
