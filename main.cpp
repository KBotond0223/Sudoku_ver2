#include "widgets.hpp"
#include "application.hpp"
#include "numbox.hpp"
#include "numinput.hpp"

using namespace std;



class MyApp: public Application
{

protected:
    vector<NumBox*> nbv;
    NumInput * ni;

public:
    MyApp(int width, int height):
        Application(width,height)
    {
        ni= new NumInput(this,50,300,150,100,0,9);
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
                nbv.push_back(new NumBox(this,250+i*42+k*10,100+j*42+l*10,40,40,0));
            }
        }
    }

};


int main()
{
    MyApp app(1000,800);
    app.event_loop(1000,800);
    return 0;
}
