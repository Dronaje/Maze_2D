#pragma once
#include <iostream>
#include <vector>
#include "maze2d.h"
#include "pos2d.h"

template <class T>
class Searchable {
public:
	virtual std::vector<T> getNextPosibleMoves(T pos) = 0;
	virtual void MarkPosition(T pos) = 0;
	virtual void removeMarks() = 0;
};


class MazeSearch2dAdapt : public Searchable<Pos2d>, public Maze2d {
public:
	MazeSearch2dAdapt(Maze2d maze) : Maze2d(maze) {}
	virtual std::vector<Pos2d> getNextPosibleMoves(Pos2d pos);
	virtual void MarkPosition(Pos2d pos) { this->blackCell(pos); }
	void removeMarks();
};
