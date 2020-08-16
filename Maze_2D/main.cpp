#include <iostream>
#include <vector>  
#include "MyMaze2dGenerator.h"
#include "simpleMaze2dGenerator.h"
#include "searchAlg.h"         
#include "MazeSearchAdapt.h"       
#include "Demo.h"
#include "TestMazeGenerator.h"
//void print_res(std::vector<std::pair<int, int>> res) {
//	for (int i = 0; i < res.size(); i++)
//	{
//		std::cout << res[i].first << "   " << res[i].second;
//		std::cout << std::endl;
//	}
//}

int main()
{
	srand(time(0));

	MyMaze2dGenerator my_gen;
	simpleMaze2dGenerator simple_gen;
	simple_gen.generate(30, 30);
	my_gen.generate(25, 25);
	TestMazeGenerator t;
	TestMazeGenerator t_2;

	t.testMazeGenerator(my_gen);
	t_2.testMazeGenerator(simple_gen);

	Demo demo;
	demo.run(25, 25);


	return 0;
}

