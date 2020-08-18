#include "MazeCompression.h"

std::vector<int> MazeCompression::compressMaze(std::vector<int> mazeData)
{
	int counter;
	std::vector<int> compressedData;
	int i;
	for (i = 0; i < 6; i++)
		compressedData.push_back(mazeData[i]);

	while ( i < mazeData.size())
	{
	
		counter = 0;
		while ((i < mazeData.size())&& (mazeData[i] ==0)) //  ??||
		{
			counter++;
			i++;
		}
		if (counter > 0)
		{
			compressedData.push_back(0);
			compressedData.push_back(counter);
		}
		counter = 0;
		while ((i < mazeData.size())&&(mazeData[i] == 1))
		{
			counter++;
			i++;
		
		}
		if (counter > 0)
		{
			compressedData.push_back(1);
			compressedData.push_back(counter);
		}
	}
	return compressedData;
}

std::vector<int> MazeCompression::decompressMaze(std::vector<int> mazeDataCompreesed)
{
	vector<int> mazeData;
	int mazecell;
	int  amount;
	int i,j;
	for (i = 0; i < 6; i++)
		mazeData.push_back(mazeDataCompreesed[i]);


	while (i < mazeDataCompreesed.size())   //the size is always even
	{
		long int a = i + 1;
		  amount = mazeDataCompreesed[(a)];
		  for (j = 0; j < amount; j++)
		  {
			  if (mazeDataCompreesed[i] == 0)
				  mazeData.push_back(0);
			  else 
				  mazeData.push_back(1);
		  }
		   i+=2;
	}
	return mazeData;
}

std::vector<int> MazeCompression::readFromFileMaze(std::string filename)
{
	vector<int> loadedMaze;
	ifstream rf(filename, ios::out | ios::binary);

	if (!rf) 
		throw "Cannot open file!";

	int temp;
	while (!rf.eof())
	{
		rf.read((char*)&temp, sizeof(int));
		loadedMaze.push_back(temp);
	}

	loadedMaze.pop_back();
	rf.close();

	return loadedMaze;
}




void MazeCompression::writeToFile(const std::vector<int>& mazeTosave, std::string filename)
{
	ofstream wf(filename, ios::out | ios::binary);
	if (!wf) {
		throw"Cannot open file!";
	}
	for(int i=0 ; i< mazeTosave.size();i++)
		wf.write((char*)&mazeTosave[i], sizeof(int));    

	wf.close();
	if (!wf.good()) {
		throw "Error occurred at writing time!" ;
	}

}

