#ifndef LOGISZTIKAIMENEDZSER_HPP_INCLUDED
#define LOGISZTIKAIMENEDZSER_HPP_INCLUDED

#include "graphics.hpp"
#include "push_button.hpp"
#include "sudokubox.hpp"
#include <iostream>

using namespace genv;

const int ROW=9;
const int COL=9;

class GameMaster{
private:
    std::vector<std::vector<SudokuBox*>> sudokuTable;
    std::vector<Widget*> _widgets;
    event ev;
    int _focusRow=-1;
    int _focusCol=-1;
    int _focusWidget=-1;
    bool exited=false;

public:
    GameMaster();
    void event_loop();
    void addSudokuBox(SudokuBox *sb);
    void addWidget(Widget *w);
    ~GameMaster();
};



#endif // LOGISZTIKAIMENEDZSER_HPP_INCLUDED
