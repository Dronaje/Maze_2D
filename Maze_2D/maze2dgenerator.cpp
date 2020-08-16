#include "Maze2dGenerator.h"

std::string Maze2dGenerator::measureAlgorithmTime(int rows, int columns)
{
	clock_t before = clock();	

	this->generate(rows, columns); //"true" -> testing

	clock_t after = clock();

	return (std::to_string( ((float)after - (float)before) / CLOCKS_PER_SEC));
}