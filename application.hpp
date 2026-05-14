#ifndef APPLICATION_HPP
#define APPLICATION_HPP


#include <vector>
#include "widgets.hpp"

class Application
{
public:
    Application(int,int);
    void betolt(std::string);
    void ellenor(int);
    void megold();
    void event_loop(int, int);
    void register_widget(Widget*);
protected:
    std::vector<Widget*> _widgets;

};

#endif // APPLICATION_HPP
