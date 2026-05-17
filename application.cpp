#include "application.hpp"
#include <vector>

using namespace genv;


Application::Application(int szel,int mag){
    gout.open(szel,mag);
}

//Ide igazából csak azért kell a szel és mag hogy a clear is meg tudja kapni
void Application::event_loop(int szel,int mag){
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        //A bal egérre mindenki tud reagálni
        if ((ev.type == ev_mouse && ev.button==btn_left) || (ev.type == ev_mouse && ev.button==btn_right) ) {
            for (size_t i=0;i<_widgets.size();i++) {
                if (_widgets[i]->benne_van(ev.pos_x, ev.pos_y)) {
                    //De NumInput és NumBox "mouse" id-val
                    if(_widgets[i]->get_name()=="nb" || _widgets[i]->get_name()=="ni"){
                        focus = i;
                        action("mouse",ev,focus);
                    }
                    //Míg PushButton fájl-t közvetít
                    else{
                        _widgets[i]->micsi(ev);
                    }
                }
            }
        }
        else if(ev.type==ev_key && (ev.keycode==key_up || ev.keycode==key_down))
        {
            //Mivel csak a NumInput-nak van a fel és le arrow-ra eseménye, ezért csak kikeressük az ő indexét a _widgets-ből
            //Bár tudom, hogy ő a 0. indexű, ha ez esetleg változna, akkor is működni fog
            //Pl.: a NumBox-ok vannak először inicializálva, így nem NumInput a 0.
            for(size_t i=0;i<_widgets.size();i++){
                if(_widgets[i]->get_name()=="ni"){
                    action("arrow",ev,i);
                }
            }

        }
        //Ez a törlésre van, csak NumBox tud erre reagálni
        if (focus!=-1 && !(ev.type == ev_mouse && ev.button == btn_left)) {
            _widgets[focus]->micsi(ev);
        }
        //Egy sima fekete képernyő
        clear(szel, mag);
        for (Widget * w : _widgets) {
            w->rajzol();
        }
        //Ha nyertünk kiírja, ha még nem akkor nem lesz ott
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
