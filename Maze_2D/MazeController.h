#pragma once
#include "Controller.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

class MazeController : public Controller
{

public:
	MazeController();
	
	virtual void checkCommand(const std::string& str);
	
	~MazeController() {};


private:
	Maze2d* _myMaze;
};


