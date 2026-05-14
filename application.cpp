#include "application.hpp"

using namespace genv;

Application::Application(int width, int height)

{
    gout.open(width,height);
}

void Application::ellenor(int focus){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int v=
        }
    }
}

void Application::event_loop(int width,int height){
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        gout<<move_to(0,0)<<color(0,0,0)<<box(width,height);
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<_widgets.size();i++) {
                if (_widgets[i]->benne_van(ev.pos_x, ev.pos_y)) {
                    focus = i;
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
