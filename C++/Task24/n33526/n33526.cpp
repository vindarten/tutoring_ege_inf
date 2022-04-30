// https://inf-ege.sdamgia.ru/problem?id=33526

#include <iostream>
#include <fstream>

int main()
{
	std::fstream myFile(".\\Data\\24.txt", std::ios_base::in);
	char c1 = 0, c2 = 0, c3 = 0;
	myFile >> c1 >> c2;
	const int n = 'Z' - 'A' + 1;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
	while (myFile >> c3)
	{
		if (c1 == c3)
		{
			a[c2 - 'A']++;
		}
		c1 = c2;
		c2 = c3;
	}
	int max = 0, max_i = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			max_i = i;
		}
	}
	char max_ch = 'A' + max_i;
	std::cout << max_ch << std::endl;
	return 0;
}