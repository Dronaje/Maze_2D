#pragma once
#include <iostream>
#include <vector>    
#include "MyMaze2dGenerator.h"
#include "SimpleMaze2dGenerator.h"
#include "searchAlg.h"                      
#include "MazeSearchAdapt.h"  
#include "pos2d.h"


class Demo {
public:
	Demo() {}
	void run(int rows, int columns)const;
private:
	void print_res(std::vector<Pos2d> res)const;
};