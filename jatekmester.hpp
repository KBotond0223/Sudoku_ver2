#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP

#include "application.hpp"
#include "numbox.hpp"
#include <vector>

class JatekMester
{
protected:
    Application* _parent;
public:
    JatekMester(Application*);
    void betolt(std::string,std::vector<NumBox*>);
    void ellenorMester(std::vector<NumBox*>);
    void ellenor(int,int,std::vector<NumBox*>);
    void tisztit(std::vector<NumBox*>);
    void megold();
    void set_num();
};

#endif // JATEKMESTER_HPP
