#pragma once

#include <utility>
#include <iostream>
#include <vector>
#include "Cell.h"
#include "pos.h"     ///ch
#include <ctime>

//COLORS
#define RESET   "\033[0m"
#define GREEN   "\033[1m\033[32m"
#define MAGENTA "\033[1m\033[35m"    
#define CYAN    "\033[1m\033[36m"
#define BLUE    "\033[1m\033[34m"



using namespace std;


class Maze2d
{

protected:                               // ch
	int _rows;
	int _columns;
	vector<vector<Cell>> _grid;
	pair<int, int> _entry;
	pair<int, int> _exit;

public:
	//constructors
	Maze2d();						// Default Constructor 
	Maze2d(const Maze2d& maze);		// Copy Constructor  
	Maze2d(int row, int col);		// Main Constructor  

	//simple gets
	int getRows()  const;  // ch
	int getColumns()const;  // ch
	Pos getEnter()const;    // ch
	Pos getExit() const;    // ch
	std::pair<int, int> getEntryCell();          // ??
	std::pair<int, int> getExitCell();           // ?? 


	//maze information gets
	vector<pair<int, int>> getWallsSurround(pair<int, int> curr);
	vector<pair<int, int>> getPossibleMoves(vector<pair<int, int>> walls, pair <int, int> pos); //using previous method

	//for Player/solve algorithm
	bool isValidMove(Pos pos)const;                      // ch
	vector<Pos> getPosiblePlayerMoves(Pos pos);          // ch
	void blackCell(Pos pos);                             // ch


public:
	//maze creation: helpers & actions
	void makeWall(int row, int column);
	void makeRandomEntryAndExit();
	void openThePath(int x, int y, pair<int, int> visiting = make_pair(-1, -1)); //(-1,-1) if not moving after opening.
	void clearWalls();



	//print
	void printMaze();
//	void printSolution(std::vector<std::pair<int, int>> solution);
	//destructor
	~Maze2d();
};