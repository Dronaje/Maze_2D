#pragma once
#include <iostream>
#include <vector>    
#include "MyMaze2dGenerator.h"
#include "SimpleMaze2dGenerator.h"
#include "searchAlg.h"                      
#include "MazeSearchAdapt.h"  



class Demo {
public:
    Demo(){}
    void run(int rows, int columns)const;
private:
    void print_res(std::vector<std::pair<int, int>> res)const;
};
 

