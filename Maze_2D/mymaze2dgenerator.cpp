#include "Maze2dGenerator.h"
#include <stack>
#include <windows.h>
#include "Maze2d.h"
#include "MyMaze2dGenerator.h"



Maze2d MyMaze2dGenerator::generate(int rows, int columns)
{
	Maze2d maze(rows, columns);

	maze.makeRandomEntryAndExit();


	pair<int, int> Pos2d = maze.getStartPos();
	Pos2d.second++;	//start one Pos2d to the right of the start frame size

	int move_check[] = { (1,0),(0,1),(-1,0),(0,-1) };

	stack <pair <int, int>> stk_moves;
	stk_moves.push(Pos2d);

	vector <pair <int, int>> srnd_walls, possible_moves;
	vector <int> possibilities;

	int path_to_go; // idxs: up = 0, right = 1, down = 2, left = 3
	while (!(stk_moves.empty()))
	{
		Pos2d = stk_moves.top();
		possibilities.clear();

		srnd_walls = maze.getWallsSurround(Pos2d);					// getting the walls around the current Pos2d
		possible_moves = maze.GetPossibleMoves(Pos2d, srnd_walls);	// getting the positions behind those walls
		for (int i = 0; i < 4; i++)
			if (possible_moves[i].first != 0 && possible_moves[i].second != 0) // creating a vector of 
				possibilities.push_back(i);

		if (possibilities.size() != 0)
		{
			path_to_go = possibilities[rand() % possibilities.size()];
			maze.openThePath(srnd_walls[path_to_go].first,srnd_walls[path_to_go].second, possible_moves[path_to_go]);
			Pos2d = possible_moves[path_to_go];
			stk_moves.push(Pos2d);
		}
		else
			stk_moves.pop();
	}
	maze.resetVisited();
	system("cls");
	std::cout << maze << endl;
	return maze;
}

