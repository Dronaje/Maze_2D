#pragma once
#include "Maze2d.h"
#include <map>
#include "Command.h"
#include <vector>


class Controller 
{
public:
    Controller();
    ~Controller();
    virtual void checkCommand(const std::string& str) = 0 ;

protected:
    std::map<std::string, Command *> commands;
    std::vector<std::string> _args;
};