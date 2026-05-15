#include "application.hpp"
#include <vector>

using namespace genv;


Application::Application(int szel,int mag){
    gout.open(szel,mag);
}


void Application::event_loop(){

    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<_widgets.size();i++) {
                if (_widgets[i]->benne_van(ev.pos_x, ev.pos_y)) {
                    focus = i;
                    action("mouse",focus);
                }
            }
        }
        if (focus!=-1) {
            _widgets[focus]->micsi(ev);
        }
        for (Widget * w : _widgets) {
            w->rajzol();
        }
        gout << refresh;
    }
}

void Application::register_widget(Widget *w){
    _widgets.push_back(w);
}

void Application::register_jm(JatekMester *jm){
    _jm=jm;
}
