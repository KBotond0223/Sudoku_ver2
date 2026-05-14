#ifndef NUMBOX_HPP
#define NUMBOX_HPP

#include "graphics.hpp"
#include "widgets.hpp"
#include "application.hpp"

class NumBox : public Widget
{
protected:
    int _number;
    bool _hiba=false;
public:
    NumBox(Application*,int x,int y,double szel, double mag, int number);
    virtual void rajzol() const override;
    virtual void micsi(genv::event) override;
    void set_hiba(bool);
    int get_num() const;
};

#endif // NUMBOX_HPP
