#pragma once
#include <iostream>
#include <fstream>
#include "maze2d.h"
#include <vector>
#include <string>
#include<fstream>

class MazeCompression {
public:
	MazeCompression(){}
	std::vector<int> compressMaze(std::vector<int> mazeData);
	std::vector<int> decompressMaze(std::vector<int> mazeDataCompreesed);
	std::vector<int> readFromFileMaze(std::string filename);
	void writeToFile(const std::vector<int>& mazeTosave , std::string filename);

};
