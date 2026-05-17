#include "pushbutton.hpp"
#include <functional>


using namespace genv;

PushButton::PushButton(Application* parent,int x, int y, int sx, int sy, std::string text, std::string fajl):
    Widget(parent,x,y,sx,sy), _text(text), _fajl(fajl)
{

}


void PushButton::rajzol()const{
    canvas can(_szel,_mag);
    can.load_font("LiberationSans-Regular.ttf", 20);
    can<<move_to(0,0)<<color(0,50,0)<<box(_szel,_mag);
    can<<move_to(2,2)<<color(255,255,255)<<box(_szel-4,_mag-4)<<color(0,0,0);
    can<<move_to(_szel/7,_mag/4)<<color(0,0,0)<<text(_text);

    gout<<stamp(can,_x,_y);
}

void PushButton::micsi(event ev){
    if (ev.type == ev_mouse && ev.button == btn_left) {
        if (benne_van(ev.pos_x, ev.pos_y)) {
            //Itt küldi el a buttonben tárolt fájl nevét az actionnek
            _parent->action(_fajl,ev,-1);
        }
    }
}

std::string PushButton::get_data(){
    return _fajl;
}

std::string PushButton::get_name() const{
    return _name;
}
