#ifndef NUMBERSETBOX_HPP_INCLUDED
#define NUMBERSETBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class NumberSetBox : public Widget{
protected:
    int _number;
    int _max, _min;

public:
    NumberSetBox(int x, int y, int sx, int sy, int number, int minimum, int maximum);
    virtual void draw();
    void modNumber(int increment);
    virtual void writeValue(int keycode);
    void setValue(int number);
    void deleteDigit();
    void resetNumber();
    virtual void handle(genv::event ev);
    int get_value();
};

#endif // NUMBERSETBOX_HPP_INCLUDED
