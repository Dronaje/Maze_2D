#include "TestMazeGenerator.h"
#include <string>


void TestMazeGenerator::testMazeGenerator(Maze2dGenerator& mg)
{

	//prints the time it takes the alogorithm to run
	std::cout << mg.measureAlgorithmTime(10, 10) << std::endl;

	//genrerate another 2d maze
	Maze2d maze = mg.generate(5, 5);
	
	//get maze entrance
	Position p = maze.getStartPosition();

	//print maze entrance
	std::cout << p << std::endl;

	//get all possible moves from p
	std::vector<std::string> vector = maze.getMoves(p);
	
	//std::cout << maze.getGoalPosition() << std::endl;

	//std::cout << maze << std::endl;

	//std::String moves;

	//std::string moves[];
	/*for (const auto& piece : vector) moves += piece;

	for(std::string move : moves)*/

	//for (int i = 0; i < vector.size; i++)
	//{
	//	moves[i]= vector;
	//}

	//for (std::vector<std::string>::const_iterator i = vector.begin(); i != vector.end(); ++i)
	//	std::cout << *i << ' ';
}
