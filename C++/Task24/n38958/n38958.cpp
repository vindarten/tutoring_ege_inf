// https://inf-ege.sdamgia.ru/problem?id=38958

#include <iostream>
#include <fstream>

int main()
{
	std::fstream myFile(".\\Data\\n38958.txt", std::ios_base::in);
	int curLen = 0, lenFromLastA = 0, maxLen = 0;
	char x;
	while (myFile >> x)
	{
		if (x == 'A')
		{
			curLen = lenFromLastA + 1;
			lenFromLastA = 0;
		}
		else
		{
			curLen++;
			lenFromLastA++;
		}
		maxLen = std::max(curLen, maxLen);
	}
	std::cout << maxLen << std::endl;
	return 0;
}