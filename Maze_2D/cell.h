#pragma once

#include <iostream>

class Cell
{
private:
	bool _is_wall;
	bool _is_frame;
	bool _visited; 

public:
	Cell();

	bool isEmpty()const;   
	bool isWall()const ;   
	bool isVisited()const; 
	bool isFrame()const;   

	void emptyCell();      
	void Visited();        
	void createWall();     
	void breakTheWall();   
	void createFrame();          

	void printCell();

	~Cell();
};
