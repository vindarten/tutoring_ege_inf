// https://inf-ege.sdamgia.ru/problem?id=40740

#include <iostream>
#include <fstream>

int main()
{
	std::fstream myfile(".\\Data\\n40740.txt", std::ios_base::in);
	int curLen = 0, maxLen = 0, countE = 0;
	char x;
	while (myfile >> x)
	{
		if (x == 'A')
		{
			curLen = 0;
			countE = 0;
		}
		else
		{
			curLen++;
			if (x == 'E')
			{
				countE++;
			}
		}
		if (countE >= 3)
		{
			maxLen = std::max(curLen, maxLen);
		}
	}
	std::cout << maxLen << std::endl;
	return 0;
}