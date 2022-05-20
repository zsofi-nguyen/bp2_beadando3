#include "widgets.hpp"
#include "numbersetbox.hpp"
#include "menubar.hpp"
#include "window.hpp"
#include "push_button.hpp"
#include "input_textbox.hpp"

#include "graphics.hpp"
#include "sudokubox.hpp"
#include "logisztikaimenedzser.hpp"
#include <iostream>

using namespace genv;

int main()
{

    GameMaster game;
    game.event_loop();


    return 0;
}
