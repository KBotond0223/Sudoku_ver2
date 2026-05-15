#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
class Application;

class Widget {
protected:
    int _x, _y, _szel, _mag;
    Application * _parent;
    std::string _name;
public:
    Widget(Application*,int x, int y, int sx, int sy);
    virtual bool benne_van(int mouse_x, int mouse_y);
    virtual void rajzol() const = 0;
    virtual void micsi(genv::event ev) = 0;
    virtual std::string get_name() const=0;
};

#endif // WIDGETS_HPP_INCLUDED
