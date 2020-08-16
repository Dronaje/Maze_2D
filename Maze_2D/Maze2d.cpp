#pragma once

#include "Maze2d.h"

//Defualt Constructor
Maze2d::Maze2d()
{
	_grid.resize(0);
	_rows = 0;
	_columns = 0;
	_entry = std::pair<int, int>(0, 0);
	_entry = std::pair<int, int>(0, 0);
}

//Copy Constructor
Maze2d::Maze2d(const Maze2d& maze)
{
	_rows = maze._rows;
	_columns = maze._columns;
	_grid = maze._grid;
	_entry = maze._entry;
	_exit = maze._exit;
}


// Main Constructor
Maze2d::Maze2d(int row, int col)
{
	if (row % 2 == 1)
		row++;
	if (col % 2 == 1)
		col++;

	_rows = row;
	_columns = col;


	_entry = std::pair<int, int>(0, 0);
	_exit = std::pair<int, int>(0, 0);


	_grid.resize(row + 1);

	//creating a grid to work with
	for (int i = 0; i < _grid.size(); ++i)
	{
		_grid[i].resize(col + 1);
		for (int j = 0; j < _grid[0].size(); ++j)
			if (i == 0 || i == row || j == 0 || j == _columns)
				_grid[i][j].createFrame();
			else if (i % 2 != 0 && j % 2 != 0)
				_grid[i][j].breakTheWall();
	}

}


void Maze2d::printMaze()
{
	std::cout << CYAN << "\n \n" << std::endl;
	for (int i = 0; i <= _rows; i++)
	{
		std::cout << "\t";
		for (int j = 0; j <= _columns; j++)
			if ((i == _entry.first && j == _entry.second) ||
				(i == _exit.first && j == _exit.second))
				std::cout << GREEN << "->" << CYAN;
			else if (_grid[i][j].isFrame())
			{
				std::cout << RESET;
				_grid[i][j].printCell();
				std::cout << CYAN;
			}
			else
				_grid[i][j].printCell();
		std::cout << std::endl;
	}
	std::cout << RESET << std::endl;
}


Maze2d::~Maze2d()
{
}

void Maze2d::makeRandomEntryAndExit()
{
	int val = rand() % _rows;

	_entry.second = 0;		// entry always at the left side
	for (; val % 2 == 0; val = rand() % _rows); // always get a pair value
	_grid[val][0].breakTheWall();
	_entry.first = val;
	_grid[_entry.first][_entry.second + 1].Visited();


	_exit.second = _columns;	//exit always at the right side
	for (val = rand() % _rows; val % 2 == 0; val = rand() % _rows); // always get a pair value
	_grid[val][_columns].breakTheWall();
	_exit.first = val;
}

std::pair<int, int> Maze2d::getStartPos()
{
	return _entry;
}

Pos2d Maze2d::getStartPosition()
{
	Pos2d p(_entry.first, _entry.second);
	return p;
}

std::pair<int, int> Maze2d::getGoalPos()
{
	return _exit;
}

Pos2d Maze2d::getGoalPosition()
{
	Pos2d exit(_exit.first, _exit.second);
	return exit;
}


int Maze2d::getRows() const
{
	return _rows;
}

int Maze2d::getColumns() const
{
	return _columns;
}



bool Maze2d::isValidMove(Pos2d  pos) const
{
	if ((pos.Getcol() < 0) || (pos.Getcol() > _columns) || (pos.Getrow() < 0) || (pos.Getrow() > _rows))
		return false;
	return true;
}


std::vector<std::pair<int, int>> Maze2d::getWallsSurround(std::pair<int, int> curr)
{
	std::vector<std::pair<int, int>> moves = { {0,0},{0,0},{0,0},{0,0} };

	if (!(_grid[curr.first - 1][curr.second].isVisited()) &&
		!(_grid[curr.first - 1][curr.second].isFrame()) &&
		_grid[curr.first - 1][curr.second].isWall())
	{
		moves[0] = std::pair<int, int>(curr.first - 1, curr.second);
	}


	if (!(_grid[curr.first][curr.second + 1].isVisited()) &&
		!(_grid[curr.first][curr.second + 1].isFrame()) &&
		_grid[curr.first][curr.second + 1].isWall())
	{
		moves[1] = std::pair<int, int>(curr.first, curr.second + 1);
	}


	if (!(_grid[curr.first + 1][curr.second].isVisited()) &&
		!(_grid[curr.first + 1][curr.second].isFrame()) &&
		_grid[curr.first + 1][curr.second].isWall())
	{
		moves[2] = std::pair<int, int>(curr.first + 1, curr.second);
	}


	if (!(_grid[curr.first][curr.second - 1].isVisited()) &&
		!(_grid[curr.first][curr.second - 1].isFrame()) &&
		_grid[curr.first][curr.second - 1].isWall())
	{
		moves[3] = std::pair<int, int>(curr.first, curr.second - 1);
	}

	return moves;
}

vector<Pos2d> Maze2d::getPossiblePlayerMoves(Pos2d pos)
{
	vector<Pos2d> posibleMoves;
	Pos2d up(pos.Getrow() - 1, pos.Getcol());
	Pos2d right(pos.Getrow(), pos.Getcol() + 1);
	Pos2d down(pos.Getrow() + 1, pos.Getcol());
	Pos2d left(pos.Getrow(), pos.Getcol() - 1);

	if (isValidMove(up))
		if( _grid[(int)pos.Getrow() - 1][pos.Getcol()].isEmpty())
			posibleMoves.push_back(up);
	if (isValidMove(right))
		if(_grid[pos.Getrow()][(int)pos.Getcol() + 1].isEmpty())
			posibleMoves.push_back(right);
	if (isValidMove(down))
		if(_grid[(int)pos.Getrow() + 1][pos.Getcol()].isEmpty())
			posibleMoves.push_back(down);
	if (isValidMove(left))
		if(_grid[pos.Getrow()][(int)pos.Getcol() - 1].isEmpty())
		posibleMoves.push_back(left);
	return posibleMoves;
}

vector<pair<int, int>> Maze2d::GetPossibleMoves(pair<int, int> pos, vector<pair<int, int>> walls)
{
	vector<pair<int, int>> move_check = { {-1,0},{0,1},{1,0},{0,-1} };
	vector<pair<int, int>> moves = walls;
	int x, y;
	for (int i = 0; i < 4; i++)
		if (walls[i].first != 0 && walls[i].second != 0) // if there's acually a wall
		{
			x = moves[i].first + move_check[i].first;
			y = moves[i].second + move_check[i].second;
			if (!(_grid[x][y].isVisited()))	// if the cell after this wall is not visited
			{
				moves[i].first = x;
				moves[i].second = y;
			}
			else
			{
				moves[i].first = 0;
				moves[i].second = 0;
			}
		}

	return moves;
}

vector<string> Maze2d::getPossibleMoves(Pos2d p)
{
	vector<Pos2d> moves = getPossiblePlayerMoves(p);
	vector<string> possible;
	for (int i = 0; i < moves.size(); i++)
		possible.push_back(moves[i].getPositionAsString());
	return possible;
}


void Maze2d::makeWall(int row, int column)
{
	_grid[row][column].createWall();
}

void Maze2d::clearWalls()
{
	for (int i = 1; i < _rows; i++)
		for (int j = 1; j < _columns; j++)
			if (_grid[i][j].isWall())
				_grid[i][j].breakTheWall();
}

void Maze2d::blackCell(Pos2d pos)
{
	_grid[pos.Getrow()][pos.Getcol()].Visited();
}

void Maze2d::resetVisited()
{
	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _columns; j++)
			_grid[i][j].resetVisited();
}

void Maze2d::openThePath(int x, int y, pair<int, int> visiting)
{
	_grid[x][y].breakTheWall();
	_grid[x][y].Visited();
	if (visiting != (make_pair(-1, -1)))
		_grid[visiting.first][visiting.second].Visited();
}


std::ostream& operator<<(std::ostream& out, Maze2d maze)
{
	maze.printMaze();
	return out;
}
