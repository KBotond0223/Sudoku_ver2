#include "numbox.hpp"
#include "graphics.hpp"
using namespace genv;

NumBox::NumBox(Application *parent,int x, int y, double szel, double mag,int number):
    Widget(parent,x,y,szel,mag), _number(number)
{}


void NumBox::rajzol() const{
    canvas can(_szel,_mag);
    can<<move_to(0,0)<<color(0,0,0)<<box(_szel,_mag);

    //Ha a szám le van lock-olva
    if(_locked==true){
        can<<move_to(2,2)<<color(155,155,155)<<box(_szel-4,_mag-4);
        can<<move_to(_szel/2,_mag/2)<<color(0,0,0)<<text(std::to_string(_number));
    }
    //Ha jó a szám
    else if(_number!=0 && _hiba==false && _locked==false){
        can<<move_to(2,2)<<color(255,255,255)<<box(_szel-4,_mag-4);
        can<<move_to(_szel/2,_mag/2)<<color(0,0,0)<<text(std::to_string(_number));
    }
    //Ha nem jó
    else if(_number!=0 && _hiba==true && _locked==false){
        can<<move_to(2,2)<<color(200,0,0)<<box(_szel-4,_mag-4);
        can<<move_to(_szel/2,_mag/2)<<color(0,0,0)<<text(std::to_string(_number));
    }
    gout << stamp(can,_x,_y);
}

void NumBox::set_hiba(bool b){
    _hiba=b;
}

int NumBox::get_num() const{
    return _number;
}

std::string NumBox::get_name() const{
    return _name;
}

void NumBox::set_num(int n){
    if(_locked==false){
            _number=n;
    }
}

void NumBox::micsi(event ev){}

void NumBox::lock(bool b){
    _locked=b;
}
