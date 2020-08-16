#pragma once
#include "Maze2dGenerator.h"

#define Horizonal 0
#define Vertical 1

class SimpleMaze2dGenerator : public Maze2dGenerator
{
private:
	//main recursive:
	void Divide(int row_start,int rows, int col_start, int col_end, int direction, Maze2d& maze);

	// getting pair/odd random number between min-max
	int getExclusiveRandom(const int min, const int max, const int restriction);

	//creating a line of walls
	void createWallsLine(int start, const int& end, const int& seperator, bool direction, Maze2d& maze);
public:
	virtual Maze2d generate(int rows, int col_end);

};