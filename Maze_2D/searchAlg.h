#pragma once

#include <queue>
#include<iostream>
#include <vector>

#include "pos2d.h"
#include "Huristic.h"
#include "maze2d.h"
#include "MazeSearchAdapt.h"


#define MOVE_COST 1

template <class T>
class Maze2dSearchAlg {

public:
	virtual  std::vector<T>  runSearch(T start, T end, Searchable<T>* task) = 0;
	virtual int getAmountOfMoves() = 0;
};


template <class T>
class AStar : public Maze2dSearchAlg<T> {

public:
	// Constructor
	AStar(hurisicCalc<T>* huristic) : _huristic(huristic), amountOfMoves(0) {}

	// Methods
	virtual  std::vector<T> runSearch(T start, T end, Searchable<T>* task);
	int getAmountOfMoves() { return amountOfMoves; }

	// Inner Class A* NODE
	class AStarNode {
	public:
		AStarNode(T position, AStarNode* parent, int g, const float& h) :
			_position(position), _parent(parent), _h(h), _g(g), _f(g + h) {}
		int getG() const { return _g; }
		float getF() const { return _f; }
		AStarNode* getParent() const { return _parent; }
		T getPos() const { return _position; }

	private:
		T _position;
		AStarNode* _parent;
		float _h;
		int _g;
		float _f;
	};
private:
	hurisicCalc<T>* _huristic;
	int amountOfMoves;
};


template <class T>
class BFSalg : public Maze2dSearchAlg<T> {
public:
	// Constructor
	BFSalg<T>() : amountOfMoves(0) {}

	// Methods
	virtual  std::vector<T>  runSearch(T start, T end, Searchable<T>* task);
	int getAmountOfMoves() { return amountOfMoves; }

	// Inner Class BFS NODE
	class BfsNode {
	public:
		BfsNode(T position, BfsNode* parent, int distance) :
			_position(position), _parent(parent), _distance(distance) {}
		int getDistance() const { return _distance; }
		BfsNode* getParent() const { return _parent; }
		T getPos() const { return _position; }

	private:
		T _position;
		BfsNode* _parent;
		int _distance;
	};
private:
	int amountOfMoves;
};




template<class T>
inline std::vector<T> BFSalg<T>::runSearch(T start, T end, Searchable<T>* task)
{
	int counter = 0;

	task->removeMarks();

	std::vector<T> posibleMoves;
	BfsNode* next = nullptr;
	T curr;
	std::vector<T> path;
	BfsNode* root = new BfsNode(start, nullptr, 0);

	std::queue<BfsNode*> q1;
	q1.push(root);
	while (!q1.empty()) {
		counter++;
		next = q1.front();
		q1.pop();
		if (next->getPos() == end)
			break;
		task->MarkPosition(next->getPos());
		root = next;
		posibleMoves = task->getNextPosibleMoves(root->getPos());
		while (!posibleMoves.empty())
		{
			curr = posibleMoves.back();
			BfsNode* currNode = new BfsNode(curr, root, root->getDistance() + MOVE_COST);
			//std::cout << std::endl;
			//std::cout << root->getPos() <<"  "  <<root->getF()<<" " <<curr<<"  "<< posibleDiraction.size();
			//std::cout << std::endl;
			q1.push(currNode);
			posibleMoves.pop_back();

		}

	}
	//task->removeMarks();


	BfsNode* toWrite, * toDelete;
	if (next != nullptr)
	{
		path.push_back(next->getPos());
		toWrite = next->getParent();
		while (toWrite != nullptr)
		{
			path.push_back(toWrite->getPos());
			toDelete = toWrite;
			toWrite = toWrite->getParent();
			delete toDelete;
		}
	}
	else {
		path.push_back(start);
	}
	amountOfMoves = counter;

	return path;
}

template<class T>
inline std::vector<T> AStar<T>::runSearch(T start, T end, Searchable<T>* task)
{
	task->removeMarks();

	std::vector<T> posibleMoves;
	AStarNode* next = nullptr;
	T curr;
	std::vector<T> path;
	AStarNode* root = new AStarNode(start, nullptr, 0, _huristic->Calc(start, end));

	auto nodeCmp = [](AStarNode* left, AStarNode* right) {return (left->getF()) > (right->getF()); };
	std::priority_queue<AStarNode*, std::vector<AStarNode*>, decltype(nodeCmp)> q(nodeCmp);
	q.push(root);
	int counter = 0;
	while (!q.empty()) {
		counter++;
		next = q.top();
		q.pop();
		if (next->getPos() == end)
			break;
		task->MarkPosition(next->getPos());
		root = next;
		posibleMoves = task->getNextPosibleMoves(root->getPos());
		while (!posibleMoves.empty())
		{
			curr = posibleMoves.back();
			AStarNode* currNode = new AStarNode(curr, root, root->getG() + MOVE_COST, _huristic->Calc(curr, end));
			//std::cout << std::endl;
			//std::cout << root->getPos() <<"  "  <<root->getF()<<" " <<curr<<"  "<< posibleDiraction.size();
			//std::cout << std::endl;
			q.push(currNode);
			posibleMoves.pop_back();

		}
		//system("cls");
		//Maze2d* a = dynamic_cast<Maze2d*>(task);
		//a->printMaze();
		//system("cls");
	}
	//task->removeMarks();


	AStarNode* toWrite, * toDelite;
	if (next != nullptr)
	{
		path.push_back(next->getPos());
		toWrite = next->getParent();
		while (toWrite != nullptr)
		{
			path.push_back(toWrite->getPos());
			toDelite = toWrite;
			toWrite = toWrite->getParent();
			delete toDelite;
		}
	}
	else {
		path.push_back(start);
	}
	amountOfMoves = counter;
	return path;
}