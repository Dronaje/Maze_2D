#pragma once

#include "Maze2dGenerator.h"

class MyMaze2dGenerator : public Maze2dGenerator
{
public:
	MyMaze2dGenerator() {};
	virtual Maze2d generate(int rows, int cols);
};