#include <iostream>
#include <vector>     // ch
#include "MyMaze2dGenerator.h"
#include "SimpleMaze2dGenerator.h"
#include "searchAlg.h"                 // ch      
#include "MazeSearchAdapt.h"        // ch
#include "Demo.h"

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

	Demo demo;
	demo.run(25, 25);




	//MazeSearchAdapt* mazeToSearch = new  MazeSearchAdapt(m1);
	//ManhetenUristic* mh = new ManhetenUristic;
	//AirLineUristic* alh = new AirLineUristic;
	//AStar a1(mh);
	//AStar a2(alh);
	//BFSalg b1;
	//std::vector<std::pair<int, int>> res1 = a1.runSearch(m1.getEnter(), m1.getExit(), mazeToSearch);
	//std::vector<std::pair<int, int>> res2 = a2.runSearch(m1.getEnter(), m1.getExit(), mazeToSearch);
	//std::vector<std::pair<int, int>> res3 = b1.runSearch(m1.getEnter(), m1.getExit(), mazeToSearch);
	//std::cout << std::endl;
	//print_res(res1);
	//std::cout << std::endl;
	//print_res(res2);
	//std::cout << std::endl;
	//print_res(res3);

	//cout << endl << "\t\t" << maze.measureAlgorithmTime(25,32) << endl;

	return 0;
}

