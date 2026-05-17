#ifndef APPLICATION_HPP
#define APPLICATION_HPP


#include <vector>
#include "widgets.hpp"

class JatekMester;

class Application
{
public:
    Application(int, int);
    void event_loop(int,int);
    virtual void action(std::string,genv::event,int)=0;
    virtual void register_widget(Widget*);
    virtual void register_jm(JatekMester*);
    virtual void win_msg() const = 0;
    void clear(int,int);
protected:
    std::vector<Widget*> _widgets;
    JatekMester *_jm;
};

#endif // APPLICATION_HPP
