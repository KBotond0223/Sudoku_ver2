#ifndef NUMINPUT_HPP
#define NUMINPUT_HPP

#include "graphics.hpp"
#include "widgets.hpp"
#include "application.hpp"

class NumInput : public Widget
{
protected:
    int _number, _interval;
public:
    NumInput(Application*,int x,int y,double szel, double mag, int number, int interval);
    virtual void rajzol() const override;
    virtual void micsi(genv::event) override;
    int data() const;
};
#endif // NUMINPUT_HPP
