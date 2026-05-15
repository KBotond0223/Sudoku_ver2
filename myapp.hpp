#ifndef MYAPP_HPP
#define MYAPP_HPP

#include "application.hpp"
#include "widgets.hpp"
#include "numbox.hpp"
#include "numinput.hpp"
#include "pushbutton.hpp"
#include "jatekmester.hpp"


class MyApp : public Application
{
public:
    MyApp(int, int);
    void action(std::string,int) override;
    void mas_map(int);
protected:
    std::vector<NumBox*> _nbv;
    NumInput * _ni;
    std::vector<PushButton*> _pbv;
};

#endif // MYAPP_HPP
