// https://inf-ege.sdamgia.ru/problem?id=27421

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
			if (last != next)
			{
				len++;
				maxLen = std::max(len, maxLen);
			}
			else // last == next
			{
				f = false;
				len = 0;
			}
		}
		else // if (f == false)
		{
			if (last != next)
			{
				f = true;
				len = 2;
			}
		}
		last = next;
	}
	std::cout << maxLen << std::endl;
	return 0;
}