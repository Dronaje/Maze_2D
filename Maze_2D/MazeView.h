#include <iostream>
#include <string>
#include <conio.h>
#include <io.h>
#include <fcntl.h>

#include "View.h"
#include "MazeController.h"

#define RESET   "\033[0m"
#define RED     "\033[1m\033[31m"   
#define GREEN   "\033[1m\033[32m"

class MazeView: public View
{
public:
    void mainMenu();
    std::string programName();
	MazeView(std::ostream& out, std::istream& in) :View(out, in)
	{
		running = true;
		controller = new MazeController();
		user_command = "";
	};


	void start();	// Main Menu Start
	std::string Instructions();

	~MazeView(){delete controller;}

private:
    bool running;
	MazeController* controller;
	std::string user_command;
};



