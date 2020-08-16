#include "Maze2dGenerator.h"
#include <stack>
#include <windows.h>
#include "Maze2d.h"
#include "simpleMaze2dGenerator.h"

Maze2d simpleMaze2dGenerator::generate(int rows, int columns)
{
	
	Maze2d maze(rows, columns);

	maze.makeRandomEntryAndExit();
	maze.clearWalls();

	int col = maze.getColumns();
	int row = maze.getRows();

	if (row > col) // if there are more rows than columns 
		Divide(0, row, 0, col, Horizonal, maze); //start by splitting horizonally
	else
		Divide(0, row, 0, col, Vertical, maze); //start by splitting vertically

	maze.resetVisited();
	system("cls");
	std::cout << maze << endl;
	return maze;
}


void simpleMaze2dGenerator::Divide(int row_start, int row_end, int col_start, int col_end, int direction, Maze2d& maze)
{
	if (row_end - row_start <= 2 || col_end - col_start <= 2)
		return;
	int wall_to_break;

	if (direction == Vertical)
	{
		// creating a vertical line of walls at a random Pos2d 
		int seperator_col = getExclusiveRandom(col_start, col_end, 0); // get paired random int from col_start to col_end
		createWallsLine(row_start, row_end, seperator_col, Vertical, maze);

		// breaking a random wall in the previous random line
		wall_to_break = getExclusiveRandom(row_start, row_end, 1);
		maze.openThePath(wall_to_break, seperator_col);

		//Recursively 
 		Divide(row_start, row_end, col_start, seperator_col, Horizonal, maze);
		Divide(row_start, row_end, seperator_col, col_end, Horizonal, maze);

	}

	else // Horizonal Dividing ::
	{
		// creating an Horizonal line of walls at a random Pos2d 
		int seperator_row = getExclusiveRandom(row_start, row_end, 0);
		createWallsLine(col_start, col_end, seperator_row, Horizonal, maze);

		// breaking a random wall
		wall_to_break = getExclusiveRandom(col_start, col_end, 1);
		maze.openThePath(seperator_row, wall_to_break);

		//Recursively 
		Divide(row_start, seperator_row, col_start, col_end, Vertical, maze);
		Divide(seperator_row, row_end , col_start, col_end, Vertical, maze);

	}
	return;
}


int simpleMaze2dGenerator::getExclusiveRandom(const int min, const int max, const int restriction)
{
	//restriction = 0 : PAIR,	restriction = 1: ODD

	int val = rand() % max;
	while (val % 2 != restriction || val <= min)
		val = rand() % max;
	return val;
}


void simpleMaze2dGenerator::createWallsLine(int itr, const int& end, const int& seperator, bool direction, Maze2d& maze)
{
	while (itr++ < end)
		if (direction == Vertical)
			maze.makeWall(itr, seperator);
		else
			maze.makeWall(seperator, itr);
}
