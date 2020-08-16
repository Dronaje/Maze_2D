#pragma once
#include "Pos2d.h"


template<class T>
class hurisicCalc {
public:
	virtual float Calc(T curr, T end) = 0;
};


class Manheten2dUristic :public hurisicCalc<Pos2d> {
public:
	Manheten2dUristic() {}
	~Manheten2dUristic() {}
	virtual float Calc(Pos2d curr, Pos2d end)
	{
		return float(fabs(curr.Getrow() - end.Getrow()) + fabs(curr.Getcol() - end.Getcol()));
	}
};


class AirLine2dHuristic :public hurisicCalc<Pos2d> {
public:
	AirLine2dHuristic() {}
	~AirLine2dHuristic() {}
	virtual float Calc(Pos2d curr, Pos2d end)
	{
		return float(sqrt(pow((end.Getrow() - curr.Getrow()), 2) + pow((end.Getcol() - curr.Getcol()), 2)));

	}
};