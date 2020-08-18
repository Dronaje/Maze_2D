#include "MazeView.h"

void MazeView::start()
{
	vector<string> argv;
	while (running)
	{
		system("cls");
		mainMenu();
		cout << MAGENTA;
		std::getline(std::cin, user_command);
		controller->checkCommand(user_command);
	}
}


void MazeView::mainMenu()
{
	std::cout << programName() << RESET;
	std::cout << "   C O M M A N D S :\n";
	std::cout << "   ________________\n\n\n";
	std::cout << Instructions();
}


std::string MazeView::programName()
{

	return std::string
	(
	"\n"
	+ string(MAGENTA)+"    _______  "+RESET+	 " ________ "+string(CYAN)+"          _____ ______    ________   ________   _______        \n"
	+ string(MAGENTA)+"   /  ___  \\ " RESET + "|\\   ___  \\" + string(CYAN) + "        |\\   _ \\  _   \\ |\\   __  \\ |\\_____  \\ |\\  ___ \\       \n"
	+ string(MAGENTA)+"  /__/|_/  /|" + RESET +  "\\ \\  \\_|\\  \\" + string(CYAN) + "       \\ \\  \\\\\\__\\ \\  \\\\ \\  \\|\\  \\ \\|___/  /|\\ \\   __/|      \n"
	+ string(MAGENTA)+"  |__|//  / / " + string(RESET) + "\\ \\  \\ \\\\  \\" + string(CYAN) + "       \\ \\  \\\\|__| \\  \\\\ \\   __  \\    /  / / \\ \\  \\_|/__    \n"
	+ string(MAGENTA)+"      /  /_/__ " + string(RESET) +"\\ \\  \\_\\\\  \\" + string(CYAN) + "       \\ \\  \\    \\ \\  \\\\ \\  \\ \\  \\  /  /_/__ \\ \\  \\_|\\ \\   \n"
	+ string(MAGENTA)+"     |\\________\\"+string(RESET)+"\\ \\_______|" + string(CYAN) + "        \\ \\__\\    \\ \\__\\\\ \\__\\ \\__\\|\\________\\\\ \\_______\\  \n"
	+ string(MAGENTA)+"      \\|_______| "+string(RESET)+"\\|______/" + string(CYAN) + "          \\|__|     \\|__| \\|__|\\|__| \\|_______| \\|_______|  \n\n\n\n"
	+string(RESET)
	);
}

std::string MazeView::Instructions()
{
	return std::string
	(
		std::string(GREEN) + "   dir" + RESET + " <path>\t\t\t\t"+
		std::string(GREEN) + "   generate_maze" + RESET + " <name> <Alg> <rows> <coloms>\n"+
		std::string(GREEN) + "   display" + RESET " <name>\t\t\t"+
		std::string(GREEN) + "   save_maze" + RESET " <name> <file name>\n"+
		std::string(GREEN) + "   load_maze" + RESET " <file name> <name>\t\t"+
		std::string(GREEN) + "   maze_size" + RESET " <name>\n"+
		std::string(GREEN) + "   file_size" + RESET " <name>\t\t\t"+
		std::string(GREEN) + "   solve" + RESET " <name> <algorithm>\n"+
		std::string(GREEN) + "   display_solution" + RESET " <name>\t\t"+
		std::string(RED) +	 "   exit" + RESET + "\n" + 
		"   -------------------------------------------------------------------------------\n\n   "
	);
}
