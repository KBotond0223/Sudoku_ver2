#include "numbox.hpp"
#include "graphics.hpp"
#include "application.hpp"
using namespace genv;

NumBox::NumBox(Application *parent,int x, int y, double szel, double mag,int number):
    Widget(parent,x,y,szel,mag), _number(number)
{}


void NumBox::rajzol() const{
    canvas can(_szel,_mag);
    can<<move_to(0,0)<<color(0,0,0)<<box(_szel,_mag);
    can<<move_to(2,2)<<color(255,255,255)<<box(_szel-4,_mag-4);
    if(_number!=0 && _hiba==false){
        can<<move_to(_szel/2,_mag/2)<<color(0,0,0)<<text(std::to_string(_number));
    }
    else if(_number!=0 && _hiba==true){
        can<<move_to(_szel/2,_mag/2)<<color(200,0,0)<<text(std::to_string(_number));
    }
    gout << stamp(can,_x,_y);
}

void NumBox::micsi(event ev){
    if(ev.type==ev_mouse && ev.button==btn_left && ev.pos_x>_x && ev.pos_x<_x+_szel && ev.pos_y>_y && ev.pos_y<_y+_mag){

    }
}

void NumBox::set_hiba(bool n){
    _hiba=n;
}

int NumBox::get_num() const{
    return _number;
}
