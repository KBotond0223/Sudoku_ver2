#ifndef NUMBOX_HPP
#define NUMBOX_HPP

#include "widgets.hpp"

class NumBox : public Widget
{
protected:
    int _number;
    bool _hiba=false;
    bool _locked=false;
    std::string _name="nb";
public:
    NumBox(Application*,int x,int y,double szel, double mag, int number);
    virtual void rajzol() const override;
    virtual void micsi(genv::event) override;
    void set_hiba(bool);
    int get_num() const;
    void set_num(int);
    void lock(bool);
    virtual std::string get_name() const override;
};

#endif // NUMBOX_HPP
