// https://inf-ege.sdamgia.ru/problem?id=29672

#include <iostream>
#include <fstream>

int main()
{
	std::fstream myFile(".\\Data\\inf_22_10_20_24.txt", std::ios_base::in);
	int countE = 0, countA = 0, countStr = 0;
	char c = 0;
	while (myFile.get(c))
	{
		if (c == 'E')
		{
			countE++;
		}
		else if (c == 'A')
		{
			countA++;
		}
		else if (c == '\n')
		{
			if (countE > countA)
			{
				countStr++;
			}
			countE = countA = 0;
		}
	}
	if (countE > countA)
	{
		countStr++;
	}
	std::cout << countStr << std::endl;
	return 0;
}