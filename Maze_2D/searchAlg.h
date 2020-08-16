#pragma once

#include <queue>
#include<iostream>
#include <vector>

#include "pos.h"
#include "Huristic.h"
#include "maze2d.h"
#include "MazeSearchAdapt.h"

class Maze2dSearchAlg {

public:
	virtual  std::vector<std::pair<int, int>>  runSearch(Pos start , Pos end , Searchable * task) = 0 ;

};


class AStar : public Maze2dSearchAlg {

public:
	// Constructor
	AStar(hurisicCalc* huristic): _huristic(huristic) {}
	
	// Methods
	virtual  std::vector<std::pair<int, int>>  runSearch(Pos start, Pos end, Searchable * task);

	// Inner Class A* NODE
	class AStarNode {
	public:
		AStarNode(Pos position, AStarNode* parent,int g,const float &h):
			_position(position), _parent(parent), _h(h), _g(g),_f(g+h){}
		int getG() const { return _g; }
		float getF() const { return _f; }
		AStarNode * getParent() const { return _parent; }
		Pos getPos() const { return _position; }

	private:
		Pos _position;
		AStarNode* _parent;
		float _h;
		int _g;
		float _f;
	};
private:
	hurisicCalc* _huristic;
};

class BFSalg : public Maze2dSearchAlg {
public:
	// Constructor
	BFSalg() {}

	// Methods
	virtual  std::vector<std::pair<int, int>>  runSearch(Pos start, Pos end, Searchable* task);

	// Inner Class BFS NODE
	class BfsNode {
	public:
		BfsNode(Pos position, BfsNode* parent, int distance) :
			_position(position), _parent(parent), _distance(distance) {}
		int getDistance() const { return _distance; }
		BfsNode* getParent() const { return _parent; }
		Pos getPos() const { return _position; }

	private:
		Pos _position;
		BfsNode* _parent;
		int _distance;
	};
};