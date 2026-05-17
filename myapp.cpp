#include "myapp.hpp"
#include "widgets.hpp"
#include "numbox.hpp"
#include "numinput.hpp"
#include "pushbutton.hpp"

using namespace std;
using namespace genv;

//Ezek csak a konstruktorok
MyApp::MyApp(int szel, int mag): Application(szel,mag) {
    _jm = new JatekMester(this);
    _ni= new NumInput(this,50,300,150,100,1,9);
    int k=0;
    for(int i=0;i<9;i++){
        if(i%3==0 && i!=0){
            k++;
        }

        int l=0;
        for(int j=0;j<9;j++){

            if(j%3==0 && j!=0){
                l++;
            }
            NumBox* nb=new NumBox(this,250+i*42+k*10,200+j*42+l*10,40,40,0);
            _nbv.push_back(nb);
        }
    }
    for(int i=0;i<5;i++){
        PushButton* pb=new PushButton(this,700,200+i*70,100,50,to_string(i+1)+". map","map"+to_string(i+1)+".txt");
        _pbv.push_back(pb);
    }
}

void MyApp::action(string id,genv::event ev,int ind){
    if(id=="mouse"){
        if(ev.button==btn_left){
            //Ha NumBox-ra kattintottunk
            if(_widgets[ind]->get_name() == "nb"){
                NumBox* nb = dynamic_cast<NumBox*>(_widgets[ind]);
                if(nb){
                    //Szám beállítása a NumInput-tól
                    nb->set_num(_ni->data());
                    //NumBox-ok ellenőrzése
                    _jm->ellenorMester(_nbv);
                    //Ha igaz akkor nyertünk
                    if(_jm->megold(_nbv)==true){
                        set_jippie(true);
                    }

                }
            }
            //Ha NumInput-ar kattintottunk
            else if(_widgets[ind]->get_name() == "ni"){
                _widgets[ind]->micsi(ev);
            }
        }
        //Egyszerűbb törlés
        if(ev.button==btn_right){
            if(_widgets[ind]->get_name() == "nb"){
                NumBox* nb = dynamic_cast<NumBox*>(_widgets[ind]);
                if(nb){
                    //Szám beállítása 0-ra
                    nb->set_num(0);
                    _jm->ellenorMester(_nbv);
                }
            }
        }

    }
    //Ha "arrow" akkor csak a NumInput tud rá reagálni
    //Így nem is kell használni a NumInput gombjait, elég ha akárhol arrow-t nyomunk
    else if(id=="arrow"){
        _widgets[ind]->micsi(ev);
    }
    //Ha nem "mouse" az id akkor az id egy fajl neve
    //Ezért itt biztosan egy PushButton lett lenyomva
    else{
        for(int i=0; i<_pbv.size(); i++){
            if(_pbv[i]->get_data()==id){
                mas_map(i);
                break;
            }
        }
    }
}

void MyApp::set_jippie(bool b){
    _jippie=b;
}

void MyApp::win_msg() const{
    //Ha nyertünk akkor ezt írja ki
    if(_jippie==true){
        gout.load_font("LiberationSans-Regular.ttf", 20);
        gout<<move_to(400,50)<<color(255,51,153)<<text("OH MY GOD!!!!");
        gout<<move_to(400,100)<<color(0,255,255)<<text("You've Won!");
        gout<<move_to(400,150)<<color(255,51,255)<<text("Feel free to try any other map");
    }
}

void MyApp::mas_map(int n){
    //Ha más map-ot játszunk akkor ez legyen hamis
    set_jippie(false);
    _jm->tisztit(_nbv);
    _jm->betolt(_pbv[n]->get_data(),_nbv);
}
