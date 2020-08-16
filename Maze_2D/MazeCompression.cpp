#include "MazeCompression.h"

std::vector<int> MazeCompression::compressMaze(std::vector<int> mazeData)
{
	int counter;
	std::vector<int> compressedData;
	///'''firs integers
	int i = 0;
	while ( i < mazeData.size())
	{
		counter = 0;
		while (mazeData[i]==0 && i < mazeData.size()) //  ??||
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
		while (mazeData[i] == 1  && i < mazeData.size())
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
