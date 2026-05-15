#include "jatekmester.hpp"
#include "numbox.hpp"
#include <fstream>

JatekMester::JatekMester(Application* parent):
    _parent(parent)
{
    _parent->register_jm(this);
}


struct Koor{
    int _sor;
    int _oszlop;
    int _num;
};

void JatekMester::ellenor(int k, int l,std::vector<NumBox*> nbv){
    int x=0, y=0;
    bool van_hiba=false;
    if(k/3<1){
        x=0;
    }
    if(k/3>=2){
        x=6;
    }
    else{
        x=3;
    }
    if(l/3<1){
        y=0;
    }
    if(l/3>=2){
        y=6;
    }
    else{
        y=3;
    }
    int most_ind=k*9+l;
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            int check_ind=i*9+j;
            if(most_ind!=check_ind && nbv[most_ind]->get_num()==nbv[check_ind]->get_num()){
                nbv[most_ind]->set_hiba(true);
                nbv[check_ind]->set_hiba(true);
                van_hiba=true;
            }
        }
    }
    for(int i=0;i<9;i++){
        if(i!=k && nbv[i*9+l]->get_num()==nbv[k*9+l]->get_num()){
            nbv[k*9+l]->set_hiba(true);
            nbv[i*9+l]->set_hiba(true);
            van_hiba=true;
        }
    }
    for(int j=0;j<9;j++){
        if(j!=l && nbv[k*9+j]->get_num()==nbv[k*9+l]->get_num()){
            nbv[k*9+l]->set_hiba(true);
            nbv[k*9+j]->set_hiba(true);
            van_hiba=true;
        }
    }
    if(van_hiba==false){
        nbv[k*9+l]->set_hiba(false);
    }
}

void JatekMester::betolt(std::string fajl,std::vector<NumBox*> nbv){
    std::ifstream be(fajl);
    std::vector<Koor> u_v;
    while(be.good()){
        int o,s,n;
        be>>o>>s>>n;
        Koor u;
        u._sor=s;
        u._oszlop=o;
        u._num=n;
        u_v.push_back(u);
    }
    for(int i=0;i<u_v.size();i++){
        nbv[u_v[i]._sor*9+u_v[i]._oszlop]->set_num(u_v[i]._num);
        nbv[u_v[i]._sor*9+u_v[i]._oszlop]->lock(true);
    }
}

void JatekMester::tisztit(std::vector<NumBox*> nbv){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            nbv[i*9+j]->lock(false);
            nbv[i*9+j]->set_num(0);
        }
    }
}
