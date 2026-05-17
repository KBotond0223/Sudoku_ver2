#include "numbox.hpp"
#include "graphics.hpp"
using namespace genv;

NumBox::NumBox(Application *parent,int x, int y, double szel, double mag,int number):
    Widget(parent,x,y,szel,mag), _number(number)
{}


void NumBox::rajzol() const{
    canvas can(_szel,_mag);
    can<<move_to(0,0)<<color(0,0,0)<<box(_szel,_mag);
    can.load_font("LiberationSans-Regular.ttf", 20);
    //Ha a szám le van lock-olva
    if(_locked==true){
        //Ha hibás, ez csak azért van hogy a felhasználó láthassa mivel
        //is van probléma
        if(_hiba==true){
            can<<move_to(2,2)<<color(200,0,0)<<box(_szel-4,_mag-4);
            can<<move_to(_szel/2-5,_mag/2-15)<<color(0,0,0)<<text(std::to_string(_number));
        }
        //Amikor minden bueno
        else{
            can<<move_to(2,2)<<color(155,155,155)<<box(_szel-4,_mag-4);
            can<<move_to(_szel/2-5,_mag/2-15)<<color(0,0,0)<<text(std::to_string(_number));
        }

    }
    //Ha jó a szám
    else if(_number!=0 && _hiba==false && _locked==false){
        can<<move_to(2,2)<<color(255,255,255)<<box(_szel-4,_mag-4);
        can<<move_to(_szel/2-5,_mag/2-15)<<color(0,0,0)<<text(std::to_string(_number));
    }
    //Ha nem jó
    else if(_number!=0 && _hiba==true){
        can<<move_to(2,2)<<color(200,0,0)<<box(_szel-4,_mag-4);
        can<<move_to(_szel/2-5,_mag/2-15)<<color(0,0,0)<<text(std::to_string(_number));
    }
    //Ha a szám 0
    else{
        can<<move_to(2,2)<<color(255,255,255)<<box(_szel-4,_mag-4);
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

bool NumBox::get_hiba() const{
    return _hiba;
}

//Nem csinál semmit, de enélkül abstract
void NumBox::micsi(event ev){}

void NumBox::lock(bool b){
    _locked=b;
}
