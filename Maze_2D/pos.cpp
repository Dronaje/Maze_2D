#include "Pos.h"

Pos::Pos()
{
	_row = _column = -1;
}

Pos::~Pos()
{
}


int Pos::Getrow() const
{
	return this->_row;
}

int Pos::Getcol() const
{
	return this->_column;
}

void Pos::Setrow(int row)
{
	_row = row;
}

void Pos::Setcol(int col)
{
	_column = col;
}


std::ostream& operator<<(std::ostream& out, const Pos& pos)
{
	out << '(' << pos.Getrow() << ", " << pos.Getcol() << ')';
	return out;
}

