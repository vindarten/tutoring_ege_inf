// https://inf-ege.sdamgia.ru/problem?id=27686

#include <iostream>
#include <fstream>

int main()
{
	std::fstream myfile(".\\Data\\24_demo.txt", std::ios_base::in);
	char c = 0;
	bool f = false;
	int len = 0, maxLen = 0;
	while (myfile >> c)
	{
		if (f == true)
		{
			if (c == 'X')
			{
				len++;
				maxLen = std::max(len, maxLen);
			}
			else // if (c != 'X')
			{
				f = false;
				len = 0;
			}
		}
		else // if (f == false)
		{
			if (c == 'X')
			{
				f = true;
				len = 1;
			}
		}
	}
	std::cout << maxLen << std::endl;
	return 0;
}