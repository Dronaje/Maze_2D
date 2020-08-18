#include "MazeController.h"


MazeController::MazeController()
{
    commands["dir"] = new dirCommand();
    commands["generate_maze"] = new generateCommand();
    commands["display"] = new displayCommand();
    commands["save_maze"] = new saveCommand();
    commands["load_maze"] = new loadCommand();
    commands["maze_size"] = new sizeCommand();
    commands["file_size"] = new fsizeCommand();
    commands["solve"] = new solveCommand();
    commands["display_solution"] = new solutionCommand();
    commands["exit"] = new exitCommand();
}


void MazeController::checkCommand(const std::string& str)
{
	std::cout << RESET;
	
	std::string buffer;                
	std::stringstream ss(str);     

	std::vector<std::string> command; 

	while (ss >> buffer)
		command.push_back(buffer);

	if (commands[command[0]]) 
	{
		commands[command[0]]->run(command);
		std::cout << std::endl;
		system("pause");
	}
		
	else
		cout << "ERROR";
    
}