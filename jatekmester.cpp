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

void JatekMester::ellenorMester(std::vector<NumBox*> nbv){
    //Minden NumBox-ot "hibátlanná" teszünk
    for(int i = 0; i < 81; i++){
        nbv[i]->set_hiba(false);
    }
    //Amelyik NumBox-ban van szám azt lecsekkoljuk
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(nbv[i*9+j]->get_num() != 0){
                ellenor(i, j, nbv);
            }
        }
    }
}

void JatekMester::ellenor(int k, int l,std::vector<NumBox*> nbv){
    int x=0, y=0;
    bool van_hiba=false;
    //Megnézzük melyik 3x3-as blokkban van
    //Először oszlop szerint
    if(k/3<1){
        x=0;
    }
    else if(k/3>=2){
        x=6;
    }
    else{
        x=3;
    }
    //Aztán sorok szerint
    if(l/3<1){
        y=0;
    }
    else if(l/3>=2){
        y=6;
    }
    else{
        y=3;
    }
    //Itt meg is nézzük a 3x3-as blokkot
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
    //Itt oszlop-ellenőrzés
    for(int i=0;i<9;i++){
        if(i!=k && nbv[i*9+l]->get_num()==nbv[k*9+l]->get_num()){
            nbv[k*9+l]->set_hiba(true);
            nbv[i*9+l]->set_hiba(true);
            van_hiba=true;
        }
    }
    //Itt sor-ellenőrzés
    for(int j=0;j<9;j++){
        if(j!=l && nbv[k*9+j]->get_num()==nbv[k*9+l]->get_num()){
            nbv[k*9+l]->set_hiba(true);
            nbv[k*9+j]->set_hiba(true);
            van_hiba=true;
        }
    }
    //Ha no problemo akkor nincs hiba (kb egyértelmű)
    if(van_hiba==false){
        nbv[k*9+l]->set_hiba(false);
    }
}

void JatekMester::betolt(std::string fajl,std::vector<NumBox*> nbv){
    std::ifstream be(fajl);

    std::vector<Koor> u_v;
    while(be.good()){
        //o=oszlopszám
        //s=sorszám
        //n=maga a szám
        int o,s,n;
        be>>o>>s>>n;
        Koor u;
        u._sor=s;
        u._oszlop=o;
        u._num=n;
        u_v.push_back(u);
    }
    //Beállítjuk a fájlból kinyert számokat, úgy hogy aztán ne lehessen azokat változtatni
    for(int i=0;i<u_v.size();i++){
        nbv[u_v[i]._sor*9+u_v[i]._oszlop]->set_num(u_v[i]._num);
        nbv[u_v[i]._sor*9+u_v[i]._oszlop]->lock(true);
    }
}


void JatekMester::tisztit(std::vector<NumBox*> nbv){
    for(int i=0;i<81;i++){
        nbv[i]->set_hiba(false);
        nbv[i]->lock(false);
        nbv[i]->set_num(0);
    }
}
