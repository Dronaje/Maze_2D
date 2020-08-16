#pragma once
#include "pos.h"



class hurisicCalc {
public:
	virtual float Calc(Pos curr, Pos end) = 0;
};

class ManhetenUristic :public hurisicCalc {
public:	
	ManhetenUristic() {}
	~ManhetenUristic() {}
	virtual float Calc(Pos curr, Pos end)
	{
		return float(fabs(curr.Getrow()-end.Getrow())+fabs(curr.Getcol()-end.Getcol()));
	}
};


class AirLineUristic :public hurisicCalc {
public:
	AirLineUristic(){}
	~AirLineUristic() {}
	virtual float Calc(Pos curr, Pos end)
	{
		return float(sqrt(pow((end.Getrow()- curr.Getrow()),2)+pow((end.Getcol()- curr.Getcol()),2)));
		
	}
};



