#include "logisztikaimenedzser.hpp"

GameMaster::GameMaster()
    //:sudokuTable(std::vector<std::vector<SudokuBox*>>(ROW, std::vector<SudokuBox*>(COL, nullptr)))
{
    gout.open(800,600);

    for(int row=0; row<ROW; row++)
    {
        std::vector<SudokuBox*> v;
        for(int col=0; col<COL; col++)
        {
            SudokuBox *sbPtr = new SudokuBox(150+row*45,100+col*45,45,45,0,9,0);
            sbPtr->draw();
            v.push_back(sbPtr);
        }
        sudokuTable.push_back(v);
    }

    /*NumberSetBox *nb = new NumberSetBox(150,30,100,40,0,-100,100);
    _widgets.push_back(nb);
    nb->draw();
    SudokuBox *ptr=sudokuTable[0][0];
    PushButton*pb = new PushButton(280,30,40,40,"pb",[ptr](){ptr->setValue(8);});
    _widgets.push_back(pb);
    nb->draw();
    NumberSetBox *sbPtr = new NumberSetBox(150+10*45,100+10*45,45,45,0,0,9);
    _widgets.push_back(sbPtr);
    sbPtr->draw();*/
    gout << refresh;
}

GameMaster::~GameMaster()
{
    for(int row=0; row<ROW; row++){
        for(int col=0; col<COL; col++)
        {
            delete sudokuTable[row][col];
        }
    }
    for(size_t i=0;i<_widgets.size();i++)
    {
        delete _widgets[i];
    }
    std::cout << "vege" << std::endl;
}

void GameMaster::event_loop()
{
    while(gin >> ev && !exited)
    {
        if(ev.keycode==key_escape) {exited=true;}
        if(ev.type==ev_mouse && ev.button==btn_left)
        {
            for(size_t i=0;i<_widgets.size();i++)
            {
                if(_widgets[i]->is_selected(ev.pos_x,ev.pos_y))
                {
                    _focusWidget=i;
                }
            }
            for(int row=0;row<ROW;row++)
            {
                for(int col=0;col<COL;col++)
                {
                    if(sudokuTable[row][col]->is_selected(ev.pos_x,ev.pos_y))
                    {
                        _focusRow=row;
                        _focusCol=col;
                        std::cout<<_focusRow<<" "<<_focusCol<<std::endl;
                        break;
                    }
                }

            }

        }
        if(_focusWidget!=-1)
        {
            _widgets[_focusWidget]->handle(ev);
        }
        for(Widget *w: _widgets)
        {
            w->draw();
        }
        if(_focusRow!=-1&&_focusCol!=-1)
        {
            sudokuTable[_focusRow][_focusCol]->handle(ev);
        }
        for(std::vector<SudokuBox*> r: sudokuTable)
        {
            for(SudokuBox* sb: r)
                sb->draw();
        }
        gout << refresh;
    }
}

void GameMaster::addWidget(Widget *w)
{
    _widgets.push_back(w);
    w->draw();
}
