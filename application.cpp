#include "application.hpp"
#include <vector>

using namespace genv;


Application::Application(int szel,int mag){
    gout.open(szel,mag);
}


void Application::event_loop(int szel,int mag){

    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if ((ev.type == ev_mouse && ev.button==btn_left) || (ev.type == ev_mouse && ev.button==btn_right) ) {
            for (size_t i=0;i<_widgets.size();i++) {
                if (_widgets[i]->benne_van(ev.pos_x, ev.pos_y)) {
                    if(_widgets[i]->get_name()=="nb" || _widgets[i]->get_name()=="ni"){
                        focus = i;
                        action("mouse",ev,focus);
                    }
                    else{
                        _widgets[i]->micsi(ev);
                    }
                }
            }
        }
        if (focus!=-1 && !(ev.type == ev_mouse && ev.button == btn_left)) {
            _widgets[focus]->micsi(ev);
        }
        clear(szel, mag);
        for (Widget * w : _widgets) {
            w->rajzol();
        }
        win_msg();
        gout << refresh;
    }
}

void Application::clear(int szel, int mag){
    gout<<move_to(0,0)<<color(0,0,0)<<box(szel,mag);
}

void Application::register_widget(Widget *w){
    _widgets.push_back(w);
}

void Application::register_jm(JatekMester *jm){
    _jm=jm;
}
