#ifndef PUSH_BUTTON_HPP_INCLUDED
#define PUSH_BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <functional>

class PushButton : public Widget{
protected:
    bool _pushed;  //kell?
    std::string _text;
    std::function<void()> _f;

public:
    PushButton(int x, int y, int sx, int sy, std::string pushbutton_text,std::function<void()> f);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_pushed() ;
};

#endif // PUSH_BUTTON_HPP_INCLUDED
