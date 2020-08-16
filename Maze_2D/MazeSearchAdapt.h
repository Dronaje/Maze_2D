#pragma once
#include <iostream>
#include <vector>
#include "maze2d.h"
#include "pos.h"

class Searchable {
public:
	  virtual std::vector<Pos> getNextPosibleMoves(Pos pos) =0;
	  virtual void MarkPosition(Pos pos) =0 ;
	  virtual void removeMarks() = 0;
};


class MazeSearchAdapt : public Maze2d, public Searchable  {
public:
	MazeSearchAdapt(Maze2d maze) : Maze2d(maze){}
	virtual std::vector<Pos> getNextPosibleMoves(Pos pos);
	virtual void MarkPosition(Pos pos) { this->blackCell(pos); }
	void removeMarks();
};


/// another vertion 
//class MazeSearchAdapt : public Maze2d, public Searchable {
//public:
//	MazeSearchAdapt(  ...  ) {}
//private:
//	
//};
