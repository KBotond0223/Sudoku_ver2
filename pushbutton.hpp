#ifndef PUSHBUTTON_HPP
#define PUSHBUTTON_HPP

#include "graphics.hpp"
#include "widgets.hpp"
#include "application.hpp"

class PushButton : public Widget
{
protected:
    std::string _text;
    std::string _fajl;
    std::string _name="pb";
public:
    PushButton(Application*,int,int,int,int,std::string,std::string);
    virtual void rajzol() const override;
    virtual void micsi(genv::event) override;
    std::string get_data();
    virtual std::string get_name() const override;
};

#endif // PUSHBUTTON_HPP
