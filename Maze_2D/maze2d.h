#pragma once

#include <utility>
#include <iostream>
#include <vector>
#include "Cell.h"
#include "Pos2d.h"   
#include <ctime>

//COLORS
#define RESET   "\033[0m"
#define GREEN   "\033[1m\033[32m"
#define MAGENTA "\033[1m\033[35m"    
#define CYAN    "\033[1m\033[36m"
#define BLUE    "\033[1m\033[34m"
#define RED     "\033[1m\033[31m"   


using namespace std;


class Maze2d
{

protected:                        
	int _rows;
	int _columns;
	vector<vector<Cell>> _grid;
	pair<int, int> _entry;
	pair<int, int> _exit;

public:
	// Constructors
	Maze2d();							// Default Constructor 
	Maze2d(const Maze2d& maze);			// Copy Constructor  
	Maze2d(int row, int col);			// Main Constructor  
	Maze2d(std::vector<int> mazeData);	// Compressor Constructor

	// Gets
	int getRows()  const;  
	int getColumns()const; 
	std::vector<int>getData()const;

	// Start
	Pos2d getStartPosition();
	std::pair<int, int> getStartPos();

	// Exit
	Pos2d getGoalPosition();
	std::pair<int, int> getGoalPos();   


	//maze information gets
	vector<pair<int, int>> getWallsSurround(pair<int, int> curr);
	vector<pair<int, int>> GetPossibleMoves(pair <int, int> pos, vector<pair<int, int>> walls);
	vector<string> getPossibleMoves(Pos2d p);

	//for Player/solve algorithm
	bool isValidMove(Pos2d pos)const;                  
	vector<Pos2d> getPossiblePlayerMoves(Pos2d pos);      
	void blackCell(Pos2d pos);
	void resetVisited();


public:
	//maze creation: helpers & actions
	void makeWall(int row, int column);
	void makeRandomEntryAndExit();
	void openThePath(int x, int y, pair<int, int> visiting = make_pair(-1, -1)); //(-1,-1) if not moving after opening.
	void clearWalls();
	friend std::ostream& operator<<(std::ostream& out, Maze2d maze);


	//print
	void printMaze();

	
	//destructor
	~Maze2d();
};