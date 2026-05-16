#include "numinput.hpp"
#include "graphics.hpp"
#include "application.hpp"
using namespace genv;


NumInput::NumInput(Application *parent,int x, int y, double szel, double mag,int number, int interval):
    Widget(parent,x,y,szel,mag), _number(number), _interval(interval)
{}

void NumInput::rajzol() const{
    canvas can(_szel,_mag);
    //Maga a widget
    can << move_to(0,0) << color(100,100,100) << box(_szel,_mag);
    //Szám kijelző
    can << move_to(_szel/12,_mag/8) << color(0,50,0) << box_to(((_szel/12)*7),_mag/8*7)
        << move_to(_szel/3-(gout.twidth(std::to_string(_number))/2),_mag/2)<<color(0,200,0)<< text(std::to_string(_number));
    //Fel-Le gombok
    can << move_to(((_szel/24)*17),_mag/16) << color(130,130,130) << box_to(_szel/24*23,_mag/16*7);
    can << move_to(((_szel/24)*17),_mag/16*9) << color(130,130,130) << box_to(_szel/24*23,_mag/16*15);
    //fel-le nyíl
    can << move_to(((_szel/12)*9),_mag/16*5) << color(100,0,0) << line_to(_szel/12*11,_mag/16*5)<<line_to(_szel/12*10,_mag/16*2)<<line_to(((_szel/12)*9),_mag/16*5);
    can << move_to(((_szel/12)*9),_mag/16*11) << color(100,0,0) << line_to(_szel/12*11,_mag/16*11)<<line_to(_szel/12*10,_mag/16*14)<<line_to(((_szel/12)*9),_mag/16*11);
    gout << stamp(can,_x,_y);
}

void NumInput::micsi(event ev){
    //page gombok 10-el mennek fel-le
    if (ev.type == ev_key && ev.keycode == key_pgdn) {
        _number-=10;
        if(_number<0){
            _number=0;
        }
    }
    if (ev.type == ev_key && ev.keycode == key_pgup) {
        _number+=10;
        if(_number>_interval){
            _number=_interval;
        }
    }
    //nyilakkal vagy kurzorral rányomva a gombokra 1-el mennek fel-le
    if((ev.type == ev_mouse && ev.button==btn_left && (ev.pos_x>(_x+_szel/24*17) && ev.pos_x<(_x+_szel/24*23)) && (ev.pos_y>_y+_mag/16 && ev.pos_y<_y+_mag/16*7))
        || (ev.type == ev_key && ev.keycode == key_up)){
        _number+=1;
        if(_number>_interval){
            _number=_interval;
        }
    }
    if((ev.type == ev_mouse && ev.button==btn_left && (ev.pos_x>(_x+_szel/24*17) && ev.pos_x<(_x+_szel/24*23)) && (ev.pos_y>_y+_mag/16*9 && ev.pos_y<_y+_mag/16*15))
        || (ev.type == ev_key && ev.keycode == key_down)){
        _number-=1;
        if(_number<0){
            _number=0;
        }
    }
}


int NumInput::data() const{
    return _number;
}

std::string NumInput::get_name() const{
    return _name;
}

