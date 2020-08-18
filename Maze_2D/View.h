#include <iostream>
#include <string>
#include "Controller.h"
#include <conio.h>

class View 
{
public:
    virtual void start() = 0;
    View(std::ostream& out, std::istream& in) :_out(out), _in(in) {};

protected:
    std::ostream& _out;
    std::istream& _in;
    Controller *con;
};