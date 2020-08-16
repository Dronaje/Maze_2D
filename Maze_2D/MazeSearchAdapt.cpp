#include "MazeSearchAdapt.h"

std::vector<Pos> MazeSearchAdapt::getNextPosibleMoves(Pos pos)
{
	return this->getPosiblePlayerMoves(pos);
}

void MazeSearchAdapt::removeMarks()
{
	
	for (int i = 0; i < _rows ; i++)
		for (int j = 0; j < _columns ; j++)
			if (_grid[i][j].isVisited() && !(_grid[i][j].isWall()))
			{
				_grid[i][j].emptyCell();

			}
				
}

