#include "Cell.h"

#define RESET   "\033[0m"
#define GREEN   "\033[1m\033[32m"
#define CYAN    "\033[1m\033[36m"

Cell::Cell()
{
	_is_wall = true;
	_is_frame = false;
	_visited = false;
}

bool Cell::isEmpty() const
{
	return ((!_is_wall) && (!_visited));
}

bool Cell::isWall() const
{
	return _is_wall;
}

bool Cell::isVisited() const
{
	return _visited;
}

bool Cell::isFrame() const
{
	return _is_frame;
}



void Cell::emptyCell()
{
	_is_wall = _is_frame = _visited = false;
}

void Cell::Visited()
{
	_visited = true;
}

void Cell::createWall()
{
	_is_wall = true;
}

void Cell::printCell()
{
	if (_is_wall)
		std::cout << "##";
	else if (_visited)
		std::cout << GREEN << "- " << CYAN;
	else
		std::cout << "  ";
}

void Cell::breakTheWall()
{
	_is_wall = false;
}


void Cell::createFrame()
{
	_is_frame = true;
}


Cell:: ~Cell()
{
}