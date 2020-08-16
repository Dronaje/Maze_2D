#include "Demo.h"

#include <iomanip>

void Demo::print_res(std::vector<std::pair<int, int>> res)const
{
	//cout << fixed << setprecision(6) << setfill(' ');

	for (unsigned int i = 0; i < res.size(); i++)
	{
		
		std::cout  << fixed  << setw(2) << setfill(' ') << "("<<res[i].first << "," << fixed  << setw(2) << setfill(' ') << res[i].second<<")";
		if(i%12==0)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Demo::run(int rows, int columns)const
{
	Maze2d m1;
	MyMaze2dGenerator maze;
	m1 = maze.generate(rows, columns);
	m1.printMaze();
	MazeSearchAdapt* mazeToSearch = new MazeSearchAdapt(m1);
	ManhetenUristic* mh = new ManhetenUristic;
	AirLineUristic* alh = new AirLineUristic;
	AStar a1(mh);
	AStar a2(alh);
	BFSalg b1;
	std::vector<std::pair<int, int>> res3 = b1.runSearch(m1.getEnter(), m1.getExit(), mazeToSearch);
	std::vector<std::pair<int, int>> res1 = a1.runSearch(m1.getEnter(), m1.getExit(), mazeToSearch);
	std::vector<std::pair<int, int>> res2 = a2.runSearch(m1.getEnter(), m1.getExit(), mazeToSearch);
	std::cout << std::endl;

	print_res(res1);
	mazeToSearch->printMaze();
	std::cout << std::endl;

	print_res(res2);
	mazeToSearch->printMaze();
	std::cout << std::endl;

	print_res(res3);
	mazeToSearch->printMaze();
	std::cout << std::endl;

	std::cout <<"TOTAL AMOUNT OF MOVES :   BFS - "<<res3.size()<<"       Astar(Manhattan) - "<< res1.size()<<"       Astar(airLine) - "<< res2.size()<< std::endl;

	//SimpleMaze2dGenerator rand_maze;
	//rand_maze.generate(30, 30);

	//maze.generate(30, 30);
}






 


