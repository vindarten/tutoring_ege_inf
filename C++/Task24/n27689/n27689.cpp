// https://inf-ege.sdamgia.ru/problem?id=27689

#include <iostream>
#include <fstream>

int main()
{
	std::fstream myfile(".\\Data\\24_demo.txt", std::ios_base::in);
	char last = 0, next = 0;
	bool f = false;
	int len = 0, maxLen = 0;
	myfile >> last;
	while (myfile >> next)
	{
		if (f == true)
		{
			if (last == 'X' && next == 'Y' ||
				last == 'Y' && next == 'Z' ||
				last == 'Z' && next == 'X')
			{
				len++;
				maxLen = std::max(len, maxLen);
			}
			else
			{
				f = false;
				len = 0;
			}
		}
		else // if (f == false)
		{
			if (next == 'X')
			{
				f = true;
				len = 1;
			}
		}
		last = next;
	}
	std::cout << maxLen << std::endl;
	return 0;
}