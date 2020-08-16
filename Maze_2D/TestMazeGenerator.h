#pragma once

#include <string>

#include "Maze2dGenerator.h"
#include "MyMaze2dGenerator.h"



class TestMazeGenerator
{
public:
	TestMazeGenerator() {}

	void testMazeGenerator(Maze2dGenerator& mg)
	{

		//prints the time it takes the alogorithm to run
		cout << mg.measureAlgorithmTime(10, 10) << std::endl;

		//genrerate another 2d maze
		Maze2d maze = mg.generate(10, 10);

		//get maze entrance
		Pos2d p = maze.getStartPosition();

		//print maze entrance
		cout << p << std::endl;

		//get all possible moves from a Pos2d
		vector<string> moves = maze.getPossibleMoves(p);

		for (string move : moves)
			cout << move << endl;

		cout << maze.getGoalPosition() << endl;

		cout << maze;
	}
};