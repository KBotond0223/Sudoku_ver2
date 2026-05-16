#include "myapp.hpp"
#include "widgets.hpp"
#include "numbox.hpp"
#include "numinput.hpp"
#include "pushbutton.hpp"

using namespace std;
using namespace genv;

MyApp::MyApp(int szel, int mag): Application(szel,mag) {
    _jm = new JatekMester(this);
    _ni= new NumInput(this,50,300,150,100,0,9);
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
            NumBox* nb=new NumBox(this,250+i*42+k*10,100+j*42+l*10,40,40,0);
            _nbv.push_back(nb);
        }
    }
    for(int i=0;i<2;i++){
        PushButton* pb=new PushButton(this,700,100+i*70,100,50,to_string(i+1)+". map",to_string(i+1)+"map.txt");
        _pbv.push_back(pb);
    }
}

void MyApp::action(string id,genv::event ev,int ind){
    if(id=="mouse"){
        if(ev.button==btn_left){
            if(_widgets[ind]->get_name() == "nb"){
                NumBox* nb = dynamic_cast<NumBox*>(_widgets[ind]);
                if(nb){
                    nb->set_num(_ni->data());
                    for(int i = 0; i < _nbv.size(); i++){
                        if(_nbv[i] == nb){
                            int k = i / 9;  // row
                            int l = i % 9;  // column
                            _jm->ellenorMester(_nbv);
                            break;
                        }
                    }
                }
            }
        }
        else{
            for(int i = 0; i < _pbv.size(); i++){
                if(_pbv[i]->get_data() == id){
                    mas_map(i);
                    break;
                }
            }
        }
    }
}

void MyApp::mas_map(int n){
    _jm->tisztit(_nbv);
    _jm->betolt(_pbv[n]->get_data(),_nbv);
}
