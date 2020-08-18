#include <iostream>
#include <iomanip>
#include <vector>
#include "Maze2dGenerator.h"
#include "MyMaze2dGenerator.h"
#include "SimpleMaze2dGenerator.h"
#include <Windows.h>
#include "Maze2d.h"
#include <filesystem>
#include <experimental/filesystem>
#include "MazeCompression.h"


namespace fs = std::experimental::filesystem;

static std::vector<std::pair<std::string, Maze2d >> Mymazes;
class Command {
public:
    virtual int run(std::vector<std::string> args) = 0;
private:
};
/*------------------------------------------------------------------------*/
class dirCommand : public Command
{
public:
    dirCommand() {}
    int run(std::vector<std::string> args)
    {
		if (!(args[0] == "dir"))
			return false;
		if (args.size() < 2)
			return false;
		if (args.size() > 2)
			for (int i = args.size() - 1; i > 1; i--)
				args[i - 1] += " " + args[i];

		const fs::path path = args[1];
		
		for (auto& p : fs::directory_iterator(path))
		{
			std::string curr = p.path().string();	// cutting " \<dir_name>\ "
			int idx_to_cut = curr.find_last_of("\\") + 1;
			cout << '\t' << curr.substr(idx_to_cut) << endl;	// printing each file/directory
		}
        return true;
    }
private:
};

/*------------------------------------------------------------------------*/
class generateCommand : public Command
{
public:
    generateCommand()
    {

    }
    int run(std::vector<std::string> args)
    {
        Maze2d Maze;
        Maze2dGenerator* Generator;
        if (args[2] == "random")
            Generator = new simpleMaze2dGenerator();
        else if (args[2] == "dfs")
            Generator = new MyMaze2dGenerator();
        else
            return 1;

        int NumOfRows = std::stoi(args[3]);
        int NumOfCols = std::stoi(args[4]);
        Maze = Generator->generate(NumOfRows, NumOfCols);
        Mymazes.push_back(std::make_pair(args[1], Maze));
        return 1;

    }
private:
};
/*------------------------------------------------------------------------*/
class displayCommand : public Command
{
public:
    displayCommand() {}
    int run(std::vector<std::string> args)
    {

        for (std::vector<std::pair<std::string, Maze2d >>::const_iterator iter = Mymazes.begin(); iter != Mymazes.end(); iter++)
        {
            if (iter->first == args[1])
            {
                std::cout << MAGENTA << "The Maze " << BLUE + args[1] + MAGENTA << " Was Already Generated \n";
                std::cout << "Here is your Maze: \n" << RESET;
                std::cout << iter->second;
                break;
            }
        }
        return 1;
    }
private:
};
/*------------------------------------------------------------------------*/
class saveCommand : public Command
{
    public:
        saveCommand() {}
        int run(std::vector<std::string> args)
        {
            Maze2d maze;
            std::string mazeName = args[1];
            std::string fileName = args[2];
            int answer = 0;

            std::vector<std::pair<std::string, Maze2d >> mazes = Mymazes;
            for (std::vector<std::pair<std::string, Maze2d >>::const_iterator iter = Mymazes.begin(); iter != Mymazes.end(); iter++)
            {
                if (iter->first == mazeName)
                {
                    maze = iter->second;
                    answer = 1;
                }
            }
            if (answer == 0)
            {
                cout << RED << "The Maze " << BLUE << mazeName << " Not exist" << RESET << endl;
                return 1;
            }
            MazeCompression Save;
			std::vector<int> mazeData;
            Save.compressMaze(mazeData);

            return 1;

        }
};
/*------------------------------------------------------------------------*/
class loadCommand : public Command
{
public:
    loadCommand() {}
    int run(std::vector<std::string> args)
    {
        Maze2d Maze;
        std::string mazeName = args[2];
        std::string fileName = args[1];
        int answer = 0;

        std::vector<std::pair<std::string, Maze2d >> mazes = Mymazes;
        for (std::vector<std::pair<std::string, Maze2d >>::const_iterator iter = Mymazes.begin(); iter != Mymazes.end(); iter++)
        {
            if (iter->first == mazeName)
            {
                Maze = iter->second;
                answer = 1;
            }
        }
        if (answer == 0)
        {
            cout << RED << "The Maze " << BLUE << mazeName << RED << " Not exist" << RESET << endl;
            return 1;
        }
		MazeCompression Load;
		vector<int> check;
		Load.readFromFileMaze(mazeName);
		Load.decompressMaze(check);
    }
};
/*------------------------------------------------------------------------*/
class sizeCommand : public Command
{
public:
    sizeCommand() {}
    int run(std::vector<std::string> args)
    {
        Maze2d Maze;
        std::string mazeName = args[2];
        std::string fileName = args[1];
        int answer = 0;

        std::vector<std::pair<std::string, Maze2d >> mazes = Mymazes;
        for (std::vector<std::pair<std::string, Maze2d >>::const_iterator iter = Mymazes.begin(); iter != Mymazes.end(); iter++)
        {
            if (iter->first == mazeName)
            {
                Maze = iter->second;
                answer = 1;
            }
        }
        if (answer == 0)
        {
            cout << RED << "The Maze " << BLUE << mazeName << RED << " Not exist" << RESET << endl;
            return 1;
        }
        else
        {
			std::vector<int> mazeData;
            MazeCompression Size;
            //Size.getExpansionSize(mazeData);
        }
    }
};
/*------------------------------------------------------------------------*/
class fsizeCommand : public Command
{
public:
    fsizeCommand() {}
    int run(std::vector<std::string> args)
    {
        {
            Maze2d Maze;
            std::string mazeName = args[2];
            std::string fileName = args[1];
            int answer = 0;

            std::vector<std::pair<std::string, Maze2d >> mazes = Mymazes;
            for (std::vector<std::pair<std::string, Maze2d >>::const_iterator iter = Mymazes.begin(); iter != Mymazes.end(); iter++)
            {
                if (iter->first == mazeName)
                {
                    Maze = iter->second;
                    answer = 1;
                }
            }
            if (answer == 0)
            {
                cout << RED << "The Maze " << BLUE << mazeName << RED << " Not exist" << RESET << endl;
                return 1;
            }
            MazeCompression Size;
			std::vector<int> mazeDataCompreesed;
			Size.decompressMaze(mazeDataCompreesed);
        }
    }
};
/*------------------------------------------------------------------------*/
class solveCommand : public Command
{
public:
    solveCommand() {}
    int run(std::vector<std::string> args)
    {
        std::cout<<"Fuck all bitches! - sizeCommand - solveCommand"<<std::endl;
        return 1;

    }
private:
};
/*------------------------------------------------------------------------*/
class solutionCommand : public Command
{
public:
    solutionCommand() {}
    int run(std::vector<std::string> args)
    {
        std::cout<<"Fuck all bitches! - solutionCommand"<<std::endl;
        return 1;

    }
private:
};
/*------------------------------------------------------------------------*/
class exitCommand : public Command
{
public:
    exitCommand() {}
    int run(std::vector<std::string> args)
    {
        std::cout<<"BYE BYE"<<std::endl;
        return 0;
    }
private:
};

