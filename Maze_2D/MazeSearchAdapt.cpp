#include "MazeSearchAdapt.h"

std::vector<Pos2d> MazeSearch2dAdapt::getNextPosibleMoves(Pos2d pos)
{
	return this->getPossiblePlayerMoves(pos);
}

void MazeSearch2dAdapt::removeMarks()
{

	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _columns; j++)
			if (_grid[i][j].isVisited() && !(_grid[i][j].isWall()))
			{
				_grid[i][j].emptyCell();
			}

}