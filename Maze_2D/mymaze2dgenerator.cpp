#include "Maze2dGenerator.h"
#include <stack>
#include <windows.h>
#include "Maze2d.h"
#include "MyMaze2dGenerator.h"



Maze2d MyMaze2dGenerator::generate(int rows, int columns)
{
	Maze2d maze(rows, columns);

	maze.makeRandomEntryAndExit();


	pair <int, int> position = maze.getEntryCell();
	position.second++;	//start one position to the right of the start frame size

	int move_check[] = { (1,0),(0,1),(-1,0),(0,-1) };

	stack <pair <int, int>> stk_moves;
	stk_moves.push(position);

	vector <pair <int, int>> srnd_walls, possible_moves;
	vector <int> possibilities;

	int path_to_go; // idxs: up = 0, right = 1, down = 2, left = 3
	while (!(stk_moves.empty()))
	{
		position = stk_moves.top();
		possibilities.clear();

		srnd_walls = maze.getWallsSurround(position);					// getting the walls around the current position
		possible_moves = maze.getPossibleMoves(srnd_walls,position);	// getting the positions behind those walls
		for (int i = 0; i < 4; i++)
			if (possible_moves[i].first != 0 && possible_moves[i].second != 0) // creating a vector of 
				possibilities.push_back(i);

		if (possibilities.size() != 0)
		{
			path_to_go = possibilities[rand() % possibilities.size()];
			maze.openThePath(srnd_walls[path_to_go].first,srnd_walls[path_to_go].second, possible_moves[path_to_go]);
			position = possible_moves[path_to_go];
			stk_moves.push(position);
		}
		else
			stk_moves.pop();
	}
	//maze.printMaze();
	return maze;
}

