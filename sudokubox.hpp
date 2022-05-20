#ifndef SUDOKUBOX_HPP_INCLUDED
#define SUDOKUBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "numbersetbox.hpp"


class SudokuBox : virtual public NumberSetBox{
protected:
    bool _hibas;
    bool _original;
public:
    SudokuBox(int x, int y, int sx, int sy, int number, int minimum, int maximum);
    virtual void draw();
    virtual void writeValue(int keycode);
    virtual void handle(genv::event ev);
};

#endif // SUDOKUBOX_HPP_INCLUDED
