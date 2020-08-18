#include <iostream>
#include <vector>  
#include "MyMaze2dGenerator.h"
#include "simpleMaze2dGenerator.h"
#include "searchAlg.h"         
#include "MazeSearchAdapt.h"       
#include "Demo.h"
#include "TestMazeGenerator.h"
#include "MazeCompression.h"
#include "MazeController.h"
#include "MazeView.h"


int main()
{

	MazeView checking = MazeView(cout, cin);
	checking.start();


	//Maze2d maze;
	//srand(time(0));
	//MyMaze2dGenerator my_gen;
	//maze = my_gen.generate(25, 25);
	//std::cout << maze << "1,2" << std::endl;
	//std::vector<int> data;
	//data = maze.getData();
	//Maze2d mazeClon(data);
	//std::cout << mazeClon << 3;
	//MazeCompression compress;
	//std::vector<int> compDataFF;
	//std::vector<int> compData = compress.compressMaze(data);
	//compress.writeToFile(compData, "lala.txt");
	//compDataFF = compress.readFromFileMaze("lala.txt");
	//std::vector<int> DEcompData = compress.decompressMaze(compDataFF);
	//Maze2d mazeClon2(DEcompData);
	//std::cout << mazeClon2 << 4;



	//simpleMaze2dGenerator simple_gen;
	//simple_gen.generate(30, 30);
	//my_gen.generate(25, 25);
	//TestMazeGenerator t;
	//TestMazeGenerator t_2;

	//t.testMazeGenerator(my_gen);
	//t_2.testMazeGenerator(simple_gen);

	//Demo demo;
	//demo.run(11, 11);




	return 0;
}