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
        PushButton* pb=new PushButton(this,400,100+i*70,100,50,to_string(i+1)+". map",to_string(i+1)+"map.txt");
        _pbv.push_back(pb);
    }
}

void MyApp::action(string id,int ind){

}

void MyApp::mas_map(int n){
    _jm->tisztit(_nbv);
    _jm->betolt(_pbv[n]->get_data(),_nbv);
}
