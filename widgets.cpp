#include "widgets.hpp"
#include "graphics.hpp"
#include "application.hpp"
using namespace genv;

Widget::Widget(Application *parent,int x, int y, int sx, int sy) :
    _parent(parent),_x(x), _y(y), _szel(sx), _mag(sy)
{
    _parent->register_widget(this);
}

bool Widget::benne_van(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_szel && mouse_y>_y && mouse_y<_y+_mag;
}






