#ifndef NUMINPUT_HPP
#define NUMINPUT_HPP

#include "widgets.hpp"

class NumInput : public Widget
{
protected:
    int _number, _interval;
    std::string _name="ni";
public:
    NumInput(Application*,int x,int y,double szel, double mag, int number, int interval);
    virtual void rajzol() const override;
    virtual void micsi(genv::event) override;
    int data() const;
    virtual std::string get_name() const override;
};
#endif // NUMINPUT_HPP
