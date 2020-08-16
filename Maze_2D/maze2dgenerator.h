#pragma once

#include <string>
#include <ctime>

#include "maze2d.h"


class Maze2dGenerator
{
private:


public:
	virtual Maze2d generate(int rows, int columns) = 0;
	virtual std::string measureAlgorithmTime(int rows, int columns);
};

