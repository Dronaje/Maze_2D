#include "Pos2d.h"

Pos2d::Pos2d()
{
	_row = _column = -1;
}

Pos2d::~Pos2d()
{
}


int Pos2d::Getrow() const
{
	return this->_row;
}

int Pos2d::Getcol() const
{
	return this->_column;
}

void Pos2d::Setrow(int row)
{
	_row = row;
}

void Pos2d::Setcol(int col)
{
	_column = col;
}


std::ostream& operator<<(std::ostream& out, const Pos2d& pos)
{
	out << '(' << pos.Getrow() << ", " << pos.Getcol() << ')';
	return out;
}

