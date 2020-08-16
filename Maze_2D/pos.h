#pragma once
#include <iostream>

class Pos {

private:
	int _row;
	int _column;
public:
	Pos(int row, int column) : _row(row), _column(column) {}

	Pos();
	~Pos();
	int Getrow() const;
	int Getcol() const;
	void Setrow(int row);
	void Setcol(int col);
	friend std::ostream& operator<<(std::ostream& out, const Pos& pos);
	bool operator==(const Pos& pos)
	{
		return this->_row == pos.Getrow() && this->_column == pos.Getcol();
	}

	bool operator!=(const Pos& pos)
	{
		return !(*this == pos);
	}
};



